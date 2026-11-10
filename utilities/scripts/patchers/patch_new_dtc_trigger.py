#!/usr/bin/env python3
"""EXAMPLE: patch_new_dtc_trigger.py — author a new DTC trigger into a copy of the stock ROM.

Example patcher demonstrating the "how to author a DTC" map (see
docs/investigations/60E15120_N3J1E/dtc_authoring_report.md). It adds ONE new DTC:

  slot 0x79 (free in stock: code 0xffff, enable#1/#2 = 0) with fault arg 0x83
  (already pre-wired in ROM: id2slot[0x83] = 0x79 at 0x7df42+2*0x83, related
  record low byte 0x83 at 0x7e06c+4*0x79, and arg 0x83 is already in the E2RAM
  persistence lists 0x242ae/0x23f4e).

Patch contents (60E15120_N3J1E addresses):
  1. code table  0x7e5f2 (= 0x7e560 + 2*0x79) <- new OBD code (default 0x1F01 = P1F01,
     a manufacturer-specific code — the right class for a custom DTC)
  2. enable#1    0x7e6f1 (= 0x7e678 + 0x79) <- 1   (MIL + aging gate)
  3. enable#2    0x7e71d (= 0x7e704 + 0x79) <- 1   (Mode 03 / freeze-frame visibility)
  4. hook: the dtc_fault_service_batch 0x118d0 (task[13], periodic) tail-calls its
     last pool entry (pool word 0x11ad8 = 0x3809a via `jmp @r2` at 0x1196a). That
     pool word is repointed to a code cave in a verified-free flash run; the cave
     calls the stock 0x3809a first (behavior preserved), then evaluates the trigger
     and calls the stock set-fault thunk 0x5fd38(0x83, 1) when firing.
  Trigger (example condition): engine speed 0xffffb548 (float rpm) > --threshold
  (default 8000 rpm). The cave is ~40 words + 4 pool words.

  Everything else the slot needs is already stock-correct for free slots:
  enable#3 0x20 (reportable), type 0, conf mask 0, monitor-source mask 0xff.

Safety (AGENTS.md): stock .bin read-only, input SHA-256 asserted unchanged; the
patch refuses to emit unless every target byte holds its expected stock/free value;
output asserted to differ only at the pool word, the three table bytes and the
cave. Reference ROM pinned by SHA-256; other ROMs SKIP with a reason. Emulator-
pre-validated (tests/test_dtc_trigger_patcher.py boots the patched ROM and fires
the trigger via harness.call). Static + emulator only — NOT hardware-tested; no
vehicle flashing without bench validation (AGENTS.md rule 10).

Usage:
  python3 patch_new_dtc_trigger.py <rom.bin> [--code 0x1F01] [--threshold 8000] [--out patched/]
  python3 patch_new_dtc_trigger.py --dry-run <rom.bin>
"""
import argparse, hashlib, json, struct, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from patch_limiter_behavior import (Asm, movi, mov_rr, fmov_s, fcmp_gt,  # noqa: E402
                                    f32, NOP, RTS)

JSR_R0 = 0x400B   # jsr @r0 (verified: firmware_disassembly.asm "400b jsr @r0")
STS_PR, LDS_PR = 0x4F22, 0x4F26  # sts.l pr,@-r15 / lds.l @r15+,pr (everywhere in ROM)

REPO = Path(__file__).resolve().parents[3]
REF_ROM = REPO / 'submodules' / 'Mazda_RX8_PCM_ReverseEngineering' / 'Stock_ROMs' / '60E15120_N3J1E.bin'
REF_SHA256 = 'a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1'

BATCH_FUNC, BATCH_BODY = 0x118d0, 158          # dtc_fault_service_batch (task[13] periodic batch)
BATCH_POOL_WORD = 0x11ad8                      # pool word holding LAST_CALL (tail `jmp @r2`)
BATCH_TAIL_CALL = 0x11968                      # mov.l @(pool,pc),r2 ; jmp @r2 at 0x1196a
LAST_CALL = 0x3809a

SLOT, ARG = 0x79, 0x83                         # pre-wired free slot / fault arg
CODE_TBL, EN1, EN2 = 0x7e560, 0x7e678, 0x7e704
ID2SLOT, RELATED = 0x7df42, 0x7e06c
SET_FAULT = 0x5fd38                            # set-fault thunk (71 stock callers)
RPM_RAM = 0xffffb548                           # engine_speed_rpm (float32)

DEFAULT_CODE = 0x1F01                          # P1F01 manufacturer-specific
DEFAULT_THRESHOLD = 8000.0


def find_free_run(rom, need, start=0x6c000):
    i, best = start, None
    while i < len(rom) - need:
        if rom[i] == 0xff:
            j = i
            while j < len(rom) and rom[j] == 0xff:
                j += 1
            if j - i >= need and (best is None or j - i > best[1] - best[0]):
                best = (i, j)
            i = j
        else:
            i += 1
    if best is None:
        raise SystemExit('no free flash run big enough')
    return best[0] + (-best[0]) % 4


def build_cave(cave, orig, set_fault, threshold):
    """Cave = wrapper called instead of the batch's last entry: run stock, then trigger.

    Only volatile registers (r0/r1/r4-r6, fr0/fr1) are used, and every opcode is
    present in the emulator's corpus-derived OPMNEM table (verified in tests), so
    the patched ROM also runs in the emulator. The fault arg is loaded from a pool
    word because `mov #0x83,r4` (0xe483) is not in the 60E15120 opcode corpus.
    P_THR is a forward label pointing at the threshold float stored as data after
    the pool (a pool word must hold an address, not the float itself).
    """
    def build(thr_addr):
        a = Asm(cave)
        a.emit(STS_PR)                                       # save caller's PR across our jsr's
        a.pc_word(0, 'P_ORIG'); a.emit(JSR_R0); a.emit(NOP)  # call stock last-batch fn
        a.pc_word(0, 'P_RPM'); a.emit(fmov_s(0, 0))          # fr0 = rpm (0xffffb548)
        a.pc_word(1, 'P_THR'); a.emit(fmov_s(1, 1))          # fr1 = *P_THR (threshold)
        a.emit(fcmp_gt(1, 0))                                # T = fr0 > fr1 (rpm > threshold)
        a.emit_br('bf', 'SKIP'); a.emit(NOP)                 # below threshold: nothing
        a.pc_word(0, 'P_ARG'); a.emit(mov_rr(0, 4))          # r4 = 0x83 (0xd406 not in corpus)
        a.emit(movi(1, 5)); a.emit(movi(0, 6))               # r5 = 1 (mode), r6 = 0
        a.pc_word(0, 'P_SET'); a.emit(JSR_R0); a.emit(NOP)   # 0x5fd38(0x83, 1, 0)
        a.label('SKIP')
        a.emit(LDS_PR); a.emit(RTS)
        a.pool('P_ORIG', orig)
        a.pool('P_SET', set_fault)
        a.pool('P_RPM', RPM_RAM)
        a.pool('P_ARG', ARG)
        a.pool('P_THR', thr_addr)
        while a.here() % 4:
            a.emit(NOP)
        a.emit(f32(threshold) >> 16)                         # threshold float as trailing data
        a.emit(f32(threshold) & 0xffff)
        return a
    n = len(build(0).words) * 2                              # pass 1: measure (length is stable)
    a = build(cave + n - 4)                                  # threshold float = last 4 bytes
    return a.finish(), len(a.words) * 2


def patch_rom(in_path, code=DEFAULT_CODE, threshold=DEFAULT_THRESHOLD, out_dir=None, dry_run=False):
    in_path = Path(in_path)
    data = in_path.read_bytes()
    sha_in = hashlib.sha256(data).hexdigest()
    ref = REF_ROM.read_bytes()
    if hashlib.sha256(ref).hexdigest() != REF_SHA256:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'reference ROM hash mismatch'}
    if sha_in == REF_SHA256:
        pass  # patching the reference ROM itself is the intended use
    # locate the batch by exact body match
    pat = ref[BATCH_FUNC:BATCH_FUNC + BATCH_BODY]
    hits, pos = [], data.find(pat)
    while pos >= 0:
        hits.append(pos)
        pos = data.find(pat, pos + 1)
    if len(hits) != 1:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': f'batch body matches: {len(hits)} (reference ROM only)'}
    base = hits[0]
    delta = base - BATCH_FUNC
    pool_word = base + (BATCH_POOL_WORD - BATCH_FUNC)
    if struct.unpack('>I', data[pool_word:pool_word + 4])[0] != LAST_CALL + delta:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'batch pool word mismatch'}
    # verify the tail-call pattern (mov.l @(pool,pc),r2 ; jmp @r2)
    tail = base + (BATCH_TAIL_CALL - BATCH_FUNC)
    w_movl = struct.unpack('>H', data[tail:tail + 2])[0]
    disp = (pool_word - ((tail + 4) & ~3)) // 4
    if w_movl != (0xd200 | disp) or struct.unpack('>H', data[tail + 2:tail + 4])[0] != 0x422b:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'tail jmp pattern mismatch'}
    # table anchors: arg->slot wiring and related record must be the stock pre-wiring
    if struct.unpack('>H', data[ID2SLOT + 2 * ARG:ID2SLOT + 2 * ARG + 2])[0] != SLOT:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'id2slot[0x83] != 0x79'}
    if data[RELATED + 4 * SLOT + 3] != ARG:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'related record arg byte mismatch'}
    # expected stock values at the patch targets (refuse to overwrite anything else)
    code_addr = CODE_TBL + 2 * SLOT
    en1_addr, en2_addr = EN1 + SLOT, EN2 + SLOT
    expect = {code_addr: struct.pack('>H', 0xffff), en1_addr: b'\x00', en2_addr: b'\x00'}
    for a, blob in expect.items():
        if data[a:a + len(blob)] != blob:
            return {'rom': in_path.name, 'status': 'SKIP', 'reason': f'unexpected stock bytes at {a:#x}'}
    cave = find_free_run(data, 0x80)
    cave_bytes, cave_len = build_cave(cave, LAST_CALL + delta, SET_FAULT + delta, threshold)
    if any(b != 0xff for b in data[cave:cave + cave_len]):
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'cave area not free'}
    out = bytearray(data)
    old = {}
    def put(a, blob):
        old[f'{a:#x}'] = data[a:a + len(blob)].hex()
        out[a:a + len(blob)] = blob
    put(pool_word, struct.pack('>I', cave))
    put(code_addr, struct.pack('>H', code & 0xffff))
    put(en1_addr, b'\x01')
    put(en2_addr, b'\x01')
    put(cave, cave_bytes)
    # checks
    assert hashlib.sha256(in_path.read_bytes()).hexdigest() == sha_in, 'input modified!'
    allowed = set()
    for a, blob in old.items():
        allowed |= set(range(int(a, 16), int(a, 16) + len(blob) // 2))
    diff = [i for i in range(len(data)) if data[i] != out[i]]
    assert all(i in allowed for i in diff), 'diff outside patched spans'
    result = {'rom': in_path.name, 'status': 'OK', 'input_sha256': sha_in,
              'slot': SLOT, 'arg': ARG, 'code': f'{code & 0xffff:04x}',
              'threshold_rpm': threshold,
              'hook_pool_word': f'{pool_word:#x}', 'hooked_function': f'{LAST_CALL + delta:#x}',
              'table_patches': {'code': f'{code_addr:#x}', 'enable1': f'{en1_addr:#x}', 'enable2': f'{en2_addr:#x}'},
              'cave': f'{cave:#x}', 'cave_len': cave_len, 'bytes_changed': len(diff), 'old_words': old}
    if not dry_run:
        out_dir = Path(out_dir) if out_dir else in_path.parent
        out_dir.mkdir(parents=True, exist_ok=True)
        out_path = out_dir / f'{in_path.stem}_newdtc_{code & 0xffff:04x}.bin'
        out_path.write_bytes(bytes(out))
        result['output'] = str(out_path)
        result['output_sha256'] = hashlib.sha256(bytes(out)).hexdigest()
        out_path.with_suffix('.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('inputs', nargs='+')
    ap.add_argument('--code', default=f'{DEFAULT_CODE:#x}', help='new OBD code as BE u16 (default 0x1F01 = P1F01)')
    ap.add_argument('--threshold', type=float, default=DEFAULT_THRESHOLD, help='trigger rpm threshold')
    ap.add_argument('--out', default=None)
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    code = int(str(args.code), 0)
    files = []
    for i in args.inputs:
        p = Path(i)
        files.extend(sorted(p.glob('*.bin')) if p.is_dir() else [p])
    results = [patch_rom(f, code, args.threshold, args.out, args.dry_run) for f in files]
    for r in results:
        print(json.dumps({k: r[k] for k in ('rom', 'status', 'reason', 'output', 'cave', 'code') if k in r}))
    sys.exit(1 if any(r['status'] != 'OK' for r in results) else 0)


if __name__ == '__main__':
    main()
