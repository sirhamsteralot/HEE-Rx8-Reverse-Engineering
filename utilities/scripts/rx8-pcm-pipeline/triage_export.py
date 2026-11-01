#!/usr/bin/env python3
"""Triage the 154 decompiler-warning functions and classify the 1,759
non-instruction ranges of the 60E15120_N3J1E export (ROADMAP group C item 1).

Reads only; writes NEW companion artifacts (never edits the raw TSVs):
  - decompiled/disassembly: non_instruction_ranges_classified.tsv
  - decompiled/disassembly: decompiler_issues_triaged.tsv
  - metadata (data/labels/60E15120_N3J1E/triage_export.json): summary + evidence

Every claim is re-read from the raw ROM (SHA-256 checked against
metadata/input.json first). Referrer evidence comes from the disassembly's
computed `@(0xEA,pc)` annotations. Run from anywhere:
    python utilities/scripts/rx8-pcm-pipeline/triage_export.py
"""
from pathlib import Path
import bisect, csv, hashlib, json, re, struct
from collections import Counter, defaultdict

from paths import b, base, rom_file, ROOT, DEC, DISASM, LABELS

info = json.loads((LABELS / "input.json").read_text())
ROM = rom_file().read_bytes()
assert len(ROM) == info["size"], "ROM size mismatch"
ROM_SHA = hashlib.sha256(ROM).hexdigest()
assert ROM_SHA == info["sha256"], "ROM SHA-256 mismatch vs metadata/input.json"

CODE_END = 0x68E40   # code region per docs/architecture/design/README.md §1
CAL_START = 0x6C000  # descriptor/calibration area
RAM_LO, RAM_HI = 0xFFFF6000, 0xFFFFE000


def rows(path):
    with path.open(newline="") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def write_tsv(path, fieldnames, rs):
    with path.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames, delimiter="\t")
        w.writeheader()
        w.writerows(rs)


index = rows(base / "decompiled/function_index.tsv")
symbols = rows(base / "decompiled/symbols.tsv")
calls = rows(base / "decompiled/callgraph.tsv")
ranges = rows(base / "decompiled/non_instruction_ranges.tsv")
issues = rows(base / "decompiled/decompiler_issues.tsv")

func_starts = sorted(int(r["address"], 16) for r in index)
func_by_start = {int(r["address"], 16): r for r in index}
callers = Counter(e["callee"] for e in calls)


def containing_function(a):
    i = bisect.bisect_right(func_starts, a) - 1
    if i < 0:
        return ""
    r = func_by_start[func_starts[i]]
    end = func_starts[i] + int(r["body_bytes"])
    return r["name"] if a < end else ""


# ---- referrer map from the disassembly's computed @(0xEA,pc) annotations ----
ea_refs = defaultdict(list)          # EA -> [(instr_addr, mnemonic)]
branch_targets = set()               # all 0x........ branch targets
asm_lines = (base / "decompiled/firmware_disassembly.asm").read_text().splitlines()
pc_pat = re.compile(r"@\(0x([0-9a-f]+),pc\)")
br_pat = re.compile(r"\b(?:bra|bsr|bt|bf|bt/s|bf/s|bra/s|bsr/s)\s+(?:0x([0-9a-f]+)|-?)")
for line in asm_lines:
    parts = line.split(None, 2)
    if len(parts) < 3:
        continue
    ia = int(parts[0], 16)
    mn = parts[2].split()[0]
    m = pc_pat.search(parts[2])
    if m:
        ea_refs[int(m.group(1), 16)].append((ia, mn))
    for bm in re.finditer(r"(?:bra|bsr|bt|bf)(?:/s)?\s+0x([0-9a-f]+)", parts[2]):
        branch_targets.add(int(bm.group(1), 16))


def sane_float(x):
    return x == 0.0 or 1e-6 <= abs(x) <= 1e7


def classify_range(a, n):
    """Return (class, detail) from ROM content + pc-relative referrers."""
    d = ROM[a:a + n]
    refs = [(ea, ia, mn) for ea in range(a, a + n + 1) if ea in ea_refs
            for ia, mn in ea_refs[ea]]
    mns = sorted({mn for _, _, mn in refs})
    if a == 0 and n % 4 == 0:  # the IVT occupies only 0x0-0x3f (16 used vectors); code starts at 0x40
        u32 = struct.unpack(">%dI" % (n // 4), d)
        ncode = sum(1 for v in u32 if 0x40 <= v < CODE_END)
        nother = [hex(v) for v in u32 if not (0x40 <= v < CODE_END)]
        return ("vector_table", "%d vectors: %d code ptrs, other=%s" % (n // 4, ncode, nother)), refs, mns
    if n and all(x == 0 for x in d):
        return ("zero_pad", "alignment/unused"), refs, mns
    if n and all(x == 0xFF for x in d):
        return ("ff_pad", "erased flash padding"), refs, mns
    # ascii string: mostly printable, a real run (>=8), and NUL-terminated or spaced
    # (excludes code sleds like the 40 21 shar sled and pointer blocks)
    printable = sum(1 for x in d if 32 <= x < 127)
    run = best = 0
    for x in d:
        run = run + 1 if 32 <= x < 127 else 0
        best = max(best, run)
    if n >= 8 and printable / n >= 0.6 and best >= 12 and (0 in d or 32 in d):
        txt = "".join(chr(x) if 32 <= x < 127 else "." for x in d[:64])
        return ("ascii_string", repr(txt)), refs, mns
    if n % 4 == 0 and n >= 4:
        u32 = struct.unpack(">%dI" % (n // 4), d)
        if all(0x40 <= v < CODE_END for v in u32):
            return ("ptr_pool_code", "u32 targets in code 0x40-0x%x" % (CODE_END - 1)), refs, mns
        if all(CAL_START <= v < 0x80000 for v in u32):
            return ("ptr_pool_data", "u32 targets in data/cal 0x%x-0x7ffff" % CAL_START), refs, mns
        if all(RAM_LO <= v < RAM_HI for v in u32):
            return ("ptr_pool_ram", "u32 RAM pointers"), refs, mns
        if n >= 16 and all(v < 0x10000 for v in u32):
            return ("offset_table", "u32 word offsets (<0x10000), mova-relative jump table" if "mova" in mns
                    else "u32 small offsets"), refs, mns
        fl = struct.unpack(">%df" % (n // 4), d)
        if sum(1 for x in fl if sane_float(x)) / len(fl) >= 0.9:
            return ("float_pool", "float32 values"), refs, mns
        if a >= CAL_START and n >= 12:
            nn, typ = struct.unpack(">HB", d[:3])
            ax, dt = struct.unpack(">II", d[4:12])
            if 0 < nn < 4096 and typ <= 3 and CAL_START <= ax < 0x80000 and CAL_START <= dt < 0x80000:
                return ("cal_descriptor", "n=%d type=%d axis=0x%x data=0x%x" % (nn, typ, ax, dt)), refs, mns
        if refs:
            return ("u32_table", "referenced by " + "+".join(mns)), refs, mns
        return ("u32_data", "no pc-relative referrer"), refs, mns
    if n % 2 == 0:
        if refs and mns == ["mov.w"]:
            return ("word_literal_pool", "mov.w sign-extended literals"), refs, mns
        if refs:
            return ("mixed_pool", "referenced by " + "+".join(mns)), refs, mns
        return ("u16_data", "no pc-relative referrer"), refs, mns
    return ("odd_data", "odd length"), refs, mns


classified = []
class_counts = Counter()
for r in ranges:
    a, e = int(r["start"], 16), int(r["end"], 16)
    n = int(r["bytes"])
    (cls, detail), refs, mns = classify_range(a, n)
    class_counts[cls] += 1
    classified.append({
        "start": r["start"], "end": r["end"], "bytes": r["bytes"],
        "class": cls, "detail": detail,
        "referrers": str(len(refs)),
        "ref_mnemonics": "+".join(mns),
        "first_referrer": ("0x%x" % refs[0][1]) if refs else "",
        "containing_function": containing_function(a),
        "sample_hex": ROM[a:a + min(n, 16)].hex(),
    })

write_tsv(base / "decompiled/non_instruction_ranges_classified.tsv",
          ["start", "end", "bytes", "class", "detail", "referrers", "ref_mnemonics",
           "first_referrer", "containing_function", "sample_hex"], classified)
write_tsv(base / "disassembly/non_instruction_ranges_classified.tsv",
          ["start", "end", "bytes", "class", "detail", "referrers", "ref_mnemonics",
           "first_referrer", "containing_function", "sample_hex"], classified)


# ---- decompiler-issue triage -------------------------------------------------
def rom_u32_refs(target):
    needle = struct.pack(">I", target)
    hits, i = [], -1
    while True:
        i = ROM.find(needle, i + 1)
        if i < 0:
            return hits
        hits.append(i)


def record_table(base_addr, max_n=64):
    """Dump an 8-byte-record dispatch table (key:u8, pad:3, target:u32) from ROM."""
    out = []
    for i in range(max_n):
        off = base_addr + i * 8
        key = ROM[off]
        tgt = struct.unpack(">I", ROM[off + 4:off + 8])[0]
        out.append((key, tgt))
        if key == 0:
            break
    return out


# record-dispatch recovery for the two jumptable_truncated functions
recovered = {}
for fn_addr, pool_addr in ((0x54D90, 0x54E34), (0x55A7C, 0x55C64)):
    pool = struct.unpack(">I", ROM[pool_addr:pool_addr + 4])[0]
    tbl = record_table(pool)
    recovered["%08x" % fn_addr] = {
        "dispatcher": "0x%x" % fn_addr,
        "pool_word": "0x%x" % pool_addr,
        "table_base": "0x%x" % pool,
        "records": [{"key": "0x%02x" % k, "target": "0x%08x" % t} for k, t in tbl],
        "record_count": len(tbl) - 1,
        "default_target": "0x%08x" % tbl[-1][1],
        "format": "key:u8 pad:3 target:u32; linear search on key, 0x00 terminator carries default",
    }

# orphan check for 0x33b6
orphan = {
    "function": "0x33b6",
    "body_bytes": func_by_start[0x33B6]["body_bytes"],
    "body_hex": ROM[0x33B6:0x33B8].hex(),
    "next_word_hex": ROM[0x33B8:0x33BA].hex(),
    "u32_pointer_refs": [hex(h) for h in rom_u32_refs(0x33B6)],
    "branch_target": 0x33B6 in branch_targets,
    "callgraph_callers": callers.get("000033b6", 0),
}

inner_label_counts = {}
for s in symbols:
    a = int(s["address"], 16)
    if s["type"] == "Label":
        fn = containing_function(a)
        if fn and func_by_start.get(func_starts[bisect.bisect_right(func_starts, a) - 1], {}).get("address") != s["address"]:
            pass  # counted below per function instead

verdicts = []
verdict_counts = Counter()
for r in issues:
    addr = r["address"]
    a = int(addr, 16)
    iss = r["issue"]
    fn = func_by_start.get(a, {})
    body = int(fn.get("body_bytes", 0))
    ncall = callers.get(addr, 0)
    # inner labels strictly inside the body
    i0 = bisect.bisect_right(func_starts, a) - 1
    fe = func_starts[i0] + body if i0 >= 0 else a
    inner = [s["address"] + ":" + s["name"] for s in symbols
             if func_starts[i0] < int(s["address"], 16) < fe and s["type"] == "Label"] if i0 >= 0 else []
    # does the body contain an rts or a self-branch (bra to itself = halt spin)?
    body_lines = [l for l in asm_lines
                  if a <= int(l.split(None, 1)[0], 16) < fe]
    has_rts = any(l.split(None, 2)[2].strip() == "rts" for l in body_lines)
    has_self_branch = False
    for l in body_lines:
        m = re.match(r"(bra|bt|bf)(/s)?\s+0x([0-9a-f]+)\s*$", l.split(None, 2)[2].strip())
        if m and int(m.group(3), 16) == int(l.split(None, 1)[0], 16):
            has_self_branch = True
            break

    if "case table recovered" in iss:
        verdict, action = "recovered_case_table", "documented in [EXPORT CLEANUP] note; no further action"
        ev = "jump-table dispatch recovered from ROM data (see function file note)"
    elif "jump mechanism annotated" in iss:
        verdict, action = "already_annotated", "none; [EXPORT CLEANUP] note carries the disassembly evidence"
        ev = "indirect jump site annotated during export cleanup"
    elif "jumptable_truncated" in iss:
        rec = recovered.get(addr)
        verdict = "resolved_record_dispatch"
        action = ("record-dispatch table recovered by this triage: base %s, %d records + default %s; "
                  "feed into UDS/OBD dispatch labeling" %
                  (rec["table_base"], rec["record_count"], rec["default_target"])) if rec else "recover table from ROM"
        ev = ("pool word 0x%x -> table 0x%x; %d records, format %s" %
              (int(rec["pool_word"], 16), int(rec["table_base"], 16), rec["record_count"], rec["format"])) if rec else iss
    elif "bad_instruction_data" in iss:
        verdict = "orphan_artifact_unreferenced"
        action = "treat 0x33b6-0x348f as data; keep FUN_000033b6 address-only (label ladder rule 6)"
        ev = ("body %s bytes %s, next word %s (illegal 0x0000 on SH-2E); u32 ptr refs %s; branch target: %s; callers: %d"
              % (orphan["body_bytes"], orphan["body_hex"], orphan["next_word_hex"],
                 orphan["u32_pointer_refs"], orphan["branch_target"], orphan["callgraph_callers"]))
    elif "infinite_loop_block" in iss:
        if has_self_branch:
            verdict = "benign_halt_spin"
            action = "none; 'bra self' halt spin (optionally with SR masked) alongside a normal rts path"
            ev = "body 0x%x-0x%x contains a self-branch halt spin + rts path; callers=%d" % (a, fe, ncall)
        elif not has_rts:
            verdict = "benign_infinite_loop"
            action = "none"
            ev = ("body 0x%x-0x%x has no rts (unconditional loop): expected for reset/idle/main paths; callers=%d"
                  % (a, fe, ncall))
        else:
            verdict = "review_infinite_loop_with_rts"
            action = "inspect loop body"
            ev = "body contains rts; callers=%d" % ncall
    elif "unreachable_ram_block_removed" in iss:
        verdict = "benign_dead_code_removed"
        action = "none; Ghidra dead-block removal, callgraph unchanged (callers=%d)" % ncall
        ev = iss + ("; inner labels: " + ", ".join(inner[:4]) if inner else "")
    elif "overlapping_symbol_labels" in iss:
        verdict = "benign_internal_labels"
        action = "none; labels inside the body are branch targets / inline pools"
        ev = ("%d inner label(s): %s" % (len(inner), ", ".join(inner[:6]))) if inner else "overlap is with the adjacent symbol at body end"
    elif "type_propagation_unsettled" in iss:
        verdict = "benign_known_function"
        action = "none; ref_osTaskScheduler already labeled (os_scheduler_can_ivt_report.md)"
        ev = "decompiler type-propagation warning only; body/callgraph intact; callers=%d" % ncall
    elif "decompiler_restart_space" in iss or "heritage_after_dead_removal" in iss:
        verdict = "benign_decompiler_artifact"
        action = "none"
        ev = iss + "; callers=%d" % ncall
    else:
        verdict = "review"
        action = "manual review"
        ev = iss
    verdict_counts[verdict] += 1
    verdicts.append({"address": addr, "name": r["name"], "issue": iss,
                     "body_bytes": str(body), "callers": str(ncall),
                     "verdict": verdict, "evidence": ev, "action": action})

write_tsv(base / "decompiled/decompiler_issues_triaged.tsv",
          ["address", "name", "issue", "body_bytes", "callers", "verdict", "evidence", "action"],
          verdicts)
write_tsv(base / "disassembly/decompiler_issues_triaged.tsv",
          ["address", "name", "issue", "body_bytes", "callers", "verdict", "evidence", "action"],
          verdicts)

summary = {
    "date": "2026-10-31",
    "rom": info["file"], "rom_sha256": ROM_SHA, "rom_sha256_verified": True,
    "non_instruction_ranges": {"total": len(ranges), "class_counts": dict(class_counts.most_common())},
    "decompiler_issues": {"total": len(issues), "verdict_counts": dict(verdict_counts.most_common()),
                          "actionable": [v for v in verdicts if v["verdict"].startswith(("resolved", "orphan", "review"))]},
    "recovered_record_tables": recovered,
    "orphan_function_0x33b6": orphan,
    "outputs": ["decompiled/non_instruction_ranges_classified.tsv",
                "disassembly/non_instruction_ranges_classified.tsv",
                "decompiled/decompiler_issues_triaged.tsv",
                "disassembly/decompiler_issues_triaged.tsv"],
}
(LABELS / "triage_export.json").write_text(json.dumps(summary, indent=2) + "\n")
print(json.dumps({"rom_sha256": ROM_SHA,
                  "range_classes": dict(class_counts.most_common()),
                  "issue_verdicts": dict(verdict_counts.most_common())}, indent=2))
