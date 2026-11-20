#!/usr/bin/env python3
"""Tests for the throttle / DBW label record (DBW relay PE0).

Covers data/labels/60E15120_N3J1E/throttle_dbw_labels.json (split out of
fuel_pump_control_labels.json per the report scope-discipline rule — the PE0
DBW relay was mapped while tracing the fuel pump port bank; ROADMAP C item 27):

  * the accepted source-review TSV rows mirror the JSON aliases;
  * dynamic (SH-2E emulator): PEDR bit 0x1 (PE0) = (0xffffcfb7 == 0), driven
    by relay_output_pair_pd7_pe0 0x3a0ec (label record
    starting_cranking_labels.json).

Run: python -m pytest tests/test_throttle_dbw.py
"""
import csv
import json
import os
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "throttle_dbw_labels.json"
RAM_TSV = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review" / "accepted_ram_aliases.tsv"

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

PEDR = 0xFFFFF754

CFB6 = 0xFFFFCFB6      # pd7_relay_flag (PD7 half: starting_cranking_labels.json)
CFB7 = 0xFFFFCFB7      # pe0_relay_flag


@pytest.fixture(scope="module")
def record():
    return json.loads(LBL.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def pe0(bus):
    return bus.read16(PEDR) & 1


def test_pe0_drive_dynamic(booted):
    """0x3a0ec: PEDR bit 0x1 (PE0) = (0xffffcfb7 == 0) — DBW relay (inverted)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 0)})
    assert pe0(bus) == 1
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 1)})
    assert pe0(bus) == 0


def test_tsv_rows_mirror_json(record):
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        ram_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, e in record["ram_aliases"].items():
        assert ram_rows.get(addr) == e["alias"]
