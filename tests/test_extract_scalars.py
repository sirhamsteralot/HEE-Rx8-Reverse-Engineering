"""Tests for the scalar-constant extractor (utilities/scripts/extract_scalars.py).

Run: python -m pytest tests/test_extract_scalars.py
"""
import json
import struct
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts"))

import extract_scalars as es

ROM = REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs" / "60E15120_N3J1E.bin"
MAPS = REPO / "data" / "maps"


@pytest.fixture(scope="module")
def rom():
    return ROM.read_bytes()


def test_seed_bits_decode_to_documented_values():
    """Every seed's bit pattern must decode to its expected float32 value."""
    expected = {
        "fuel_load_scale": 0.07196000218391418,
        "load_cell_scale": 0.6345000267028809,
        "air_per_rev_factor": 60.0,
        "air_per_rev_clamp": 5.0,
        "kelvin_offset": 273.0,
        "kelvin_ref": 293.0,
        "std_atm_kpa": 101.33299255371094,
        "baro_scale_kpa": 25.325000762939453,
        "maf_adc_scale": 7.62939453125e-05,
        "blend_weight_decay": 0.06669999659061432,
        "pid0043_load_scale": 0.003921568393707275,
        "injector_flow_primary_cc_min": 369.47198486328125,
        "injector_flow_secondary_cc_min": 475.92999267578125,
    }
    for seed in es.SEEDS:
        val = struct.unpack(">f", bytes.fromhex(seed["bits"]))[0]
        assert seed["name"] in expected, f"undocumented seed {seed['name']}"
        assert val == expected[seed["name"]], f"{seed['name']}: bits decode to {val}, expected {expected[seed['name']]}"


def test_reference_rom_addresses_confirmed(rom):
    """In 60E15120_N3J1E every seed's documented reference address must be found."""
    for seed in es.SEEDS:
        bits = bytes.fromhex(seed["bits"])
        addrs = es.find_pattern(rom, bits)
        for ref in seed["ref_addrs"]:
            assert ref in addrs, (
                f"{seed['name']}: documented ref addr {hex(ref)} not found in {es.REFERENCE_ROM}")


def test_fuel_load_scale_is_the_base_fuel_scalar(rom):
    """The base load->fuel scalar: 0.07196 (0x3d935fc4) at 0x78170, unique in the ROM."""
    addrs = es.find_pattern(rom, bytes.fromhex("3d935fc4"))
    assert addrs == [0x78170]
    assert struct.unpack_from(">f", rom, 0x78170)[0] == 0.07196000218391418


def test_strict_ref_assertion_fires_on_wrong_rom(rom):
    """extract_rom with the reference id must raise if a documented address is missing."""
    import tempfile
    # Corrupt one documented literal so 0x78170 no longer holds 0.07196
    bad = bytearray(rom)
    bad[0x78170:0x78174] = struct.pack(">f", 1.0)
    with tempfile.TemporaryDirectory() as td:
        with pytest.raises(AssertionError):
            es.extract_rom(bytes(bad), es.REFERENCE_ROM, ROM, "0" * 64, Path(td))


def test_generated_outputs_exist_and_are_consistent():
    """Committed per-ROM scalars.json/.tsv and cross_rom_scalars.json must match a fresh run."""
    rom = ROM.read_bytes()
    rec = es.extract_rom(rom, es.REFERENCE_ROM, ROM, es.sha256_of(ROM), MAPS / es.REFERENCE_ROM)
    on_disk = json.loads((MAPS / es.REFERENCE_ROM / "scalars.json").read_text())
    assert on_disk["rom_sha256"] == rec["rom_sha256"]
    assert on_disk["scalars"] == rec["scalars"]
    tsv = (MAPS / es.REFERENCE_ROM / "scalars.tsv").read_text().splitlines()
    assert tsv[0].split("\t")[0] == "name"
    assert len(tsv) == 1 + len(es.SEEDS)

    cross = json.loads((MAPS / "cross_rom_scalars.json").read_text())
    assert cross["reference"] == es.REFERENCE_ROM
    rom_ids = sorted(p.name for p in MAPS.iterdir() if (p / "scalars.json").exists())
    for name, entry in cross["scalars"].items():
        assert set(entry["per_rom"].keys()) == set(rom_ids), f"{name}: cross report ROM coverage mismatch"
        # same bits everywhere => same value wherever present
        for rom_id, d in entry["per_rom"].items():
            if d["present"]:
                assert d["addresses"], f"{name} present but no addresses in {rom_id}"
        assert entry["per_rom"][es.REFERENCE_ROM]["present"]
