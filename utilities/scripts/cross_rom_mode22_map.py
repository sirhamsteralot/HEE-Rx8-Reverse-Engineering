#!/usr/bin/env python3
"""ROADMAP group D item 2: map the Mode 22 (ReadDataByIdentifier) dispatch
table and its PID handlers across all stock ROMs + own dumps.

Base ROM 60E15120_N3J1E: dispatch table at 0x5f10c = 99 x 12-byte records
{u16 pid, u8 response_len, u8 byte3, u16 availability_mask, u16 unk, u32 handler}
(big-endian). Dispatcher 0x5774c (diag22_find_and_dispatch_identifier) scans the
table; its literal pool word at 0x57848 holds the table address, and the pool
word at 0x57854 points at the count byte stored right after the table
(rom[table + count*12] == count, self-consistent). Record layout cross-checked
against data/labels/60E15120_N3J1E/diagnostic_dispatch_named.tsv.

Per target ROM the table is located by (a) direct byte-compare at 0x5f10c or
(b) a generic run-scan (>=30 stride-12 records with ascending u16 pid and
in-range even handlers) filtered by "u32(table_addr) appears in the ROM"
(pool reference). The record count is then derived self-consistently
(rom[table + N*12] == N AND u32(table + N*12) referenced) and must be unique.
All handler fields must be even addresses in the code region 0x40..0x6c000.

Each handler address is mapped back to the base ROM via
cross_rom_function_matches.tsv (unique_exact_bytes, re-verified against raw ROM
bytes here) or by identical address; byte-matched bodies are re-compared
byte-for-byte in this script (rule 7). Labels (handler_alias/semantic/
confidence) are inherited from the base record with the same PID when present;
PIDs that only exist in a target ROM get the base function name of their
byte-matched handler as a ref_-level hypothesis and are flagged pid_in_base=0.

Outputs (new files, nothing existing is modified):
  - data/labels/cross_rom_mode22_pid_handlers.tsv  (rom x record rows)
  - data/labels/cross_rom_mode22_summary.json      (per-ROM location + stats)

Run from the repo root:  python utilities/scripts/cross_rom_mode22_map.py
"""
from pathlib import Path
import csv, hashlib, json, struct
from collections import Counter

ROOT = Path(__file__).resolve().parents[2]
BASE_ROM_ID = "60E15120_N3J1E"
LABELS = ROOT / "data" / "labels" / BASE_ROM_ID
STOCK = ROOT / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
DUMPS = ROOT / "binaries" / "dumps"

BASE_TABLE = 0x5f10c
REC = 12
CODE_LO, CODE_HI = 0x40, 0x6c000  # code region per design README (descriptors start 0x6c000)

base_rom = (STOCK / (BASE_ROM_ID + ".bin")).read_bytes()
BASE_SHA = hashlib.sha256(base_rom).hexdigest()
info = json.loads((LABELS / "input.json").read_text())
assert BASE_SHA == info["sha256"], "base ROM hash mismatch"


def parse_records(rom, addr, n):
    out = []
    for i in range(n):
        o = addr + i * REC
        pid, ln, b3, mask, unk, h = struct.unpack_from(">HBBHHI", rom, o)
        out.append({"record": o, "pid": pid, "len": ln, "b3": b3,
                    "mask": mask, "unk": unk, "handler": h})
    return out


def find_all(rom, pat):
    out, i = [], rom.find(pat)
    while i >= 0:
        out.append(i)
        i = rom.find(pat, i + 1)
    return out


def valid_handler(h):
    return CODE_LO <= h < CODE_HI and h % 2 == 0


# base table + label cross-check
base_count = base_rom[BASE_TABLE + 99 * REC]
assert base_count == 99 and find_all(base_rom, struct.pack(">I", BASE_TABLE + 99 * REC)), "base count self-check"
base_recs = parse_records(base_rom, BASE_TABLE, 99)
named = {int(r["pid"], 16): r for r in csv.DictReader(
    (LABELS / "diagnostic_dispatch_named.tsv").open(newline=""), delimiter="\t")}
assert len(named) == 99
for r in base_recs:
    n = named[r["pid"]]
    assert int(n["record_address"], 16) == r["record"] and int(n["handler"], 16) == r["handler"]
base_pids = [r["pid"] for r in base_recs]
base_table_bytes = base_rom[BASE_TABLE:BASE_TABLE + 99 * REC]

# base -> target function matches (unique_exact_bytes)
matches = {}
for r in csv.DictReader((ROOT / "data/labels/cross_rom_function_matches.tsv").open(newline=""), delimiter="\t"):
    matches.setdefault(r["rom"], {})[r["target_address"]] = (
        int(r["base_address"], 16), r["base_name"], int(r["size"]))

targets = {}
for p in sorted(STOCK.glob("*.bin")):
    targets[p.name] = p.read_bytes()
for p in sorted(DUMPS.glob("*.bin")):
    targets["dumps/" + p.name] = p.read_bytes()


def scan_runs(rom, min_run=30):
    """Maximal runs of stride-12 records: ascending u16 pid, valid handler."""
    cands, o, n = [], CODE_LO, len(rom)
    while o + REC * min_run < n:
        if valid_handler(struct.unpack_from(">I", rom, o + 8)[0]):
            prev = struct.unpack_from(">H", rom, o)[0]
            i = 1
            while o + (i + 1) * REC <= n:
                pid = struct.unpack_from(">H", rom, o + i * REC)[0]
                h = struct.unpack_from(">I", rom, o + i * REC + 8)[0]
                if pid <= prev or not valid_handler(h):
                    break
                prev = pid
                i += 1
            if i >= min_run:
                cands.append(o)
                o += i * REC
                continue
        o += 2
    return cands


def locate_table(rom):
    if rom[BASE_TABLE:BASE_TABLE + len(base_table_bytes)] == base_table_bytes:
        return BASE_TABLE, True
    cands = [c for c in scan_runs(rom) if find_all(rom, struct.pack(">I", c))]
    assert len(cands) == 1, f"table candidates: {[hex(c) for c in cands]}"
    return cands[0], False


def find_count(rom, table):
    hits = []
    for n in range(1, 256):
        c = table + n * REC
        if c >= len(rom):
            break
        if rom[c] == n and find_all(rom, struct.pack(">I", c)):
            hits.append((n, c))
    assert len(hits) == 1, f"count candidates at {table:x}: {hits}"
    return hits[0]


rows = []
summary = {"date": "2026-11-01", "base_rom": BASE_ROM_ID, "base_sha256": BASE_SHA,
           "base_table": f"{BASE_TABLE:08x}", "base_record_count": 99,
           "record_format": "u16 pid, u8 len, u8 byte3, u16 mask, u16 unk, u32 handler (BE, 12 B)",
           "locator": "direct byte-compare at 0x5f10c, else run-scan (>=30 ascending-pid records, valid handlers) + u32 pool ref; count = unique N with rom[table+N*12]==N and u32 ref",
           "handler_mapping": "base | same_address | byte_match (cross_rom_function_matches.tsv, bodies re-compared from raw ROM bytes; asserted == same-pid base handler) | pid_match (same PID + same response_len in base; address link NOT asserted) | unmapped (PID not in base)",
           "roms": {}}

for rom_name, rom in targets.items():
    sha = hashlib.sha256(rom).hexdigest()
    table, identical = locate_table(rom)
    count, count_addr = find_count(rom, table)
    recs = parse_records(rom, table, count)
    assert all(valid_handler(r["handler"]) for r in recs), rom_name
    table_refs = find_all(rom, struct.pack(">I", table))
    count_refs = find_all(rom, struct.pack(">I", count_addr))
    pids = [r["pid"] for r in recs]
    pids_match_base = (pids == base_pids)
    extra = sorted(set(pids) - set(base_pids))
    missing = sorted(set(base_pids) - set(pids))
    m = matches.get(rom_name, {})
    methods = Counter()
    unmapped = []
    for r in recs:
        h = r["handler"]
        n = named.get(r["pid"])
        if rom_name == BASE_ROM_ID + ".bin":
            meth, base_h, bname = "base", h, n["handler_alias"]
        elif n is not None and h == int(n["handler"], 16):
            meth, base_h, bname = "same_address", h, n["handler_alias"]
        elif f"{h:08x}" in m:
            base_h, bname, bsize = m[f"{h:08x}"]
            meth = "byte_match"
            # rule 7: re-verify the byte match against raw ROM bytes
            assert base_rom[base_h:base_h + bsize] == rom[h:h + bsize], (rom_name, hex(h))
            # cross-check: a byte-matched handler for a base PID must be the base
            # handler of that same PID
            if n is not None:
                assert base_h == int(n["handler"], 16), (rom_name, hex(h), hex(base_h))
        else:
            meth, base_h, bname = "unmapped", None, None
            unmapped.append({"pid": f"{r['pid']:04x}", "handler": f"{h:08x}"})
        # PID-level inheritance: same PID + same response_len in base -> inherit the
        # semantic label, but the handler ADDRESS link is not asserted (confidence
        # downgraded to pid_match; base_handler_address stays empty).
        conf = n["confidence"] if n else ""
        if meth == "unmapped" and n is not None and int(n["response_len"]) == r["len"]:
            meth, conf = "pid_match", "pid_match"
            unmapped.pop()
        methods[meth] += 1
        rows.append({
            "rom": rom_name, "pid": f"{r['pid']:04x}", "record_address": f"{r['record']:08x}",
            "response_len": r["len"], "byte3": f"{r['b3']:02x}", "availability_mask": f"{r['mask']:04x}",
            "unk": f"{r['unk']:04x}", "handler_address": f"{h:08x}",
            "base_handler_address": f"{base_h:08x}" if base_h is not None else "",
            "map_method": meth, "pid_in_base": 1 if n else 0,
            "handler_alias": n["handler_alias"] if n else "",
            "base_function_name": bname or "",
            "semantic": n["semantic"] if n else "", "confidence": conf})
    summary["roms"][rom_name] = {
        "sha256": sha, "table_address": f"{table:08x}", "table_identical_to_base": identical,
        "record_count": count, "count_byte_address": f"{count_addr:08x}",
        "table_pool_refs": [f"{a:08x}" for a in table_refs],
        "count_pool_refs": [f"{a:08x}" for a in count_refs],
        "subpid_table_address": f"{count_addr + 2:08x}",
        "pids_match_base": pids_match_base, "extra_pids": [f"{p:04x}" for p in extra],
        "missing_pids": [f"{p:04x}" for p in missing],
        "handlers": dict(methods), "unmapped_handlers": unmapped}
    print(f"{rom_name:52s} table={table:06x} n={count:3d} ident={identical} "
          f"pool={[hex(a) for a in table_refs]} pids_base={pids_match_base} "
          f"extra={len(extra)} missing={len(missing)} {dict(methods)}")

out_tsv = ROOT / "data/labels/cross_rom_mode22_pid_handlers.tsv"
with out_tsv.open("w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=list(rows[0].keys()), delimiter="\t", lineterminator="\n")
    w.writeheader()
    w.writerows(rows)
(ROOT / "data/labels/cross_rom_mode22_summary.json").write_text(json.dumps(summary, indent=1) + "\n")
print(f"\nwrote {out_tsv.relative_to(ROOT)} ({len(rows)} rows) + data/labels/cross_rom_mode22_summary.json")
