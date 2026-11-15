"""Ignition key-state / power-state logic: static binary-level checks for the
60E15120_N3J1E ignition_power_state_report.md.

Covers the reset warm/cold split (0x4e0, magic 0xffffdffc, warm entry cell ROM
0x1000, cold 0x6c8, recovery cells ROM 0x7fff8/0x7fffc), the boot NMI-pin poll
(ICR_W bit15 at 0x8ea), the key-on input path (PFDR bit0 -> 0xffff9ec8 ->
0xffffaa69/0xffffaa68, PF15 edge latch 0xffffcbd0), the UDS gate in 0x11d88, the
key-off shutdown state machine (0x252c2), the relay-hold output PD11 (0x251d0),
PF3 (0x9e68/0x9ea2), the PB15 watchdog heartbeat (0xa850), the key-on/off timers
(0x195cc/0x195f4), the CAN RX/TX key gating (0xdbf6/0xdb58), the labels JSON <->
accepted TSV coverage, export integration, and the cross-ROM propagation
artifact (including its regeneration idempotency).

Run: python -m pytest tests/test_ignition_power_state.py
"""

import csv
import hashlib
import json
import os
import struct
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
ROM_PATH = os.path.join(
    ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Stock_ROMs", "60E15120_N3J1E.bin")
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
LAB = os.path.join(ROOT, "data", "labels", "60E15120_N3J1E",
                   "ignition_power_state_labels.json")
CROSS = os.path.join(ROOT, "data", "labels", "cross_rom",
                     "ignition_power_state_addresses.json")
SR = os.path.join(ROOT, "docs", "investigations", "60E15120_N3J1E",
                  "labeling", "source_review")

ROM = open(ROM_PATH, "rb").read()
ROM_SHA = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def test_rom_hash_and_size():
    assert len(ROM) == 0x80000
    assert hashlib.sha256(ROM).hexdigest() == ROM_SHA


# --- reset warm/cold split -------------------------------------------------

def test_reset_entry_cells():
    assert u32(0x1000) == 0x1298          # warm entry pointer cell
    assert u32(0x7fff8) == 0xd204         # recovery entry pointer
    assert u32(0x7fffc) == 0x2000         # app pointer (fw id string)


def test_reset_handler_pools():
    # pool words of ref_resetHandler_ -> now reset_handler_warm_cold_select 0x4e0
    assert u32(0x59c) == 0x5aa5a55a       # magic constant
    assert u32(0x5a0) == 0xffffdffc       # magic cell
    assert u16(0x58c) == 0x6c8            # cold path
    assert u16(0x58e) == 0x1000           # warm entry pointer cell
    assert u32(0x5a4) == 0x7fffc          # flash/app pointer check
    assert u32(0x5a8) == 0x7fff8          # recovery fallback
    assert u16(0x594) == 0x40             # FUN_00000040 (set SP, jmp @r4)
    assert u16(0x590) == 0xdfa8          # reset-cause cell (sign-extended)


def test_warm_entry_stub_bytes():
    # 0x1298: mov.w @(0x1348,pc),r3 ; jsr @r3 ; mov #0,r4 ; bra self ; nop
    assert ROM[0x1298:0x12a2].hex() == "9356430be400affe0009"
    assert u16(0x1348) == 0x1038          # warm_reset_dispatcher


def test_boot_nmi_pin_poll():
    # 0x8cc init: ICR_W 0xffffed18 zeroed (pool 0x9a4=0xed18), then 0x8ea-0x8f0
    # polls ICR_W & 0x8000 (pool 0x9b4) until the NMI pin reads high
    assert u16(0x9a4) == 0xed18
    assert u32(0x9b4) == 0x8000
    assert ROM[0x8ea:0x8f2].hex() == "6241622d225889fb"


def test_wdt_keyed_reset_pools():
    assert u16(0x596) == 0x5a1f           # RSTCSR keyed value
    assert u16(0x598) == 0xec12           # RSTCSR_W 0xffffec12
    assert u16(0x59a) == 0xec10           # TCSR 0xffffec10
    assert u32(0x5ac) == 0xa53c           # keyed TCSR write


# --- key-on input path -----------------------------------------------------

def test_pfdr_latch_and_key_on_flag_pools():
    assert u32(0x1a610) == 0xffff9ec8     # vehicle_inputs_pfdr_latch
    assert u32(0x1a60c) == 0xffffaa69     # key_on_latch_aa69
    assert u16(0x1a60a) == 0xaa68          # engine_running_flag 0xffffaa68


def test_pf15_key_input_pools():
    assert u16(0x45508) == 0xf74e         # PFDR_W 0xfffff74e
    assert u32(0x4550c) == 0x8000         # PF15 mask
    assert u32(0x45510) == 0xffffcbd1     # key_input_pf15_prev
    assert u16(0x4550a) == 0xcbd0         # key_input_pf15_edge_latch


def test_uds_gate_reads_latch_bit0():
    # 0x11d88 can_rx_poll_move_to_uds_buffer loads 0xffff9ec8 via pool 0x11e98
    assert u32(0x11e98) == 0xffff9ec8


def test_key_timers_pools():
    assert u16(0x1961a) == 0xa9e0         # key_on_time_counter
    assert u16(0x1961e) == 0xa9e2         # key_off_time_counter
    assert u16(0x1961c) == 0xaa68         # engine_running_flag
    assert u32(0x19620) == 0x2460         # rx8_add_u16_saturate


# --- key-off shutdown ------------------------------------------------------

def test_key_off_state_machine_pools():
    assert u32(0x25380) == 0xffffb57a     # key_off_state
    assert u16(0x25378) == 0xaa68         # engine flag
    assert u32(0x2539c) == 0xffffb57c     # key_off_timer
    assert u32(0x253a4) == 0x74940        # timeout constant cell
    assert u32(0x74940) == 0x36ee8        # shutdown timeout (slow-task ticks)
    assert u32(0x253a8) == 0x9ea2         # shutdown_wait_key_pin_then_halt
    assert u16(0x25376) == 0x8104         # shutdown_e2_shadow_flag
    assert u32(0x2538c) == 0xffffb582     # early counter a
    assert u32(0x25390) == 0xffffb583     # early counter b


def test_relay_hold_output_pools():
    assert u16(0x25272) == 0xf746         # PDDR_W 0xfffff746
    assert u16(0x25270) == 0x800          # PD11 mask
    assert u32(0x25278) == 0xffffb574     # relay_hold_flag
    assert u16(0x2526c) == 0xccc1         # shutdown_allowed


def test_pf3_shutdown_output():
    # 0x9e68 sets PFDR bit3=1 (mov #1,r6 at 0x9e82, mov #8,r5 at 0x9e8a);
    # 0x9ea2 clears it (mov #0,r6 at 0x9eb6, mov #8,r5 at 0x9eba)
    assert u16(0x9f1a) == 0xf74e          # PFDR_W
    assert ROM[0x9e82:0x9e8c].hex() == "e6019449d329430be508"
    assert ROM[0x9eb6:0x9ebe].hex() == "e600d31ce5089d2d"


def test_wdt_heartbeat_pools():
    assert u16(0xa88e) == 0xf738          # PBDR_W 0xfffff738
    assert u32(0xa89c) == 0x8000          # PB15 mask
    assert u16(0xa88c) == 0x7fff          # clear mask


def test_can_rx_tx_key_gating_pools():
    assert u16(0xdc5c) == 0xaa68          # in 0xdbf6/0xdb58: engine flag
    assert u16(0xdc5e) == 0xb578          # engine_stopped_latch


# --- labels artifacts ------------------------------------------------------

def _tsv(path):
    with open(path, newline="", encoding="utf-8", errors="surrogateescape") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def test_labels_json_matches_accepted_tsvs():
    lab = json.load(open(LAB, encoding="utf-8"))
    fn = {r["address"]: r["alias"] for r in _tsv(os.path.join(SR, "accepted_function_aliases.tsv"))}
    ram = {r["address"]: r["alias"] for r in _tsv(os.path.join(SR, "accepted_ram_aliases.tsv"))}
    for a, e in lab["function_aliases"].items():
        want = ("candidate_" if e["confidence"] == "medium" else "") + e["alias"]
        assert fn.get(a) == e["alias"], a
        assert e["evidence"].strip(), a
        # export integration: index carries the (candidate_-prefixed) alias
        idx = {r["address"]: r["name"] for r in _tsv(os.path.join(DEC, "function_index.tsv"))}
        assert idx[a] == want, (a, idx[a], want)
    for a, e in lab["ram_aliases"].items():
        assert ram.get(a) == e["alias"], a
        assert e["evidence"].strip(), a


def test_cross_rom_artifact():
    d = json.load(open(CROSS, encoding="utf-8"))
    assert d["base_sha256"] == ROM_SHA
    assert len(d["roms"]) == 11
    assert len(d["key_functions"]) == 34
    # every key function byte-matches in the base ROM; the reset-chain core
    # matches in all 11 dumped ROMs (other functions vary per ROM family)
    for a, v in d["key_functions"].items():
        assert "60E15120_N3J1E.bin" in v["roms"], a
    for a in ("000004e0", "000006c8", "00009ea2", "00009e68", "00001298" if "00001298" in d["key_functions"] else "000004e0"):
        assert len(d["key_functions"][a]["roms"]) == 11, a
    # per-ROM entry cells: warm entry 0x1298 (family A) / 0x12b4 (family B/C),
    # recovery entry 0xd204 / 0xd49c / 0xd494, app pointer 0x2000 everywhere
    warm = {v for v in d["rom_cells"]["0x00001000"]["per_rom"].values()}
    assert warm == {"0x00001298", "0x000012b4"}
    rec = {v for v in d["rom_cells"]["0x0007fff8"]["per_rom"].values()}
    assert rec == {"0x0000d204", "0x0000d49c", "0x0000d494"}
    assert {v for v in d["rom_cells"]["0x0007fffc"]["per_rom"].values()} == {"0x00002000"}


def test_cross_rom_artifact_regenerates():
    before = open(CROSS, "rb").read()
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "utilities", "scripts",
                                 "extract_ignition_power_state_addresses.py")],
                   check=True, cwd=ROOT, capture_output=True)
    after = open(CROSS, "rb").read()
    assert before == after
