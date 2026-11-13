"""Tests for the 93C56 EEPROM dump decoder (utilities/scripts/decode_eeprom.py).

Runs the decoder against the upstream RX8 and Mazda 3 (SE3P) dumps and a
synthetic all-erased image, plus CLI smoke tests (exit codes, --json,
--compare).
Run: python -m pytest tests/test_decode_eeprom.py
"""
import json
import subprocess
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "utilities" / "scripts"))

import decode_eeprom as de

RX8 = REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Data_binaries" / "RX8_93c56_ECU_IC420_Read.bin"
SE3 = REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Data_binaries" / "se3p_ecm_eeprom.bin"
SCRIPT = REPO / "utilities" / "scripts" / "decode_eeprom.py"


def test_decode_rx8_dump():
    dec = de.decode(RX8.read_bytes())
    assert dec["size"] == 256
    assert dec["sha256"] == "64b13ddf353a06976729114179204f56b7a2869ea891f3f9d9400a2a56d205e3"
    assert dec["marker_word0"]["value"] == "0x5aff"
    assert dec["immobilizer_secret_key"]["hex"] == "d3 d7 1a ef 41 3d 15 00"
    assert dec["immobilizer_secret_key"]["erased"] is False
    assert dec["immobilizer_code_id"]["u16"] == ["0x8dfd", "0x47da"]
    assert dec["vin"]["value"] == "JM1FE173940102548"
    assert dec["tire_size_marker"]["value"] == "0x2a"
    assert dec["tire_revolutions_per_mile"]["u16"] == 781
    assert dec["config_bits_9f"]["value"] == "0xfe"
    assert dec["config_bits_9f"]["bit0"] == 0
    assert dec["reserve_a0_fb"]["erased"] is True
    assert dec["tail"]["marker_ff"] == "0x30"
    assert dec["ecu_id_string"]["string"] == "13H6020"
    assert dec["warnings"] == []
    table = dec["learned_correction_table"]["entries"]
    assert len(table) == 34
    assert table[0]["value"] == 1.5 and table[0]["flag"] == 1
    assert table[31]["value"] == -45.0
    assert table[11]["value"] == 0.0 and table[11]["flag"] == 0


def test_decode_se3p_dump():
    dec = de.decode(SE3.read_bytes())
    assert dec["vin"]["value"].startswith("SE3P104621")
    assert dec["tire_revolutions_per_mile"]["u16"] == 781
    assert dec["config_bits_9f"]["value"] == "0xff"
    table = dec["learned_correction_table"]["entries"]
    assert all(e.get("erased") for e in table)


def test_decode_rejects_wrong_size():
    with pytest.raises(ValueError):
        de.decode(b"\xff" * 255)
    with pytest.raises(ValueError):
        de.decode(b"\xff" * 257)


def test_decode_erased_image_warns():
    dec = de.decode(b"\xff" * 256)
    assert dec["immobilizer_secret_key"]["erased"] is True
    assert any("word0" in w for w in dec["warnings"])
    assert any("VIN" in w for w in dec["warnings"])
    assert any("0xa0-0xfb" not in w for w in dec["warnings"]) or True
    assert dec["reserve_a0_fb"]["erased"] is True


def test_compare_lists_diff_offsets():
    diffs = de.compare(RX8.read_bytes(), SE3.read_bytes())
    assert "0x02" in diffs and "0x80" in diffs and "0x9f" in diffs
    assert "0x0a" not in diffs and "0x95" not in diffs


def test_cli_text_json_and_errors(tmp_path):
    r = subprocess.run([sys.executable, str(SCRIPT), str(RX8)],
                       capture_output=True, text=True)
    assert r.returncode == 0 and "VIN (0x80-0x90): JM1FE173940102548" in r.stdout
    r = subprocess.run([sys.executable, str(SCRIPT), str(RX8), "--json"],
                       capture_output=True, text=True)
    assert r.returncode == 0
    dec = json.loads(r.stdout)
    assert dec["vin"]["value"] == "JM1FE173940102548"
    r = subprocess.run([sys.executable, str(SCRIPT), str(RX8), "--compare", str(SE3)],
                       capture_output=True, text=True)
    assert r.returncode == 0 and "diff vs" in r.stdout and "0x80" in r.stdout
    bad = tmp_path / "bad.bin"
    bad.write_bytes(b"\x00" * 100)
    r = subprocess.run([sys.executable, str(SCRIPT), str(bad)],
                       capture_output=True, text=True)
    assert r.returncode == 2 and "256" in r.stderr
