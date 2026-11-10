#!/usr/bin/env python3
"""Prove or demote the unverified `candidate_*` function labels (idempotent).

Reads every `candidate_*` name from the export's function_index.tsv, collects
the best recorded confidence for each address from the per-subsystem label
records (data/labels/<rom-id>/*.json and the investigation review JSONs), plus
curated binary-level decisions for the control-path candidates, then:

  1. updates source_review/accepted_function_aliases.tsv: proven labels get
     confidence=high (the export then drops the `candidate_` prefix), the
     misnamed 0x22144 gets a corrected alias while staying medium;
  2. updates the matching per-subsystem label records (knock_loop_labels.json);
  3. writes metadata/candidate_promotions.json with the per-address decision;
  4. with --apply-export, applies the renames to the export itself
     (function_index.tsv, callgraph.tsv, symbols.tsv, functions/*.c,
     firmware_decompiled.c, named/firmware_named.c, integrated_names.json and
     the cross-ROM mode22 TSVs) using errors='surrogateescape' so the
     pre-existing non-UTF8 bytes in tracked files survive byte-exact; a full
     rebuild.sh run re-applies the same renames from the TSV via
     integrate_reviewed_names.py.

Runs after review_dtc_thunk_labels.py and before annotate_source_review.py in
rebuild.sh. The raw ROM is never written; its SHA-256 is asserted unchanged.
"""
from pathlib import Path
import csv, hashlib, json, re, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py)

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

# Curated binary-level decisions for the control-path candidates (re-verified
# against the raw ROM / disassembly / callgraph in this pass's review doc).
PROMOTE_EXTRA = {
    "000064ba": ("knock_sensor_fault_task",
        "ROM task-table record at 0x4a28 holds u32 0x000064ba (ROM-verified); body jsr chain via pools 0x655c-0x6570 = 0xd21e, 0x6842, 0x94fc, 0xc290 ref_knockSensorADCFault, 0x1150e, tail jmp 0x3d58 ref_taskEndRoutine_ (pool words ROM-verified); byte-exact function match in 10/10 other ROMs (cross_rom_function_matches.tsv). Scheduled fault-service task whose knock-specific step is 0xc290."),
    "000390b8": ("knock_sensor_monitor_task",
        "ROM pointer at 0x11978 = 0x000390b8 (ROM-verified); caller 0x11744 in the task chain (callgraph); callees 0x4a084 knock_sensor_dtc_report + 0x49fac knock_sensor_health_persistence; byte-exact match in 3/10 other ROMs (cross_rom_function_matches.tsv)."),
    "000145c8": ("timing_retard_fast_task",
        "ROM pointer at 0x116e0 = 0x000145c8 (ROM-verified); caller 0x11534 slow-background wrapper; callees include 0x1391c ref_calcKnockRAMUpdate_, 0x13b40 knock_retard_slow_recovery, 0x214f8/0x215f8 AC-compressor leading/trailing timing retards, throttle/liftoff plausibility checks (callgraph)."),
    "0001467c": ("knock_rough_correction_update",
        "ROM pointer at 0x11a84 = 0x0001467c (ROM-verified); caller 0x118d0; callees 0x13034 knock_rough_correction_targets + 0x13210 ref_roughKnockCorrection (callgraph)."),
    "0003d010": ("o2_monitor_integrator",
        "Body: integrator DAT_ffffc5ec decays by mass_air_flow_ffffa9ec*0.1 clamped >= 0 (rx8_max_float 0x23e4), loaded from tbl 0x6b61c vs catalyst-temp model 0xffffa998; countdowns c5f8/c5fa gated by vehicle_speed_ffffbbb4 > 95.88; callers 0x3ccec (sets tolerance bounds c5f0=-40.0/c5f4=200.0) and 0x3cd06 (out-of-tolerance sets c5fc/c5fd); literal pools 0x3d0c4-0x3d0ec ROM-verified."),
}
RENAME = {
    # address: (new alias, evidence) -- stays medium, so keeps the candidate_ prefix
    "00022144": ("fuel_open_loop_condition",
        "Body (200 B): DAT_ffffb319 = 1 iff DAT_ffffb318==1 && open_loop_active_ffffb12c==1 && DAT_ffffbe00 >= 66.5 && closed_loop_active_ffffae1f==0 && DAT_ffffb2f6/b0c8/b0c9 clear; pools 0x22218/0x2221c/0x22220 ROM-verified. The gate uses the fuel open-loop flag (high label open_loop_active_ffffb12c, set by set_open_loop_flag 0x1ee30), so the 'evap' attribution inherited from caller ref_evapRelated 0x21b8a (a ref_ hypothesis) is doubtful: renamed to fuel_open_loop_condition, stays candidate_ until the EVAP-chain attribution is proven."),
}

HEX = re.compile(r"^[0-9a-f]{8}$")


def norm(k):
    k = str(k).lower()
    if k.startswith("0x"):
        k = k[2:]
    return k.zfill(8) if re.fullmatch(r"[0-9a-f]+", k) else None


def read_rows(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as f:
        rdr = csv.DictReader(f, delimiter="\t")
        fields = list(rdr.fieldnames or [])
        rows = [{k: (v if v is not None else "") for k, v in r.items()} for r in rdr]
    return fields, rows


def write_rows(path, fields, rows):
    # preserve the file's existing line ending (export TSVs are CRLF, label TSVs LF)
    raw = path.read_bytes()[:4096]
    term = "\r\n" if b"\r\n" in raw else "\n"
    with path.open("w", newline="", encoding="utf-8", errors="surrogateescape") as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter="\t", lineterminator=term)
        w.writeheader()
        w.writerows(rows)


def collect_evidence(cand):
    """Best (confidence, sources, alias, evidence) per candidate address from all label JSONs."""
    ev = {a: [] for a in cand}

    def walk(obj, src, path):
        if isinstance(obj, dict):
            for k, v in obj.items():
                nk = norm(k)
                if nk in cand and isinstance(v, dict) and "confidence" in v:
                    ev[nk].append((v.get("confidence"), src + path, v.get("alias"), v.get("evidence") or ""))
                else:
                    walk(v, src, path + "/" + str(k)[:60])
        elif isinstance(obj, list):
            for i, v in enumerate(obj):
                if isinstance(v, dict):
                    a = norm(v.get("address", ""))
                    if a in cand and "confidence" in v:
                        ev[a].append((v.get("confidence"), src + path + f"[{i}]", v.get("alias"), v.get("evidence") or ""))
                walk(v, src, path + f"[{i}]")

    label_dir = ROOT / "data" / "labels" / "60E15120_N3J1E"
    inv_dir = ROOT / "docs" / "investigations" / "60E15120_N3J1E"
    for fn in sorted(label_dir.glob("*.json")) + sorted(inv_dir.rglob("*.json")):
        try:
            d = json.loads(fn.read_text(encoding="utf-8", errors="replace"))
        except Exception:
            continue
        src = fn.relative_to(ROOT).as_posix()
        walk(d, src, "")
    return ev


def main():
    apply_export = "--apply-export" in sys.argv
    rom = rom_file().read_bytes()
    assert hashlib.sha256(rom).hexdigest() == ROM_SHA256, "ROM hash changed - refusing to run"

    idx_fields, idx = read_rows(b / "decompiled/function_index.tsv")
    cand = {}
    for r in idx:
        if r["name"].startswith("candidate_"):
            cand[r["address"]] = r["name"]

    # Idempotency: if a previous run already decided the full candidate set, reuse
    # those decisions verbatim (the export may already carry the new names, so the
    # current function_index no longer lists the promoted candidates).
    record_path = b / "metadata/candidate_promotions.json"
    prev = None
    if record_path.exists():
        try:
            prev = json.loads(record_path.read_text(encoding="utf-8"))
        except Exception:
            prev = None

    ev = collect_evidence(cand)
    rank = {"high": 3, "medium": 2, "low": 1}
    promoted, kept = {}, {}
    if prev and prev.get("promoted_to_high"):
        for a, p in prev["promoted_to_high"].items():
            promoted[a] = {"alias": p["alias"], "name": "candidate_" + p["alias"],
                           "source": p["source"], "evidence": ""}
        renamed = {a: {"old": r["old"], "new": r["new"], "evidence": r.get("evidence", "")}
                   for a, r in prev.get("renamed_staying_medium", {}).items()}
        for a, name in prev.get("kept_candidate", {}).items():
            kept[a] = name
        total = prev["counts"]["candidate_total"]
    else:
        renamed = {}
        for a, (alias, evidence) in RENAME.items():
            renamed[a] = {"old": cand[a], "new": "candidate_" + alias, "evidence": evidence}
        total = len(cand)
        for a, name in cand.items():
            entries = ev[a]
            best = max((e[0] for e in entries), key=lambda c: rank.get(c, 0)) if entries else None
            if a in PROMOTE_EXTRA:
                alias, evidence = PROMOTE_EXTRA[a]
                promoted[a] = {"alias": alias, "name": name, "source": "binary-level re-verification (this pass)", "evidence": evidence}
            elif best == "high":
                srcs = sorted({e[1] for e in entries if e[0] == "high"})
                alias = next((e[2] for e in entries if e[0] == "high" and e[2]), name[len("candidate_"):])
                promoted[a] = {"alias": alias, "name": name, "source": "; ".join(srcs),
                               "evidence": "high-confidence label record (dynamic emulator proof and/or cross-ROM byte matches)"}
            elif a not in RENAME:
                kept[a] = name

    # 1. accepted_function_aliases.tsv
    tsv = b / "source_review/accepted_function_aliases.tsv"
    fields, rows = read_rows(tsv)
    changed = 0
    for r in rows:
        a = r["address"]
        if a in promoted and r["confidence"] != "high":
            p = promoted[a]
            r["confidence"] = "high"
            note = f"promoted to high ({p['source']})"
            if note not in r["evidence"]:
                r["evidence"] = (r["evidence"] + " | " + note) if r["evidence"] else note
            changed += 1
        elif a in renamed and r["alias"] != renamed[a]["new"][len("candidate_"):]:
            r["alias"] = renamed[a]["new"][len("candidate_"):]
            note = "renamed: " + renamed[a]["evidence"][:200]
            if note[:40] not in r["evidence"]:
                r["evidence"] = (r["evidence"] + " | " + note) if r["evidence"] else note
            changed += 1
    write_rows(tsv, fields, rows)

    # 2. knock_loop_labels.json records for the curated control-path labels
    #    (targeted block replacement to preserve the file's exact formatting)
    kl = b / "metadata/knock_loop_labels.json"
    text = kl.read_text(encoding="utf-8", errors="surrogateescape")
    kld = json.loads(text)

    def entry_block(key, entry):
        inner = ",\n".join(f'  "{k}": {json.dumps(v, ensure_ascii=True)}' for k, v in entry.items())
        return f' "{key}": {{\n{inner}\n }}'

    for a, (alias, evidence) in PROMOTE_EXTRA.items():
        key = next((k for k in kld["function_aliases"] if norm(k) == a), a)
        entry = {"alias": alias, "confidence": "high", "evidence": evidence}
        pat = re.compile(r' "' + re.escape(key) + r'": \{[^{}]*\}(,?)', re.S)
        assert pat.search(text), key
        text = pat.sub(entry_block(key, entry) + r"\1", text, count=1)
    for a, (alias, evidence) in RENAME.items():
        key = next((k for k in kld["function_aliases"] if norm(k) == a), a)
        entry = {"alias": alias, "confidence": "medium", "evidence": evidence}
        pat = re.compile(r' "' + re.escape(key) + r'": \{[^{}]*\}(,?)', re.S)
        assert pat.search(text), key
        text = pat.sub(entry_block(key, entry) + r"\1", text, count=1)
    # rom_unchanged flag, single-line targeted edit
    if '"rom_unchanged"' in text:
        text = re.sub(r'"rom_unchanged":\s*(true|false)', '"rom_unchanged": true', text, count=1)
    kl.write_text(text, encoding="utf-8", errors="surrogateescape")

    # 3. record
    record = {
        "pass": "candidate_label_promotions",
        "rom": "60E15120_N3J1E",
        "rom_sha256": ROM_SHA256,
        "rom_unchanged": True,
        "candidate_total": total,
        "promoted_to_high": {a: {"alias": p["alias"], "name": p["name"], "source": p["source"]} for a, p in sorted(promoted.items())},
        "renamed_staying_medium": renamed,
        "kept_candidate": {a: kept[a] for a in sorted(kept)},
        "counts": {"candidate_total": total, "promoted": len(promoted), "renamed": len(renamed), "kept_candidate": len(kept)},
        "export_applied_by": "review_candidate_promotions.py --apply-export (scoped surrogateescape pass)" if apply_export else "pending: integrate_reviewed_names.py on full rebuild",
        "ghidra_database_updated": False,
    }
    (b / "metadata/candidate_promotions.json").write_text(json.dumps(record, indent=1, ensure_ascii=True) + "\n", encoding="utf-8")

    # 4. export application
    name_map = {}
    for a, p in promoted.items():
        name_map[p["name"]] = p["alias"]
    for a, rn in renamed.items():
        name_map[rn["old"]] = rn["new"]
    name_map = {k: v for k, v in name_map.items() if k != v}

    if apply_export:
        pattern = re.compile(r"\b(?:" + "|".join(re.escape(k) for k in sorted(name_map, key=len, reverse=True)) + r")\b")

        def transform(s):
            parts = re.split(r"(/\*.*?\*/|//[^\n]*)", s, flags=re.S)
            for i in range(0, len(parts), 2):
                parts[i] = pattern.sub(lambda m: name_map[m[0]], parts[i])
            return "".join(parts)

        enc = dict(encoding="utf-8", errors="surrogateescape")
        addr_by_name = {p["name"]: a for a, p in promoted.items()}
        addr_by_name.update({rn["old"]: a for a, rn in renamed.items()})

        # export TSVs: byte-level name replacement (preserves the Ghidra-export
        # CRCRLF line endings and any quoting byte-exactly; the candidate_ names
        # are unique identifier tokens that occur only in the name columns)
        for rel in ("decompiled/function_index.tsv", "decompiled/callgraph.tsv", "decompiled/symbols.tsv"):
            p = b / rel
            data = p.read_bytes()
            for old, new in name_map.items():
                data = data.replace(old.encode(), new.encode())
            p.write_bytes(data)

        # function bodies + monoliths
        changed_files = 0
        for p in (b / "decompiled/functions").glob("*.c"):
            old = p.read_text(**enc)
            new = transform(old)
            if new != old:
                p.write_text(new, **enc)
                changed_files += 1
        for p in (b / "decompiled/firmware_decompiled.c", b / "named/firmware_named.c"):
            old = p.read_text(**enc)
            new = transform(old)
            if "[INTEGRATED REVIEWED NAMES]" not in new:
                new = "/* [INTEGRATED REVIEWED NAMES]\n * Canonical analysis C includes wiring, Denso, RX8Defs, G-ROM and CAN reviews.\n * inferred_ and candidate_ names remain hypotheses; address suffixes preserve identity.\n * Provenance comments retain historical symbols. This is not buildable firmware.\n * Saved Ghidra database has not been updated; see metadata/integrated_names.json.\n */\n" + new
            p.write_text(new, **enc)

        # per-function bodies must define the new name
        fields, rows = read_rows(b / "decompiled/function_index.tsv")
        for r in rows:
            if r["address"] in addr_by_name:
                body = (b / "decompiled" / r["file"]).read_text(**enc)
                assert re.search(r"\b" + re.escape(r["name"]) + r"\s*\(", body), r["address"]

        # integrated_names.json manifest
        manifest = b / "metadata/integrated_names.json"
        md = json.loads(manifest.read_text(encoding="utf-8", errors="replace"))
        md["identifier_map"].update(name_map)
        manifest.write_text(json.dumps(md, indent=2, ensure_ascii=True) + "\n", encoding="utf-8")

        # cross-ROM mode22 TSVs (base_function_name column): byte-level replacement
        for tsv_path in [ROOT / "data/labels/cross_rom_mode22_pid_handlers.tsv"] + sorted((ROOT / "data/labels/cross_rom/mode22").glob("*.tsv")):
            data = tsv_path.read_bytes()
            new_data = data
            for old, new in name_map.items():
                new_data = new_data.replace(old.encode(), new.encode())
            if new_data != data:
                tsv_path.write_bytes(new_data)

    print(json.dumps({
        "candidate_total": total,
        "promoted": len(promoted),
        "renamed": len(renamed),
        "kept_candidate": len(kept),
        "tsv_rows_changed": changed,
        "export_applied": apply_export,
    }, indent=2))


if __name__ == "__main__":
    main()
