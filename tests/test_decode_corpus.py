"""Validate the emulator's opcode dispatch table against the real disassembly:
every instruction in firmware_disassembly.asm must have an OPMNEM entry with the
same mnemonic and a implemented handler in sh2e.SH2E."""
import os
import re
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

from opdec import OPMNEM  # noqa: E402
from sh2e import SH2E  # noqa: E402

ASM = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "..", "reverse-engineered", "disassembly",
    "60E15120_N3J1E", "firmware_disassembly.asm"))


def _handler_name(mn):
    return "_op_" + mn.replace("/", "").replace(".", "").replace("#", "imm")


def test_corpus_fully_covered():
    assert os.path.isfile(ASM), f"disassembly missing: {ASM}"
    cpu = SH2E(bus=None)
    missing_table = []
    missing_handler = []
    total = 0
    for line in open(ASM, encoding="utf-8", errors="replace"):
        parts = line.split(None, 3)
        if len(parts) < 3 or not re.fullmatch(r"[0-9a-f]{4}", parts[1]):
            continue
        total += 1
        op = int(parts[1], 16)
        mn = parts[2].lstrip("_")
        entry = OPMNEM.get(op)
        if entry is None:
            missing_table.append((op, mn))
        elif entry[0] != mn:
            missing_table.append((op, f"{entry[0]} != {mn}"))
        if not hasattr(cpu, _handler_name(mn)):
            missing_handler.append(mn)
    assert total > 100000, f"corpus too small: {total}"
    assert not missing_table, f"opcodes missing/wrong in OPMNEM: {missing_table[:20]}"
    assert not missing_handler, f"mnemonics without handler: {sorted(set(missing_handler))}"
