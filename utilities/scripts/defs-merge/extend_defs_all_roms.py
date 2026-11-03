#!/usr/bin/env python3
"""Extend data/definitions/ from 60E15120_N3J1E to every dumped ROM (ROADMAP D item 4).

Read-only on all inputs (binaries/, submodules/, existing data/definitions/ XMLs).
Writes only NEW files:
  - data/definitions/romraider/per-rom/<rom-stem>.xml   (standalone RomRaider def per ROM;
    auto-formatted with ET.indent, 4-space indent, one element per line)
  - data/definitions/coverage.json                      (per-ROM mapping + provenance + validation)

ROM inventory: binaries/dumps/*.bin (our acquisitions, hash-checked against
binaries/manifest.csv) + submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/*.bin
(referenced, never modified). Each ROM is identified by the 8-byte ASCII firmware
ID at file offset 0x2000 and mapped to a <rom> block of the upstream RomRaider
defs submodules/RX8Defs/RomRaider/rx8_defs.xml at the pinned submodule commit.
ROM 60E15120 uses the locally reviewed block from
data/definitions/romraider/rx8defs-merged-60E15120.xml instead of upstream.

ECUFlash defs exist upstream only for 60E0G500 (ECUFlash/60E0G500.xml, 1210 tables);
they are referenced from the submodule, not copied (AGENTS.md rule 4b).

Run from the repo root:  python utilities/scripts/defs-merge/extend_defs_all_roms.py
"""
from pathlib import Path
import copy, csv, hashlib, json, re, struct, subprocess, sys
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import relabel  # 2026-11-02 table relabel pass (shared with relabel_merged_def.py)

DEFS = ROOT / "data" / "definitions"
SUB_RX8DEFS = ROOT / "submodules" / "RX8Defs"
UPSTREAM_RR = SUB_RX8DEFS / "RomRaider" / "rx8_defs.xml"
UPSTREAM_ECUFLASH = SUB_RX8DEFS / "ECUFlash" / "60E0G500.xml"
MERGED_60E15120 = DEFS / "romraider" / "rx8defs-merged-60E15120.xml"
STOCK_ROMS = ROOT / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
OUR_DUMPS = ROOT / "binaries" / "dumps"
OUT_DIR = DEFS / "romraider" / "per-rom"
COVERAGE = DEFS / "coverage.json"
FILESIZE = 0x80000  # 512 KiB SH7055 flash


def git(repo, *args, quiet=False):
    return subprocess.check_output(
        ["git", "-C", str(repo), *args],
        stderr=subprocess.DEVNULL if quiet else None).decode("utf-8-sig").strip()


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def blob(path):  # git blob id with filters (line-ending normalized)
    return git(ROOT, "hash-object", str(path))


def scan_rom(path, source):
    data = path.read_bytes()
    assert len(data) == FILESIZE, f"{path}: size {len(data)} != {FILESIZE}"
    fw = data[0x2000:0x2008].decode("ascii")
    assert re.fullmatch(r"[0-9A-Z]{8}", fw), f"{path}: bad fw id {fw!r}"
    cal = [m.decode("ascii") for m in re.findall(rb"[ -~]{6,}", data[0x6C000:0x6C100])]
    return {
        "file": path.relative_to(ROOT).as_posix(),
        "stem": path.stem,
        "source": source,
        "sha256": sha256(path),
        "fwid": fw,
        "cal_strings": cal,
    }


def blocks(root):
    # case-insensitive xmlid lookup (upstream mixes 'Rx8Base' base attr vs 'RX8Base' xmlid)
    return {x.findtext("romid/xmlid").lower(): x for x in root.findall("rom")}


def base_chain(block, blks):
    chain, seen = [], set()
    cur = block
    while cur is not None and cur.get("base"):
        key = cur.get("base").lower()
        assert key in blks and key not in seen, f"base chain broken at {key}"
        seen.add(key)
        cur = blks[key]
        chain.append(cur)
    return list(reversed(chain))  # RX8Base first


SCALARS_JSON = ROOT / "data" / "maps" / "cross_rom_scalars.json"
SCALAR_ENTRIES = {
    # literal-pool float32 scalars (ROADMAP D11) exposed as editable 1-cell
    # RomRaider "scalar" tables; addresses/values from extract_scalars.py output
    "stoich_afr": {
        "name": "Scalar - Stoich AFR (literal pool)",
        "units": "AFR",
        "description": ("Literal-pool float (stoich AFR 14.7), referenced by a mova in the "
                        "fuel-correction/catalyst model (FUN_0003e560 in 60E15120_N3J1E, PID 0x3c "
                        "path): diag_afr_word_a * fVar4 * 14.7. Converts lambda-domain fueling to AFR. "
                        "NOT the base injection map (that is tbl 0x6ac88 + open-loop target 0x69e9c). "
                        "Editing changes fuel correction + AFR display; this address is inside the "
                        "app-flash checksum range (D3, 0x2000-0x7ffff) - bench-validate before "
                        "flashing (AGENTS.md rule 10). See calibration_extraction_report.md 6a. "
                        "FUEL CHANGE: for a fuel with a different stoich ratio set THIS scalar to the "
                        "new stoich (e.g. 9.76 for E85) AND scale 'Scalar - Fuel Load Scale' by "
                        "14.7/new_stoich; leave the maps alone (they are lambda multipliers). For "
                        "varying ethanol blends use the flex stoich table (0x6C444 in G-ROM_FLEX), "
                        "not a fixed scalar. See data/definitions/README.md 'Literal-pool scalars'."),
    },
    "fuel_load_scale": {
        "name": "Scalar - Fuel Load Scale (literal pool)",
        "units": "mult",
        "description": ("Literal-pool float (0.07196): engine_load x 0.07196 -> "
                        "fuel_load_scale_ffffbed0; the scalar every fuel-volume request scales by "
                        "(0x306e8 in 60E15120_N3J1E). Physical units still candidate. Editing changes "
                        "base fueling; address is inside the checksum range (D3) - bench-validate "
                        "before flashing (rule 10). See calibration_extraction_report.md 6a. "
                        "FUEL CHANGE: this is the scalar that changes OPEN-LOOP injected fuel volume "
                        "(bed0 = load x 0.07196 in the 0x306e8 fuel-volume calc); for a different-"
                        "stoich fuel scale it by 14.7/new_stoich (E85: x1.506 -> ~0.1084) and pair "
                        "with setting 'Scalar - Stoich AFR' to the new stoich. Unit interpretation "
                        "candidate - verify with a wideband that commanded AFR = new stoich at "
                        "lambda=1.0 before driving. See data/definitions/README.md."),
    },
}


def inject_scalar_tables(block, rom_rec):
    """Add literal-pool scalar entries (1D size-1 float tables) for this ROM.

    Addresses come from data/maps/cross_rom_scalars.json (extract_scalars.py);
    each address is asserted against the ROM bytes (f32 decode == expected value).
    Skipped when the block already carries the entry (same name).
    """
    if not SCALARS_JSON.exists():
        return 0
    cross = json.loads(SCALARS_JSON.read_text())
    stem = rom_rec["stem"]
    rom = (ROOT / rom_rec["file"]).read_bytes()
    existing = {t.get("name") for t in block.findall("table")}
    n = 0
    for key, spec in SCALAR_ENTRIES.items():
        entry = cross["scalars"].get(key)
        if not entry:
            continue
        per = entry["per_rom"].get(stem)
        if not per or not per.get("present") or not per.get("addresses"):
            continue
        if spec["name"] in existing:
            continue
        if stem == cross["reference"]:
            addr = int(entry["ref_addrs"][0], 16)
        else:
            addr = int(per["addresses"][0], 16)
        val = struct.unpack(">f", rom[addr:addr + 4])[0]
        assert abs(val - entry["value"]) < 1e-6,             f"{stem} {key}: ROM f32 at {addr:#x} = {val}, expected {entry['value']}"
        t = E.SubElement(block, "table", {
            "name": spec["name"], "category": "Fuel Injection", "type": "1D",
            "storagetype": "float", "endian": "big", "size": "1",
            "storageaddress": f"0x{addr:X}",
        })
        d = E.SubElement(t, "description")
        d.text = (spec["description"] + f" ROM address 0x{addr:x}, value {entry['value']!r} "
                  "(asserted against ROM bytes by this script).")
        E.SubElement(t, "scaling", {"units": spec["units"], "expression": "x",
                                    "to_byte": "x", "format": "0.0000"})
        n += 1
    return n


DTC_PREFIX = b"\x03\x00\x03\x01\x03\x02\x03\x00"  # P0300,P0301,P0302 specials + slot0 P0300
DTC_NAME_RE = re.compile(r"^DTC ([0-9A-Fa-f]{4}) Enable/Disable (#\d)( \[additional site 0x[0-9A-Fa-f]+\])?$")


def dtc_layout(rom):
    """This ROM's DTC layout: (code_start, nslots, enable1_start, codes).

    Anchored on the universal prefix P0300/P0301/P0302 + slot-0 P0300; the code
    table is the BE u16 run ending at the first 0xffff padding slot; the three
    enable/disable blocks (def '#1'/'#2'/'#3') follow the padding run, nslots
    bytes each. Verified per ROM against literal-pool anchors and ROM bytes —
    see docs/investigations/60E15120_N3J1E/dtc_control_report.md section 5 and
    data/dtc/README.md.
    """
    idx = rom.find(DTC_PREFIX)
    assert idx >= 0, "DTC prefix not found in ROM"
    code_start = idx + len(DTC_PREFIX) - 2
    s = 0
    while True:
        v = struct.unpack_from(">H", rom, code_start + 2 * s)[0]
        if v == 0xFFFF or v > 0xF3FF:
            break
        s += 1
        assert s <= 0x200, "DTC code table runaway"
    p = code_start + 2 * s
    while rom[p] == 0xFF and rom[p + 1] == 0xFF:
        p += 2
    nslots = (p - code_start) // 2
    assert nslots > 0
    codes = [struct.unpack_from(">H", rom, code_start + 2 * i)[0] for i in range(nslots)]
    return code_start, nslots, p, codes


def repair_dtc_tables(block, rom_rec):
    """Rebuild this block's 'DTC xxxx Enable/Disable #N' entries from the ROM's own
    DTC layout, so every address maps slot -> the byte the firmware actually reads
    (filter args 1/2 in 0x61450/0x615c6 read blocks #1/#2; #3 is the bitmask read by
    0x5f9b0). Fixes the per-ROM defs that pointed at the code table or were shifted
    (60E0E700 +3, 60E1B900/60E32000_N3M5E, 60E0FB00/60E1D400) and binds #2/#3 where
    only #1 was bound (60E15120, 60E0G500). Evidence: dtc_control_report.md §5."""
    rom = (ROOT / rom_rec["file"]).read_bytes()
    code_start, nslots, e1, codes = dtc_layout(rom)
    # drop existing address-bearing DTC entries in this block, keep their descriptions
    desc = {}
    for t in list(block.findall("table")):
        if DTC_NAME_RE.match(t.get("name") or "") and t.get("storageaddress"):
            d = t.find("description")
            if d is not None and d.text:
                desc[t.get("name")] = d.text
            block.remove(t)
    added = 0
    seen = {}
    for slot, code in enumerate(codes):
        if code == 0xFFFF:
            continue
        cname = f"{code:04X}"
        for n in (1, 2, 3):
            addr = e1 + (n - 1) * nslots + slot
            key = (cname, n)
            seen[key] = seen.get(key, 0) + 1
            if seen[key] == 1:
                name = f"DTC {cname} Enable/Disable #{n}"
            else:  # duplicate code (P0300 occupies slots 0 and 1): distinct editor name
                name = f"DTC {cname} Enable/Disable #{n} [additional site 0x{addr:X}]"
            t = E.SubElement(block, "table", {
                "name": name, "storageaddress": f"0x{addr:X}",
                "category": "DTCs", "type": "1D", "storagetype": "uint8",
                "endian": "big", "expression": "x", "to_byte": "x", "size": "1",
            })
            d = E.SubElement(t, "description")
            d.text = (f"[2026-11-01 DTC repair] Address derived from this ROM's own DTC layout "
                      f"(code table 0x{code_start:X} + 2*slot, enable blocks 0x{e1:X} / "
                      f"0x{e1 + nslots:X} / 0x{e1 + 2 * nslots:X}); slot {slot} = code {cname}. "
                      f"Evidence: docs/investigations/60E15120_N3J1E/dtc_control_report.md section 5.")
            if name in desc:
                d.text = desc[name] + "\n" + d.text
            added += 1
    return {
        "dtc_code_table": f"0x{code_start:X}",
        "dtc_enable_blocks": [f"0x{e1:X}", f"0x{e1 + nslots:X}", f"0x{e1 + 2 * nslots:X}"],
        "dtc_slots_used": sum(1 for c in codes if c != 0xFFFF),
        "dtc_tables_emitted": added,
    }


def validate_block(block, fwid):
    rid = block.find("romid")
    assert rid.findtext("xmlid") == fwid, (rid.findtext("xmlid"), fwid)
    assert int(rid.findtext("internalidaddress"), 16) == 0x2000
    assert rid.findtext("internalidstring") == fwid
    n = 0
    for t in block.findall("table"):  # top-level tables only (axes are nested <table>)
        sa = t.get("storageaddress")
        if sa is not None:
            a = int(sa, 16)
            # 0x000000 = upstream placeholder for an unmapped DTC-enable byte; anything
            # else must land in the 512 KiB flash window (cal area starts at 0x2000).
            assert a == 0 or 0x2000 <= a < FILESIZE, f"{t.get('name')}: storageaddress {sa} out of range"
            if a:
                n += 1
    return n


def main():
    pinned = git(SUB_RX8DEFS, "rev-parse", "HEAD")
    lasttouch_rr = git(SUB_RX8DEFS, "log", "-1", "--format=%H %ad %s", "--date=short", "--", "RomRaider/rx8_defs.xml")
    lasttouch_ef = git(SUB_RX8DEFS, "log", "-1", "--format=%H %ad %s", "--date=short", "--", "ECUFlash/60E0G500.xml")
    up = E.parse(UPSTREAM_RR).getroot()
    ub = blocks(up)
    merged = E.parse(MERGED_60E15120).getroot()
    mb = blocks(merged)

    # manifest hashes for our own dumps
    manifest = {}
    with open(ROOT / "binaries" / "manifest.csv", newline="", encoding="utf-8-sig") as f:
        for row in csv.DictReader(f):
            manifest[row["filename"]] = row["sha256"]

    roms = [scan_rom(p, "binaries/dumps") for p in sorted(OUR_DUMPS.glob("*.bin"))]
    roms += [scan_rom(p, "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs") for p in sorted(STOCK_ROMS.glob("*.bin"))]
    for r in roms:
        if r["source"] == "binaries/dumps":
            want = manifest.get(r["file"].removeprefix("binaries/"))
            assert want == r["sha256"], f"{r['file']}: manifest hash mismatch"

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    ecuflash_tables = len(E.parse(UPSTREAM_ECUFLASH).getroot().findall(".//table"))

    coverage = {
        "generated": "2026-11-01",
        "relabel_pass": "2026-11-02 (utilities/scripts/defs-merge/relabel.py; labels from data/labels/60E15120_N3J1E/defs_table_labels.json; cross-ROM via structural match in data/maps)",
        "roadmap_item": "D item 4",
        "upstream": {
            "repo": "submodules/RX8Defs (equinox311/RX8Defs)",
            "pinned_commit": pinned,
            "romraider_rx8_defs_last_change": lasttouch_rr,
            "ecuflash_60E0G500_last_change": lasttouch_ef,
            "ecuflash_60E0G500_tables": ecuflash_tables,
        },
        "roms": [],
    }

    for r in roms:
        fwid = r["fwid"]
        rec = dict(r)
        if fwid == "60E15120":
            block, blks, origin = mb[fwid.lower()], mb, "reviewed block from data/definitions/romraider/rx8defs-merged-60E15120.xml"
        elif fwid.lower() in ub:
            block, blks, origin = ub[fwid.lower()], ub, f"upstream submodules/RX8Defs/RomRaider/rx8_defs.xml @ {pinned}"
        else:
            block = None
            rec.update({"romraider_block": None, "status": "NO_UPSTREAM_BLOCK",
                        "note": "no <rom> block in upstream rx8_defs.xml" + (
                            " (60E1C500 block exists but is commented out upstream, commit 251f54f)"
                            if fwid == "60E1C500" else "")})
            coverage["roms"].append(rec)
            continue
        chain = base_chain(block, blks)
        # inject into a copy so ROMs sharing one upstream block don't inherit
        # each other's literal addresses
        block = copy.deepcopy(block)
        n_scalars = inject_scalar_tables(block, r)
        dtc_repair = repair_dtc_tables(block, r)
        # 2026-11-02 relabel pass: apply the curated 60E15120 table labels
        # (data/labels/60E15120_N3J1E/defs_table_labels.json) to this ROM's
        # block — direct for 60E15120, cross-ROM structural match otherwise;
        # adds extracted tables that had no editor entry. Names/categories/
        # descriptions only; storageaddresses/axes/scalings untouched.
        relabel_stats = relabel.apply_to_block(block, blks, r["stem"])
        relabel_stats = {k: v for k, v in relabel_stats.items() if k != "details"}
        n_addr = validate_block(block, fwid)
        # emit standalone per-ROM def: base chain + rom block, with provenance comment
        out = E.Element("roms")
        c = E.Comment(
            f" Per-ROM RomRaider def for {r['file']} (SHA-256 {r['sha256'][:16]}..., fw id {fwid} at 0x2000).\n"
            f"    Block source: {origin}. Base chain: "
            + " <- ".join(b.findtext('romid/xmlid') for b in chain) + f" <- {fwid}.\n"
            f"    Generated 2026-11-01 by utilities/scripts/defs-merge/extend_defs_all_roms.py (ROADMAP D item 4);\n"
            f"    table relabel pass 2026-11-02 applied (relabel.py + defs_table_labels.json, cross-ROM structural match).\n"
            f"    ECUFlash def: " + (f"submodules/RX8Defs/ECUFlash/60E0G500.xml @ {pinned} ({ecuflash_tables} tables)" if fwid == "60E0G500" else "none upstream") + " "
        )
        out.append(c)
        for b in chain + [block]:
            out.append(copy.deepcopy(b))
        # auto-format the generated file: one element per line, 4-space indent
        # (matches the splice style of relabel_merged_def.py); ET.indent only
        # touches whitespace-only text/tail, so descriptions and data="..."
        # attribute values are preserved verbatim
        E.indent(out, space="    ")
        out_path = OUT_DIR / f"{r['stem']}.xml"
        E.ElementTree(out).write(out_path, encoding="utf-8", xml_declaration=True)
        # re-parse what we wrote (validation of the artifact, not just the tree)
        back = E.parse(out_path).getroot()
        n_back = len(back.findall("rom")[-1].findall("table"))
        assert len(back.findall("rom")) == len(chain) + 1 and n_back == len(block.findall("table"))
        rec.update({
            "romraider_block": fwid,
            "block_origin": origin,
            "base_chain": [b.findtext("romid/xmlid") for b in chain],
            "block_tables": len(block.findall("table")),
            "scalar_tables_injected": n_scalars,
            "dtc_repair": dtc_repair,
            "relabel_2026-11-02": relabel_stats,
            "block_tables_with_storageaddress": n_addr,
            "per_rom_def": out_path.relative_to(ROOT).as_posix(),
            "ecuflash_def": (f"submodules/RX8Defs/ECUFlash/60E0G500.xml @ {pinned}" if fwid == "60E0G500" else None),
            "status": "OK",
        })
        coverage["roms"].append(rec)

    # D8 dedupe evidence: git-blob identity of our copies vs pinned submodule files
    dedupe = []
    for local, sub in [
        ("ecuflash/60E0G500.xml", "ECUFlash/60E0G500.xml"),
        ("ecuflash/RX8BASE.xml", "ECUFlash/RX8BASE.xml"),
        ("romraider/upstream-rx8defs/logger_rx8_defs.xml", "RomRaider/logger_rx8_defs.xml"),
        ("romraider/reviewed-rx8defs-copy/logger_rx8_defs.xml", "RomRaider/logger_rx8_defs.xml"),
        ("romraider/upstream-rx8defs/rx8_defs.xml", "RomRaider/rx8_defs.xml"),
    ]:
        p = DEFS / local
        if p.exists():
            local_blob, state = blob(p), "present"
        else:
            # deleted under rule 4b; recover the blob from the newest commit whose tree still has the file
            local_blob = state = None
            for cand in git(ROOT, "rev-list", "HEAD", "--", f"data/definitions/{local}").splitlines():
                try:
                    local_blob = git(ROOT, "rev-parse", f"{cand}:data/definitions/{local}", quiet=True)
                    state = f"removed (rule 4b); blob from commit {cand[:12]}"
                    break
                except subprocess.CalledProcessError:
                    continue
            assert local_blob, f"no blob found in history for {local}"
        same = local_blob == git(SUB_RX8DEFS, "rev-parse", f"HEAD:{sub}")
        dedupe.append({
            "local": f"data/definitions/{local}",
            "state": state,
            "local_blob": local_blob,
            "pinned_submodule": f"submodules/RX8Defs/{sub} @ {pinned}",
            "pinned_blob": git(SUB_RX8DEFS, "rev-parse", f"HEAD:{sub}"),
            "blob_identical_to_pinned": same,
            "action": "delete copy, reference submodule (AGENTS.md rule 4b)" if same else "keep, record provenance",
        })
    coverage["dedupe_d8"] = dedupe

    COVERAGE.write_text(json.dumps(coverage, indent=2) + "\n")
    n_ok = sum(1 for r in coverage["roms"] if r["status"] == "OK")
    print(f"ROMs: {len(coverage['roms'])}, with per-ROM def: {n_ok}, gaps: {len(coverage['roms']) - n_ok}")
    for r in coverage["roms"]:
        print(f"  {r['stem']:48s} fw={r['fwid']}  {r['status']:18s} tables={r.get('block_tables')}")
    print(f"wrote {COVERAGE}")


if __name__ == "__main__":
    sys.exit(main())
