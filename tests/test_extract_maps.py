"""Tests for the calibration-map extractor (utilities/scripts/extract_maps.py).

Run: python -m pytest tests/test_extract_maps.py
"""
import json
import struct
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts"))

import extract_maps as em

ROM = REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs" / "60E15120_N3J1E.bin"


@pytest.fixture(scope="module")
def rom():
    return ROM.read_bytes()


@pytest.fixture(scope="module")
def cal_start(rom):
    return em.detect_cal_start(rom)


@pytest.fixture(scope="module")
def tables(rom, cal_start):
    descs = em.scan_descriptors(rom, cal_start)
    descs.sort(key=lambda d: d["descriptor"])
    resolved = []
    next_free = 0
    for d in descs:
        if d["descriptor"] < next_free:
            continue
        span = 20 if d["dimension"] == 3 else 12
        next_free = d["descriptor"] + span
        resolved.append(d)
    out = []
    for d in resolved:
        t = em.extract_table(rom, d)
        if t:
            out.append(t)
    return out


def test_cal_start_detected(cal_start):
    assert cal_start == 0x6C000


def test_finds_all_known_descriptors(tables):
    """All 478 RX8Defs-matched descriptors must be found."""
    known_path = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "cross_ecu" / "romraider_descriptor_matches.json"
    known = json.loads(known_path.read_text())
    known_addrs = {int(m["descriptor"], 16) for m in known}
    our_addrs = {t["descriptor"] for t in tables}
    missing = known_addrs - our_addrs
    assert not missing, f"missing {len(missing)} known descriptors: {sorted(hex(a) for a in list(missing)[:5])}"


def test_type_codes_match(tables):
    type_map = {0: "float32", 4: "uint8", 8: "uint16", 12: "int8", 16: "int16"}
    known_path = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "cross_ecu" / "romraider_descriptor_matches.json"
    known = json.loads(known_path.read_text())
    our_by_addr = {t["descriptor"]: t for t in tables}
    for m in known:
        a = int(m["descriptor"], 16)
        if a in our_by_addr:
            assert our_by_addr[a]["type_name"] == type_map[m["type_code"]], f"type mismatch at 0x{a:06x}"


def test_data_matches_raw_rom(rom, tables):
    """Spot-check extracted data values against raw ROM bytes."""
    fmts = {0: (">f", 4), 4: (">B", 1), 8: (">H", 2), 12: (">b", 1), 16: (">h", 2)}
    for t in tables[:50]:  # first 50 is enough
        fmt, sz = fmts[t["type_code"]]
        if t["dimension"] == 2:
            raw = [struct.unpack_from(fmt, rom, t["data"] + i * sz)[0] for i in range(t["n"])]
            assert [float(v) for v in t["data_values"]] == [float(v) for v in raw]
        else:
            nx, ny = t["nx"], t["ny"]
            for y in range(ny):
                raw = [struct.unpack_from(fmt, rom, t["data"] + (y * nx + x) * sz)[0] for x in range(nx)]
                assert [float(v) for v in t["data_values"][y]] == [float(v) for v in raw]


def test_all_axes_monotonic(tables):
    for t in tables:
        if t["dimension"] == 2:
            assert t["axis_monotonic"], f"non-monotonic axis at 0x{t['descriptor']:06x}"
        elif t["dimension"] == 3:
            assert t["axis_x_monotonic"], f"non-monotonic X at 0x{t['descriptor']:06x}"
            assert t["axis_y_monotonic"], f"non-monotonic Y at 0x{t['descriptor']:06x}"


def test_table_counts_reasonable(tables):
    assert len(tables) >= 500, f"expected >=500 tables, got {len(tables)}"
    dims = {2: 0, 3: 0}
    for t in tables:
        if t["dimension"] in dims:
            dims[t["dimension"]] += 1
    assert dims[2] > 300 and dims[3] > 100
