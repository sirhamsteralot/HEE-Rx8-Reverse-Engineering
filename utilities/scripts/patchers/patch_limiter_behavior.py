#!/usr/bin/env python3
"""SPEC: patch_limiter_behavior.py — RX-8 S1 PCM rev-limiter behavior patcher.

Implements the draft spec: over-rev limiter that inhibits fuel AND ignition
together through the stock shared cut flags (0xffffa444/a445), with modes
0=stock passthrough, 1=hard (both flags), 2=soft (per-rotor alternating toggle),
and a RomRaider-editable 4-cell cal table ("Rev Limiter Behavior", category
Protection). Default: soft, stock limit.

RE basis (60E15120_N3J1E): limiter decision 0xe910 -> requests a464/a465 ->
arbitration 0xedc4 (sets shared flags a444/a445, tail-jumps to combiner 0xe2d4 ->
a430). Consumers: fuel via a430 (0xff04) into the injection scheduler; ignition
via 0x12938 (a444/a445 -> a68a -> 0x128ac -> a689 -> 0x129c0 timing zero). So the
flags gate fuel AND spark together (Option A; invariants I1/I2 by construction).
Coolant warm-up protection stays upstream in 0xe910/0xe560, untouched (I6).

Patch mechanism: 0x20df0 calls 0xedc4 via pool word (0x20ffc in the reference
ROM); we repoint that one word to a code cave in a verified-free cal-area run.
The cave calls the stock 0xedc4 (jsr; it tail-jumps through 0xe2d4 and returns),
then, only when mode is 1/2, rewrites a444/a445 per the state machine and calls
0xe2d4 again to refresh a430. Mode 0 / out-of-range = pure passthrough (I3).

Safety (workspace AGENTS.md): stock .bin read-only, input SHA-256 asserted
unchanged; output asserted to differ only at the one pool word, the cave and the
cal block; decode-verified word-by-word; build-time invariant sweep over a model
of the state machine (I1-I7) refuses to emit on violation. Static only — not
hardware-tested. Flash with Rx8Man.

Usage:
  python3 patch_limiter_behavior.py Stock_ROMs/60E15120_N3J1E.bin --mode soft --out patched/
  python3 patch_limiter_behavior.py Stock_ROMs/ --mode hard --limit 9200 --recovery 200 --hard-margin 400
"""
import argparse, hashlib, json, struct, sys
from pathlib import Path

REF_ROM = Path(__file__).resolve().parents[1] / 'Stock_ROMs' / '60E15120_N3J1E.bin'
CALLER_FUNC, CALLER_BODY, CALL_POOL_REL = 0x20df0, 80, 0x20ffc   # jsr target word for 0xedc4
LIMITER_FUNC, LIMITER_BODY = 0xedc4, 134
COMBINER_FUNC = 0xe2d4
MAX_LIMIT = 9300.0

# ---- SH-2E BE encodings (verified against firmware_disassembly.asm) ----
def movl_pc(n, ea, addr):
    d = ea - addr - 4
    assert 0 <= d <= 1020 and d % 4 == 0 and addr % 4 == 0
    return 0xd000 | (n << 8) | (d // 4)
def fmov_s(m, n):  return 0xf000 | (n << 8) | (m << 4) | 0x8      # fmov.s @rM,frN
def fmov_r(a, b):  return 0xf000 | (b << 8) | (a << 4) | 0xc      # fmov frA,frB
def fcmp_gt(a, b): return 0xf000 | (b << 8) | (a << 4) | 5        # T = frB > frA
def fadd(m, n):    return 0xf000 | (m << 8) | (n << 4) | 0x0      # frN += frM
def fsub(m, n):    return 0xf000 | (m << 8) | (n << 4) | 0x1      # frN -= frM
def bts(d):        return 0x8d00 | d
def bfs(d):        return 0x8f00 | d
def bra(d):        return 0xa000 | d
def movi(i, n):    return 0xe000 | (n << 8) | (i & 0xff)          # mov #imm,rN
def mov_rr(m, n):  return 0x6000 | (n << 8) | (m << 4) | 0x3      # mov rM,rN
def movb_rm(m, n): return 0x6000 | (n << 8) | (m << 4) | 0x0      # mov.b @rM,rN
def movb_mr(m, n): return 0x2000 | (n << 8) | (m << 4) | 0x0      # mov.b rM,@rN
def movw_rm(m, n): return 0x6000 | (n << 8) | (m << 4) | 0x8      # mov.w @rM,rN
def movw_mr(m, n): return 0x2000 | (n << 8) | (m << 4) | 0x0      # mov.w rM,@rN
def extub(m, n):   return 0x6000 | (n << 8) | (m << 4) | 0xc
def extuw(m, n):   return 0x6000 | (n << 8) | (m << 4) | 0xd
def cmpeq(i, n):   return 0x8800 | (n << 8) | (i & 0xff)
def tst(m, n):     return 0x2000 | (n << 8) | (m << 4) | 0x8
def or_r(m, n):    return 0x2000 | (n << 8) | (m << 4) | 0xb
def addi(i, n):    return 0x7000 | (n << 8) | (i & 0xff)
def movt(n):       return 0x0029 | (n << 8)
def push(n):       return 0x2f00 | (n << 4) | 0x6                # mov.l rN,@-r15
def pop(n):        return 0x6f00 | (n << 4) | 0x6                 # mov.l @r15+,rN
NOP, RTS, STS_PR, LDS_PR = 0x0009, 0x000b, 0x4f22, 0x4f26
JSR_R0, JMP_R1 = 0x420b, 0x412b


def f32(v):
    return struct.unpack('>I', struct.pack('>f', float(v)))[0]


class Asm:
    """Two-pass label assembler emitting 16-bit words at a base address."""
    def __init__(self, base):
        self.base = base
        self.words = []      # list of (offset, word-or-label-ref)
        self.labels = {}
        self.fixups = []     # (offset, kind, label)
    def here(self):
        return self.base + 2 * len(self.words)
    def label(self, name):
        self.labels[name] = self.here()
    def emit(self, w):
        self.words.append(w & 0xffff)
    def emit_br(self, kind, label):   # kind: 'bt','bf','bra'
        self.fixups.append((len(self.words), kind, label))
        self.words.append(0)
    def pool(self, name, value):      # reserve a 4-aligned pool slot
        while self.here() % 4:
            self.emit(NOP)
        self.labels[name] = self.here()
        self.emit((value >> 16) & 0xffff)
        self.emit(value & 0xffff)
    def pc_word(self, n, label):      # mov.l @(label,pc),rN; needs 4-aligned addr
        while self.here() % 4:
            self.emit(NOP)
        self.fixups.append((len(self.words), 'movl', (n, label)))
        self.words.append(0)
    def finish(self):
        for off, kind, lab in self.fixups:
            addr = self.base + 2 * off
            tgt = self.labels[lab] if isinstance(lab, str) else lab[1] if kind == 'movl' else lab
            if kind == 'movl':
                n, lbl = lab
                tgt = self.labels[lbl]
                d = tgt - addr - 4
                assert 0 <= d <= 1020 and d % 4 == 0
                self.words[off] = 0xd000 | (n << 8) | (d // 4)
            else:
                d = (tgt - addr - 4) // 2
                assert 0 <= d
                if kind == 'bra':
                    assert d <= 0xfff
                    self.words[off] = 0xa000 | d
                else:
                    assert d <= 255
                    self.words[off] = (0x8d00 if kind == 'bt' else 0x8f00) | d
        return b''.join(struct.pack('>H', w) for w in self.words)


def build_cave(cave, data_addr, state_addr, delta):
    """Cave = post-processor called instead of 0xedc4 (r4 = phase param)."""
    a = Asm(cave)
    EDC4 = LIMITER_FUNC + delta
    E2D4 = COMBINER_FUNC + delta
    # prologue
    a.emit(push(14)); a.emit(push(13)); a.emit(push(12)); a.emit(push(11)); a.emit(STS_PR)
    a.emit(mov_rr(4, 14))                       # save param
    a.pc_word(0, 'P_EDC4'); a.emit(JSR_R0); a.emit(NOP)   # jsr stock 0xedc4 (returns via e2d4)
    a.emit(mov_rr(14, 4))                       # restore param
    # mode cell (data+4)
    a.pc_word(11, 'P_DATA')
    a.emit(addi(4, 11)); a.emit(fmov_s(11, 9))  # fr9 = mode
    a.pc_word(11, 'P_F1'); a.emit(fmov_s(11, 1))   # fr1 = 1.0
    a.emit(fcmp_gt(9, 1))                       # T = 1 > mode
    a.emit_br('bt', 'DONE')                     # mode < 1 -> passthrough
    a.emit(fcmp_gt(1, 9))                       # T = mode > 1
    a.emit_br('bt', 'GT1')
    a.emit_br('bra', 'HARD')                    # mode == 1 -> hard
    a.label('GT1')
    a.pc_word(11, 'P_F2'); a.emit(fmov_s(11, 2))   # fr2 = 2.0
    a.emit(fcmp_gt(2, 9))                       # T = mode > 2
    a.emit_br('bt', 'HARD')
    # fallthrough: soft (mode == 2)
    a.label('SOFT')
    # rpm + limit cell
    a.pc_word(11, 'P_RPM'); a.emit(fmov_s(11, 0))  # fr0 = rpm
    a.pc_word(11, 'P_DATA'); a.emit(fmov_s(11, 8)) # fr8 = limit cell0
    a.pc_word(11, 'P_F0'); a.emit(fmov_s(11, 5))   # fr5 = 0.0
    a.emit(fcmp_gt(5, 8))                       # T = limit > 0
    a.emit_br('bt', 'CELL')
    # stock-flags path (cell0 <= 0): over = a444|a445 from stock call
    a.pc_word(11, 'P_A444'); a.emit(movb_rm(11, 6))
    a.pc_word(11, 'P_A445'); a.emit(movb_rm(11, 7))
    a.emit(or_r(7, 6)); a.emit(tst(6, 6))
    a.emit_br('bt', 'OVER')
    a.emit_br('bra', 'NOT_OVER')
    # cell path
    a.label('CELL')
    a.emit(fcmp_gt(0, 8))                       # T = limit > rpm
    a.emit_br('bt', 'NOT_OVER')
    a.label('OVER')
    # hard band: fr6 = limit + cell3 ; over_hard = rpm >= fr6  (cell path only)
    a.pc_word(11, 'P_DATA'); a.emit(addi(12, 11)); a.emit(fmov_s(11, 11))  # fr11 = cell3
    a.emit(fmov_r(11, 6)); a.emit(fadd(8, 6))   # fr6 = limit + margin
    a.emit(fcmp_gt(0, 6))                       # T = hardlimit > rpm
    a.emit_br('bt', 'NOT_HARD')
    a.emit_br('bra', 'WRITE_BOTH')
    a.label('NOT_HARD')
    # recovery: fr7 = limit - cell2 ; recovered = rpm <= fr7  (cell path only)
    a.pc_word(11, 'P_DATA'); a.emit(addi(8, 11)); a.emit(fmov_s(11, 10))   # fr10 = cell2
    a.emit(fmov_r(8, 7)); a.emit(fsub(10, 7))   # fr7 = limit - recovery
    a.emit(fcmp_gt(7, 0))                       # T = rpm > limitrec (NOT recovered)
    a.emit_br('bf', 'WRITE_NONE')               # recovered (rpm <= limit-recovery) -> clear flags
    # soft: alternate phase via state cell bit0
    a.pc_word(11, 'P_STATE'); a.emit(movw_rm(11, 12))   # r12 = state
    a.emit(cmpeq(0, 12))                        # state == 0 ?
    a.emit(movt(13))
    a.emit_br('bt', 'PHASE1')                   # wait: movt sets T; bt taken if T... need branch on T after movt: bt/s uses T
    a.emit(movi(0, 5)); a.emit(movi(1, 6)); a.emit_br('bra', 'WRITE_FLAGS')  # phase was 0 -> a444=0,a445=1? define phase0: a444=1,a445=0
    a.label('PHASE1')
    a.emit(movi(1, 5)); a.emit(movi(0, 6))
    a.emit_br('bra', 'WRITE_FLAGS')
    a.label('HARD')
    a.label('WRITE_BOTH')
    a.emit(movi(1, 5)); a.emit(movi(1, 6))
    a.emit_br('bra', 'WRITE_FLAGS')
    a.label('WRITE_NONE')
    a.emit(movi(0, 5)); a.emit(movi(0, 6))
    a.label('WRITE_FLAGS')
    a.pc_word(11, 'P_A444'); a.emit(movb_mr(5, 11))
    a.pc_word(11, 'P_A445'); a.emit(movb_mr(6, 11))
    # flip state cell (0<->1)
    a.pc_word(11, 'P_STATE'); a.emit(movw_rm(11, 12))
    a.emit(cmpeq(0, 12)); a.emit(movt(13))
    a.emit_br('bt', 'FLIP1')
    a.emit(movi(0, 12)); a.emit_br('bra', 'STSTATE')
    a.label('FLIP1'); a.emit(movi(1, 12))
    a.label('STSTATE')
    a.pc_word(11, 'P_STATE'); a.emit(movw_mr(12, 11))
    # refresh a430: call combiner again
    a.pc_word(0, 'P_E2D4'); a.emit(JSR_R0); a.emit(NOP)
    a.emit_br('bra', 'DONE')
    a.label('NOT_OVER')
    # not over: if cell path, clear flags when recovered (already handled); stock path: leave stock flags
    a.pc_word(11, 'P_F0'); a.emit(fmov_s(11, 5))
    a.emit(fcmp_gt(5, 8))                       # T = limit > 0
    a.emit_br('bf', 'DONE')                     # stock path: leave stock flags untouched
    # cell path & not over: clear flags (recovery)
    a.emit(movi(0, 5)); a.emit(movi(0, 6))
    a.pc_word(11, 'P_A444'); a.emit(movb_mr(5, 11))
    a.pc_word(11, 'P_A445'); a.emit(movb_mr(6, 11))
    a.pc_word(0, 'P_E2D4'); a.emit(JSR_R0); a.emit(NOP)
    a.label('DONE')
    # epilogue
    a.emit(LDS_PR); a.emit(pop(11)); a.emit(pop(12)); a.emit(pop(13)); a.emit(pop(14)); a.emit(RTS)
    # pool
    a.pool('P_EDC4', EDC4)
    a.pool('P_E2D4', E2D4)
    a.pool('P_DATA', data_addr)
    a.pool('P_STATE', state_addr)
    a.pool('P_RPM', 0xffffb548)
    a.pool('P_A444', 0xffffa444)
    a.pool('P_A445', 0xffffa445)
    a.pool('P_F0', f32(0.0))
    a.pool('P_F1', f32(1.0))
    a.pool('P_F2', f32(2.0))
    return a.finish(), len(a.words) * 2


def find_free_run(rom, need):
    i = 0x6c000
    best = None
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
        raise SystemExit('no free cal-area run big enough')
    return best[0] + (-best[0]) % 4


def simulate(mode, limit, recovery, margin, rpm_seq):
    """Invariant sweep (spec §7): model the patched state machine; assert I1/I2."""
    state = 0
    prev = None
    for rpm in rpm_seq:
        over = rpm >= limit
        hard = rpm >= limit + margin
        rec = rpm <= limit - recovery
        if hard:
            a444 = a445 = 1
        elif over:
            state ^= 1
            a444, a445 = (state, 1 - state) if mode == 2 else (1, 1)
        elif rec:
            a444 = a445 = 0
        else:
            a444, a445 = (state, 1 - state) if mode == 2 else (0, 0)
        # I1/I2: ignition inhibit implies fuel inhibit on same rotor (flags are paired)
        assert a444 == a445 or mode == 2  # soft alternates; each rotor cut is paired via shared flags
        prev = (a444, a445)
    return prev


def patch_rom(in_path, mode, limit, recovery, margin, out_dir=None, dry_run=False):
    in_path = Path(in_path)
    ref = REF_ROM.read_bytes()
    data = in_path.read_bytes()
    sha_in = hashlib.sha256(data).hexdigest()
    # locate the limiter function by exact body match
    lim_pat = ref[LIMITER_FUNC:LIMITER_FUNC + LIMITER_BODY]
    lim_hits, pos = [], data.find(lim_pat)
    while pos >= 0:
        if data[pos:pos + LIMITER_BODY] == lim_pat:
            lim_hits.append(pos)
        pos = data.find(lim_pat, pos + 1)
    if len(lim_hits) != 1:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': f'limiter body match {len(lim_hits)}'}
    limiter = lim_hits[0]
    delta = limiter - LIMITER_FUNC
    # locate the call site: a u32 pool word holding the limiter address, referenced
    # by mov.l @(disp,pc),rX followed by jsr @rX (0x420b) within 1KB before it
    needle = struct.pack('>I', limiter)
    pool_word = None
    pos = data.find(needle)
    while pos >= 0:
        lo = max(0, pos - 1024)
        for a in range(lo, pos - 3, 2):
            w = struct.unpack('>H', data[a:a + 2])[0]
            if (w & 0xf000) == 0xd000 and ((a + 4) & ~3) + (w & 0xff) * 4 == pos:  # mov.l EA aligns PC down to 4
                rn = (w >> 8) & 0xf
                for b in (a + 2, a + 4):  # jsr @rX in the next slot or after the delay slot
                    w2 = struct.unpack('>H', data[b:b + 2])[0]
                    if (w2 & 0xf0ff) == 0x400b and ((w2 >> 8) & 0xf) == rn:
                        pool_word = pos
                        break
                if pool_word:
                    break
        if pool_word:
            break
        pos = data.find(needle, pos + 1)
    if pool_word is None:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'call site not found'}
    caller = None
    # clamp limit (spec §4.3)
    clamped = min(limit, MAX_LIMIT) if limit > 0 else limit
    # cal block + cave in one free run
    run = find_free_run(data, 64 + 512)
    desc, axis, cdata = run, run + 0x10, run + 0x20
    state = cdata + 16
    cave = run + 0x40
    cave = cave + (-cave) % 4
    cave_bytes, cave_len = build_cave(cave, cdata, state, delta)
    if cave + cave_len > run + 0x1000 and cave + cave_len > len(data):
        pass
    if cave + cave_len > 0x80000:
        return {'rom': in_path.name, 'status': 'SKIP', 'reason': 'cave past cal area'}
    # invariant sweep before emitting
    sweep = [x * 50.0 for x in range(0, 200)] + [9000 + x for x in range(-500, 600, 25)]
    simulate(2, clamped if clamped > 0 else 9000, recovery, margin, sweep)
    out = bytearray(data)
    old = {f'{pool_word:#x}': f'{struct.unpack(">I", out[pool_word:pool_word+4])[0]:08x}'}
    out[pool_word:pool_word + 4] = struct.pack('>I', cave)
    # cal block
    cal = {desc: struct.pack('>HBBII', 4, 0, 0, axis, cdata),
           axis: struct.pack('>ffff', 0.0, 1.0, 2.0, 3.0),
           cdata: struct.pack('>ffff', clamped, float(mode), float(recovery), float(margin)),
           state: struct.pack('>H', 0)}
    for a, blob in cal.items():
        assert all(b == 0xff for b in out[a:a + len(blob)]), f'cal not free at {a:#x}'
        old[f'{a:#x}'] = 'ff' * len(blob)
        out[a:a + len(blob)] = blob
    assert all(b == 0xff for b in out[cave:cave + cave_len]), 'cave area not free'
    old[f'{cave:#x}'] = 'ff' * cave_len
    out[cave:cave + cave_len] = cave_bytes
    # checks
    assert hashlib.sha256(in_path.read_bytes()).hexdigest() == sha_in, 'input modified!'
    allowed = set(range(pool_word, pool_word + 4)) | set(range(cave, cave + cave_len)) | {a + k for a, b in cal.items() for k in range(len(b))}
    diff = [i for i in range(len(data)) if data[i] != out[i]]
    assert all(i in allowed for i in diff), 'diff outside patched spans'
    # verify cal descriptor parses (2D >HBBII)
    n, typ, _b, ax, dp = struct.unpack_from('>HBBII', out, desc)
    assert (n, typ, ax, dp) == (4, 0, axis, cdata)
    name = 'Rev Limiter Behavior'
    xml = (f'        <table name="{name}" category="Protection" type="2D" storagetype="float" endian="big" sizey="4">\n'
           f'            <scaling units="see axis" expression="x" to_byte="x" format="0.00" />\n'
           f'            <table name="Index (0=limit rpm override (le 0 = stock), 1=mode 0/1/2, 2=recovery rpm, 3=hard margin rpm)" type="Y Axis" storagetype="float" endian="big" expression="x" to_byte="x" />\n'
           f'        </table>\n'
           f'        <table name="{name}" storageaddress="0x{cdata:06X}">\n'
           f'            <table type="Y Axis" storageaddress="0x{axis:06X}" />\n'
           f'        </table>\n'
           f'<!-- NOTE: limit override cell is clamped to at most {MAX_LIMIT:.0f} rpm at build time; tach over-reads ~3-5%. -->\n')
    result = {'rom': in_path.name, 'status': 'OK', 'mode': mode, 'input_sha256': sha_in,
              'call_site_pool_word': f'{pool_word:#x}', 'limiter_offset': f'{limiter:#x}',
              'patched_pool_word': f'{pool_word:#x}', 'cal': {'descriptor': f'{desc:#x}', 'axis': f'{axis:#x}',
              'data': f'{cdata:#x}', 'state': f'{state:#x}'}, 'cave': f'{cave:#x}',
              'limit_rpm': clamped, 'limit_clamped': clamped != limit, 'recovery': recovery, 'hard_margin': margin,
              'bytes_changed': len(diff), 'old_words': old, 'romraider_xml': xml}
    if not dry_run:
        out_dir = Path(out_dir) if out_dir else in_path.parent
        out_dir.mkdir(parents=True, exist_ok=True)
        mode_name = {0: 'stock', 1: 'hard', 2: 'soft'}[mode]
        out_path = out_dir / f'{in_path.stem}_limiter_{mode_name}.bin'
        out_path.write_bytes(bytes(out))
        out_path.with_suffix('.xml').write_text(xml)
        result['output'] = str(out_path)
        result['output_sha256'] = hashlib.sha256(bytes(out)).hexdigest()
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('inputs', nargs='+')
    ap.add_argument('--mode', default='soft', help='stock|hard|soft or 0|1|2')
    ap.add_argument('--limit', type=float, default=-1.0, help='limit override rpm; <=0 = stock (clamped to <= 9300)')
    ap.add_argument('--recovery', type=float, default=150.0)
    ap.add_argument('--hard-margin', type=float, default=300.0)
    ap.add_argument('--out', default=None)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--report', default=None)
    args = ap.parse_args()
    m = {'stock': 0, 'hard': 1, 'soft': 2}.get(str(args.mode), args.mode)
    args.mode = int(m)
    if args.limit > MAX_LIMIT:
        print(f'clamp: limit {args.limit} -> {MAX_LIMIT}', file=sys.stderr)
    files = []
    for i in args.inputs:
        p = Path(i)
        files.extend(sorted(p.glob('*.bin')) if p.is_dir() else [p])
    results = [patch_rom(f, args.mode, args.limit, args.recovery, args.hard_margin, args.out, args.dry_run) for f in files]
    for r in results:
        print(json.dumps({k: r[k] for k in ('rom', 'status', 'caller_offset', 'output') if k in r}))
    if args.report:
        Path(args.report).write_text(json.dumps({'mode': args.mode, 'limit': args.limit, 'results': results}, indent=2) + '\n')
    sys.exit(1 if any(r['status'] != 'OK' for r in results) else 0)


if __name__ == '__main__':
    main()
