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

Stock-only defs (2026-11-03): the G-ROM_FLEX-only 'Flex Fuel' category tables that the
RX8Base chain hands to every <rom> (incl. 'Table 2D - Stoich Fuel Ratio' @0x6C444) are
stripped from every emitted def — all dumped ROMs are stock and 0x6C444 is tbl_068f94
data in them (calibration_extraction_report.md 6a). Policy + provenance:
data/definitions/README.md 'Stock-only defs'.

Editor-facing descriptions (2026-11-03, AGENTS.md rule 6b): the rule-6b cleaning
below (clean_description/clean_block, inlined from the one-time 2026-11-03 pass)
strips provenance (addresses, pass markers, evidence/report links, generator
assertions like "asserted against ROM bytes by this script", checksum/rule-10
notes) from every <description> at generation, keeping only the plain
what-the-table-does text — so no separate post-generation cleanup pass is needed.

Run from the repo root:  python utilities/scripts/defs-merge/extend_defs_all_roms.py
"""
from pathlib import Path
import copy, csv, hashlib, json, re, struct, subprocess, sys
import xml.etree.ElementTree as E

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import relabel  # 2026-11-02 table relabel pass (shared with relabel_merged_def.py)
import dtc_names  # 2026-11-03 DTC P-code table names (data/dtc/pcodes.tsv)

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


# Stock-only defs policy (2026-11-03, data/definitions/README.md 'Stock-only defs'):
# the 'Flex Fuel' category tables live in the RX8Base block and are inherited by every
# <rom>, but they exist only in G-ROM_FLEX — all dumped ROMs are stock (single 14.7
# stoich literal each, no ethanol-indexed 1/AFR table; 0x6C444 is tbl_068f94 data in
# stock ROMs — calibration_extraction_report.md 6a flex-fuel cross-check).
FLEX_CATEGORY = "Flex Fuel"


def strip_flex_tables(block):
    """Remove upstream 'Flex Fuel' category tables from a <rom> block; returns count."""
    n = 0
    for t in list(block.findall("table")):
        if t.get("category") == FLEX_CATEGORY:
            block.remove(t)
            n += 1
    return n


# Rule 6b description cleaning (2026-11-03). A <description> is user-facing text:
# a simplified what-the-table-does sentence only. It must not carry memory
# addresses, derivation, pass markers, evidence/report references, checksum or
# bench-validation (rule-10) process notes, or generator assertions ("asserted
# against ROM bytes by this script"). Provenance lives in the label map
# (data/labels/60E15120_N3J1E/defs_table_labels.json), TSVs and investigation
# docs, not in the XML the end user reads. Inlined from the one-time 2026-11-03
# cleanup pass so generation emits clean editor text directly.
LEGACY_DTC_NAME_RE = re.compile(r"^DTC ([0-9A-Fa-f]{4}) Enable/Disable (#\d)")

# bracketed blocks that are provenance: dated markers, JSON dumps, process keywords
BRACKET_RE = re.compile(r"\[[^\]]*\]")
BRACKET_BAD_RE = re.compile(r"20\d\d-\d\d-\d\d|\{|^\s*\[(?:analysis|review|repair|correction|dtc)\b", re.I)

# sentences containing any of these are provenance, not what-the-table-does
BAD_SENTENCE_RE = re.compile(
    r"0x[0-9a-fA-F]+"                          # memory addresses
    r"|\b(?=[0-9a-f]*\d)[0-9a-fA-F]{5,8}\b"     # bare hex ids with a digit (6a354, 0000e910)
    r"|\bdescriptors?\b|\bdispatch\b|\bcorrespondence\b|\bevidence\b|\basserted\b"
    r"|rom address|by this script|\bfun_\b|\bmova\b|\bpid\b|rule 10"
    r"|bench|checksum|\bcvn\b|verified against|referencing function|lookup path"
    r"|\.md\b|\.json\b|\.tsv\b|\breport\b|\bsee \b|g-rom|literal|extract"
    r"|community definition|consult|not independently|address derived"
    r"|code table|enable block|this rom|slot \d|correction:|\bbasis\b"
    r"|storage|axis pointer|raw_|wrapper|20\d\d-\d\d-\d\d"
    r"|upstream rename|prior name|puvar\d*|rpm-indexed|do not infer"
    r"|axis labels? inferred|inferred from",
    re.I)


def _legacy_dtc_description(code, block_no):
    """Short user-facing description for a legacy 'DTC xxxx Enable/Disable #N' name."""
    return f"Enable/disable flag for diagnostic trouble code DTC {code} (block {block_no})."


def clean_description(text, name=""):
    """Return cleaned description text, or None if nothing user-facing remains.

    Idempotent: already-clean text (incl. the relabel pass's label-map
    descriptions and the P-code DTC descriptions from dtc_names) is returned
    unchanged.
    """
    m = LEGACY_DTC_NAME_RE.match(name or "")
    if m:
        return _legacy_dtc_description(m.group(1).upper(), m.group(2))
    if not text or not text.strip():
        return None
    t = BRACKET_RE.sub(lambda mo: " " if BRACKET_BAD_RE.search(mo.group(0)) else mo.group(0), text)
    parts = re.split(r"\n+|(?<=[.!?])\s+", t)
    keep = [p.strip() for p in parts if p.strip() and not BAD_SENTENCE_RE.search(p)]
    out = re.sub(r"\s+", " ", " ".join(keep)).strip()
    return out or None


def clean_block(block):
    """Clean every <description> under a <rom> block (rule 6b); returns the
    number of descriptions changed or removed."""
    n = 0
    for t in block.iter("table"):
        d = t.find("description")
        if d is None:
            continue
        cleaned = clean_description(d.text or "", t.get("name") or "")
        if cleaned is None:
            if (d.text or "").strip():
                t.remove(d)
                n += 1
        elif cleaned != d.text:
            d.text = cleaned
            n += 1
    return n


SCALARS_JSON = ROOT / "data" / "maps" / "cross_rom_scalars.json"
SCALAR_ENTRIES = {
    # literal-pool float32 scalars (ROADMAP D11) exposed as editable 1-cell
    # RomRaider "scalar" tables; addresses/values from extract_scalars.py output
    # rule 6b: editor-facing text only — what the scalar does and how to retune
    # for another fuel; addresses/provenance/checksum notes stay out of the XML
    "stoich_afr": {
        "name": "Scalar - Stoich AFR (literal pool)",
        "units": "AFR",
        "description": ("Stoichiometric air-fuel ratio (14.7 = gasoline); converts lambda to AFR "
                        "in the fuel-correction/AFR display. For a different-stoich fuel set this "
                        "to the new stoich (e.g. 9.76 for E85) and scale 'Scalar - Fuel Load Scale' "
                        "by 14.7/new stoich. Stock ROMs have no ethanol-indexed stoich table - this "
                        "fixed scalar is the only stoich constant."),
    },
    "fuel_load_scale": {
        "name": "Scalar - Fuel Load Scale (literal pool)",
        "units": "mult",
        "description": ("Scales engine load into the base injected fuel volume; editing changes "
                        "open-loop fueling. For a different-stoich fuel scale it by 14.7/new stoich "
                        "(E85: x1.506), paired with setting 'Scalar - Stoich AFR' to the new stoich."),
    },
    # meanings pinned by the source-review comments and the subsystem reports
    # (cross_rom_scalars.json evidence); same rule-6b editor text policy
    "load_cell_scale": {
        "name": "Scalar - Load Cell Scale (literal pool)",
        "units": "mult",
        "description": ("Converts air per revolution (g/rev) into the engine-load cell units used "
                        "by the fuel and ignition maps (1/(engine displacement x air density))."),
    },
    "air_per_rev_factor": {
        "name": "Scalar - Air Per Rev Factor (literal pool)",
        "units": "mult",
        "description": ("Seconds-per-minute factor in the air-per-revolution calculation "
                        "(air flow in g/s to g/rev)."),
    },
    "air_per_rev_clamp": {
        "name": "Scalar - Air Per Rev Clamp (literal pool)",
        "units": "g/rev",
        "description": "Upper clamp of the computed air per revolution (g/rev).",
    },
    "kelvin_offset": {
        "name": "Scalar - Kelvin Offset (literal pool)",
        "units": "K",
        "description": "Celsius-to-Kelvin offset used in the intake-air density model.",
    },
    "kelvin_ref": {
        "name": "Scalar - Kelvin Reference (literal pool)",
        "units": "K",
        "description": "Reference temperature in the intake-air density ratio (20 C reference).",
    },
    "std_atm_kpa": {
        "name": "Scalar - Standard Atmosphere kPa (literal pool)",
        "units": "kPa",
        "description": "Standard-atmosphere pressure used to normalize barometric pressure.",
    },
    "baro_scale_kpa": {
        "name": "Scalar - Baro ADC Scale kPa (literal pool)",
        "units": "kPa/count",
        "description": "Barometric-pressure sensor ADC counts to kPa scale.",
    },
    "maf_adc_scale": {
        "name": "Scalar - ADC Volt Scale (literal pool)",
        "units": "V/count",
        "description": ("Analog sensor ADC counts to volts scale (raw x 5/65536); used by the MAF, "
                        "throttle and knock sensor inputs."),
    },
    "blend_weight_decay": {
        "name": "Scalar - Fuel Blend Decay (literal pool)",
        "units": "mult/call",
        "description": "Per-call decay of the open-loop/closed-loop fueling blend weight.",
    },
    "pid0043_load_scale": {
        "name": "Scalar - Diag Engine Load Scale (literal pool)",
        "units": "mult",
        "description": "Scale applied to engine load in the diagnostic engine-load report (x 1/255).",
    },
    "injector_flow_primary_cc_min": {
        "name": "Scalar - Primary Injector Flow cc/min (literal pool)",
        "units": "cc/min",
        "description": ("Primary injector flow rating used for the injector pulse-width math; "
                        "change it when fitting different primary injectors."),
    },
    "injector_flow_secondary_cc_min": {
        "name": "Scalar - Secondary Injector Flow cc/min (literal pool)",
        "units": "cc/min",
        "description": ("Secondary injector flow rating used for the injector pulse-width math; "
                        "change it when fitting different secondary injectors."),
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
        # rule 6b: user-facing text only — the ROM-bytes assertion above stays in
        # code, not in the description the end user reads
        d.text = spec["description"]
        E.SubElement(t, "scaling", {"units": spec["units"], "expression": "x",
                                    "to_byte": "x", "format": "0.0000"})
        n += 1
    return n


DTC_PREFIX = b"\x03\x00\x03\x01\x03\x02\x03\x00"  # P0300,P0301,P0302 specials + slot0 P0300
# matches legacy "DTC 0420 ..." and relabeled "DTC P0420 ..." names alike
DTC_NAME_RE = dtc_names.DTC_NAME_RE


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
    only #1 was bound (60E15120, 60E0G500). Names carry the standard 5-char OBD code
    ("DTC P0420 Enable/Disable #1", decode in dtc_names.py; mapping data/dtc/pcodes.tsv).
    Evidence: dtc_control_report.md §5."""
    rom = (ROOT / rom_rec["file"]).read_bytes()
    code_start, nslots, e1, codes = dtc_layout(rom)
    # drop existing address-bearing DTC entries in this block (either naming
    # form); they are re-added below from the ROM layout with P-code names
    for t in list(block.findall("table")):
        if dtc_names.parse_dtc_name(t.get("name")) and t.get("storageaddress"):
            block.remove(t)
    added = 0
    seen = {}
    for slot, code in enumerate(codes):
        if code == 0xFFFF:
            continue
        for n in (1, 2, 3):
            addr = e1 + (n - 1) * nslots + slot
            key = (code, n)
            seen[key] = seen.get(key, 0) + 1
            # duplicate code (P0300 occupies slots 0 and 1): distinct editor name
            dup = addr if seen[key] > 1 else None
            name = dtc_names.dtc_table_name(code, f"#{n}", dup)
            t = E.SubElement(block, "table", {
                "name": name, "storageaddress": f"0x{addr:X}",
                "category": "DTCs", "type": "1D", "storagetype": "uint8",
                "endian": "big", "expression": "x", "to_byte": "x", "size": "1",
            })
            # short editor-facing description (AGENTS.md rule 6b); address/slot
            # provenance stays in data/dtc/<rom>.tsv and dtc_control_report.md §5
            d = E.SubElement(t, "description")
            d.text = dtc_names.dtc_description(code, f"#{n}")
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
        "stock_only_defs": "2026-11-03: G-ROM_FLEX-only 'Flex Fuel' base tables stripped from every per-ROM def (incl. 'Table 2D - Stoich Fuel Ratio' @0x6C444); see data/definitions/README.md 'Stock-only defs'",
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
        # work on copies so ROMs sharing one upstream block don't inherit
        # each other's literal addresses (and the shared parse tree stays intact)
        chain = [copy.deepcopy(b) for b in chain]
        block = copy.deepcopy(block)
        # stock-only defs (2026-11-03): drop the G-ROM_FLEX-only 'Flex Fuel' tables
        # inherited through the base chain — wrong addresses for every stock ROM
        # (data/definitions/README.md 'Stock-only defs')
        for b in chain:
            strip_flex_tables(b)
        strip_flex_tables(block)
        n_scalars = inject_scalar_tables(block, r)
        dtc_repair = repair_dtc_tables(block, r)
        # 2026-11-02 relabel pass: apply the curated 60E15120 table labels
        # (data/labels/60E15120_N3J1E/defs_table_labels.json) to this ROM's
        # block — direct for 60E15120, cross-ROM structural match otherwise;
        # adds extracted tables that had no editor entry. Names/categories/
        # descriptions only; storageaddresses/axes/scalings untouched.
        relabel_stats = relabel.apply_to_block(block, blks, r["stem"])
        # 2026-11-03 rule 6b pass: strip provenance (addresses, pass markers,
        # evidence links, generator assertions) from every remaining description;
        # already-clean relabel descriptions pass through unchanged
        for b in chain:
            clean_block(b)
        clean_block(block)
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
            f"    Stock-only def (2026-11-03): G-ROM_FLEX-only 'Flex Fuel' base tables stripped at generation (incl. 'Table 2D - Stoich Fuel Ratio' @0x6C444);\n"
            f"    descriptions cleaned per AGENTS.md rule 6b at generation — no addresses/provenance in editor text.\n"
            f"    see data/definitions/README.md 'Stock-only defs'.\n"
            f"    ECUFlash def: " + (f"submodules/RX8Defs/ECUFlash/60E0G500.xml @ {pinned} ({ecuflash_tables} tables)" if fwid == "60E0G500" else "none upstream") + " "
        )
        out.append(c)
        for b in chain + [block]:  # already private copies
            out.append(b)
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
            "stock_only_flex_strip": "2026-11-03: G-ROM_FLEX-only 'Flex Fuel' base tables removed from the base chain (see data/definitions/README.md 'Stock-only defs')",
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
