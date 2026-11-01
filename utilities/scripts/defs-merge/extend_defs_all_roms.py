#!/usr/bin/env python3
"""Extend data/definitions/ from 60E15120_N3J1E to every dumped ROM (ROADMAP D item 4).

Read-only on all inputs (binaries/, submodules/, existing data/definitions/ XMLs).
Writes only NEW files:
  - data/definitions/romraider/per-rom/<rom-stem>.xml   (standalone RomRaider def per ROM)
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
import copy, csv, hashlib, json, re, subprocess, sys
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
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
        n_addr = validate_block(block, fwid)
        # emit standalone per-ROM def: base chain + rom block, with provenance comment
        out = E.Element("roms")
        c = E.Comment(
            f" Per-ROM RomRaider def for {r['file']} (SHA-256 {r['sha256'][:16]}..., fw id {fwid} at 0x2000).\n"
            f"    Block source: {origin}. Base chain: "
            + " <- ".join(b.findtext('romid/xmlid') for b in chain) + f" <- {fwid}.\n"
            f"    Generated 2026-11-01 by utilities/scripts/defs-merge/extend_defs_all_roms.py (ROADMAP D item 4).\n"
            f"    ECUFlash def: " + (f"submodules/RX8Defs/ECUFlash/60E0G500.xml @ {pinned} ({ecuflash_tables} tables)" if fwid == "60E0G500" else "none upstream") + " "
        )
        out.append(c)
        for b in chain + [block]:
            out.append(copy.deepcopy(b))
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
