"""Label-artifact consistency for the seven large unlabeled control bodies.

The labels applied by this pass must be present and identical in all four
artifacts: function_index.tsv, symbols.tsv, the accepted TSVs, and the labels
JSON (which must cover exactly those TSV rows — mirrors verify_claims.py).
Per-subsystem binary checks live in the sibling files test_o2_sensor_monitor.py,
test_cruise_control.py, test_e2ram_nv_storage.py, test_idle_target_control.py,
test_can_mailbox_config.py.

Run: python -m pytest tests/test_large_control_bodies_labels.py
"""
import csv
import json
import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
INV = os.path.join(ROOT, "docs", "investigations", "60E15120_N3J1E")
LAB = os.path.join(ROOT, "data", "labels", "60E15120_N3J1E")

EXPECTED_FN = {
    "0003fb9e": "o2_response_monitor_accumulate",
    "0004128e": "o2_response_monitor_evaluate",
    "0003f924": "o2_channel_filter_update",
    "0004ca7e": "cruise_speed_error_filter_stage",
    "0002d83c": "cruise_set_speed_adjust_integrator",
    "00023844": "e2ram_block_decode",
    "000244bc": "e2ram_block_encode",
    "0001506c": "idle_target_rpm_calculate",
    "0002a4f8": "hcan_mailbox_config_compare",
    "0002376c": "e2ram_load_decode_entry",
    "0002377a": "e2ram_save_encode_entry",
    "00023f4e": "e2ram_stored_dtc_replay",
    "000242ae": "e2ram_fault_status_collect",
    "0004c828": "cruise_switch_code_decode",
    "0002df62": "cruise_set_speed_apply",
}
EXPECTED_RAM = {
    "ffffc6f0": "o2_monitor_ratio_ch0",
    "ffffc6f4": "o2_monitor_ratio_ch1",
    "ffffc780": "o2_monitor_ratio_ch2",
    "ffffc784": "o2_monitor_ratio_ch3",
    "ffffc701": "o2_monitor_fluctuation_detected",
    "ffffc708": "o2_channel_afr_fast",
    "ffffc710": "o2_channel_lambda_slow",
    "ffffb440": "e2ram_staging_block",
    "ffffb478": "e2ram_read_staging",
    "ffffb47a": "e2ram_payload_raw",
    "ffffb4ec": "stored_dtc_flag_bits",
    "ffffa7f4": "idle_target_rpm",
    "ffffbd08": "cruise_set_speed_adjust",
    "ffffbcf8": "cruise_set_speed",
    "ffffbaed": "cruise_switch_code",
    "ffffcef4": "cruise_filtered_speed_error",
    "ffffcee4": "cruise_speed_error_mean12",
}


def test_labels_in_function_index():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"


def test_ram_aliases_in_symbols():
    syms = {r["address"]: r["name"] for r in
            csv.DictReader(open(os.path.join(DEC, "symbols.tsv"), newline="", encoding="utf-8",
                                errors="surrogateescape"), delimiter="\t")}
    for addr, alias in EXPECTED_RAM.items():
        assert syms.get(addr) == f"{alias}_{addr}", f"{addr}: {syms.get(addr)!r}"


def test_accepted_tsv_rows():
    fn = {r["address"]: r["alias"] for r in
          csv.DictReader(open(os.path.join(INV, "source_review", "accepted_function_aliases.tsv"),
                              newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    ram = {r["address"]: r["alias"] for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
    for addr, alias in EXPECTED_RAM.items():
        assert ram.get(addr) == alias


def test_labels_json_covers_tsv_rows():
    data = json.load(open(os.path.join(LAB, "large_control_bodies_labels.json")))
    for addr, entry in data["function_aliases"].items():
        assert addr in EXPECTED_FN and EXPECTED_FN[addr] == entry["alias"]
    for addr, entry in data["ram_aliases"].items():
        assert addr in EXPECTED_RAM and EXPECTED_RAM[addr] == entry["alias"]
    assert len(data["function_aliases"]) == len(EXPECTED_FN)
    assert len(data["ram_aliases"]) == len(EXPECTED_RAM)
