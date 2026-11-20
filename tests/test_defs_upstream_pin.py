#!/usr/bin/env python3
"""Tests for the RX8Defs pin-move audit (utilities/scripts/defs-merge/
upstream_pin_audit.py) and the upstream snapshot re-pin
(utilities/scripts/defs-merge/repin_upstream_snapshot.py) at the pinned
submodule commit (gitlink of submodules/RX8Defs, currently d4140dc).

Invariants checked against the artifacts on disk:

  * the submodule HEAD equals the committed gitlink and coverage.json's
    pinned_commit;
  * the audit is idempotent: re-running it leaves upstream_changes.json,
    axis_conflicts.json, inheritance_issues.json and the per-pin audit record
    byte-identical (AGENTS.md rule 6d regeneration-test pattern);
  * the window records appended to upstream_changes.json are tagged with the
    window and the legacy (untagged) merge-review records are all still there;
  * the re-pin script is a no-op on an already re-pinned snapshot (--check
    exit 0) and the snapshot differs from the pinned upstream blob only by
    the stock-only flex-fuel strip;
  * the splice pass has a per-pin record (upstream_splice_<pin>.json);
  * the regenerated per-ROM defs carry the upstream-renamed table names at the
    new pin, and the duplicate overrides upstream removed are absent (their
    addresses are not lookup data in the ROM extraction);
  * the curated label map does not name any table the pin renamed (the audit's
    label_map_check is empty), so no label aliasing is needed.
"""

import json
import subprocess
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
DEFS_MERGE = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "defs-merge"
DEFS = REPO / "data" / "definitions"
SUB = REPO / "submodules" / "RX8Defs"

AUDIT = REPO / "utilities" / "scripts" / "defs-merge" / "upstream_pin_audit.py"
REPIN = REPO / "utilities" / "scripts" / "defs-merge" / "repin_upstream_snapshot.py"


def git(repo, *args):
    return subprocess.check_output(["git", "-C", str(repo), *args]).decode("utf-8-sig").strip()


@pytest.fixture(scope="module")
def pin():
    head = git(SUB, "rev-parse", "HEAD")
    gitlink = git(REPO, "ls-tree", "HEAD", "submodules/RX8Defs").split()[2]
    assert head == gitlink, "submodule HEAD must equal the committed gitlink"
    return head


@pytest.fixture(scope="module")
def short(pin):
    return git(SUB, "rev-parse", "--short=7", "HEAD")


def audit_json(short):
    return json.loads((DEFS_MERGE / f"upstream_pin_audit_{short}.json").read_text(encoding="utf-8"))


def test_coverage_json_pinned_commit_matches_gitlink(pin):
    cov = json.loads((DEFS / "coverage.json").read_text(encoding="utf-8"))
    assert cov["upstream"]["pinned_commit"] == pin


def test_audit_idempotent_on_committed_records(pin, short):
    """Rule 6d: re-running the audit generator must not drift the committed
    records."""
    files = [
        DEFS_MERGE / "upstream_changes.json",
        DEFS_MERGE / "axis_conflicts.json",
        DEFS_MERGE / "inheritance_issues.json",
        DEFS_MERGE / f"upstream_pin_audit_{short}.json",
    ]
    before = {f: f.read_bytes() for f in files}
    subprocess.run([sys.executable, str(AUDIT.relative_to(REPO))], cwd=REPO, check=True, capture_output=True)
    for f, b in before.items():
        assert f.read_bytes() == b, f"{f.name}: audit not idempotent"


def test_upstream_changes_window_records_and_legacy_intact(short):
    data = json.loads((DEFS_MERGE / "upstream_changes.json").read_text(encoding="utf-8"))
    legacy = [r for r in data if "window" not in r]
    window = [r for r in data if r.get("window", "").endswith(short)]
    assert len(legacy) >= 7432, "legacy merge-review window records must stay untouched"
    assert window, "no window records for the current pin"
    kinds = {r["kind"] for r in window}
    assert kinds <= {"renamed", "category_moved", "removed_duplicate", "added"}
    assert any(r["kind"] == "renamed" for r in window)
    assert any(r["kind"] == "removed_duplicate" for r in window)


def test_repin_check_noop_and_snapshot_is_blob_minus_flex(pin, short):
    r = subprocess.run([sys.executable, str(REPIN.relative_to(REPO)), "--check"], cwd=REPO, capture_output=True)
    assert r.returncode == 0, r.stdout + r.stderr
    blob = subprocess.check_output(["git", "-C", str(SUB), "show", f"{pin}:RomRaider/rx8_defs.xml"])
    snap = (DEFS / "romraider" / "upstream-rx8defs" / "rx8_defs.xml").read_bytes()
    assert snap != blob, "snapshot must carry the local stock-only strip"
    root = ET.fromstring(snap.decode("utf-8-sig"))
    assert not any(t.get("category") == "Flex Fuel" for t in root.iter("table"))
    assert not any(r.findtext("romid/xmlid") == "G-ROM_FLEX" for r in root.findall("rom"))
    # every rom block of the pinned blob except G-ROM_FLEX is present
    blob_root = ET.fromstring(blob.decode("utf-8-sig"))
    blob_ids = {r.findtext("romid/xmlid") for r in blob_root.findall("rom")} - {"G-ROM_FLEX"}
    snap_ids = {r.findtext("romid/xmlid") for r in root.findall("rom")}
    assert blob_ids == snap_ids


def test_splice_record_exists_for_pin(short):
    p = DEFS_MERGE / f"upstream_splice_{short}.json"
    assert p.exists(), p
    d = json.loads(p.read_text(encoding="utf-8"))
    assert d["pinned_commit_short"] == short
    assert d["immo_evidence"]["off_state_matches_rom_bytes"] is True


def test_per_rom_defs_carry_renamed_tables_at_new_pin(short):
    """The 9 renamed uncategorized tables per ROM block landed in the
    regenerated per-ROM defs under their new upstream names; the duplicate
    overrides upstream removed (0x0706be/0x0707e2 in 60E0FC00/60E0FB00) are
    absent and are not lookup data in the ROM extraction either."""
    audit = audit_json(short)
    rm = audit["rename_map"]
    per_rom = DEFS / "romraider" / "per-rom"
    # 60E0E700_N3YLEE uses the upstream 60E0E700 block: check one rename landed
    root = ET.parse(per_rom / "60E0E700_N3YLEE.xml").getroot()
    blk = root.findall("rom")[-1]
    names = {t.get("name"): t.get("storageaddress") for t in blk.findall("table")}
    new_name, old_name = rm["Table 2D - 194 "], "Table 2D - 194 "
    assert new_name in names, f"{new_name!r} missing from 60E0E700 per-rom def"
    assert old_name not in names
    # removed duplicate overrides are gone from the 60E0FC00 def
    root = ET.parse(per_rom / "60E0FC00.xml").getroot()
    blk = root.findall("rom")[-1]
    addrs = {(t.get("storageaddress") or "").lower() for t in blk.findall("table")}
    assert "0x0706be" not in addrs and "0x0707e2" not in addrs
    # and those addresses are not extracted lookup data in that ROM (so no
    # coverage loss): recorded in the audit's removed_override_coverage
    cov = [c for c in audit["removed_override_coverage"] if c["rom"] == "60E0FC00"]
    assert cov and all(c["covered"] is False for c in cov)


def test_label_map_does_not_name_renamed_tables(short):
    audit = audit_json(short)
    assert audit["label_map_check"] == {k: [] for k in audit["label_map_check"]}
