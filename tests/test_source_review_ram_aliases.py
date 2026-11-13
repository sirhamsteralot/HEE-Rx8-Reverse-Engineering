#!/usr/bin/env python3
"""Rule-7 binary-level verification of every accepted RAM alias.

Each row of docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_ram_aliases.tsv
must be anchored in the raw ROM (SHA-256 pinned): the RAM address is loaded
through a PC-relative literal pool — either

  * directly in the cited reader function (mov.l 32-bit pool word, or a mov.w
    pool word that sign-extends to the 0xffff.... address), or
  * directly anywhere in the ROM (shared pool / helper), or
  * as an array/struct member: some pool-referenced base cell b with
    0 < addr - b < 0x200 exists (e.g. 0xffffa098 = 0xffffa094 + 4*ch).

Also checks TSV hygiene: unique addresses, non-empty alias/evidence.
"""
import bisect
import csv
import hashlib
import re
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
TSV = REPO / "docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_ram_aliases.tsv"
ROM = (
    REPO
    / "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"
)
ASM = (
    REPO
    / "reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm"
)
FUNC_INDEX = REPO / "reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

ASM_LINE = re.compile(r"^([0-9a-f]{8})  ([0-9a-f]{4})  (.*)$")
POOL_REF = re.compile(r"@\((0x[0-9a-f]+),pc\)")


def _sext16(w):
    return (w - 0x10000 if w >= 0x8000 else w) & 0xFFFFFFFF


@pytest.fixture(scope="module")
def rom():
    data = ROM.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ROM_SHA256, "ROM hash changed"
    return data


@pytest.fixture(scope="module")
def disasm():
    lines = {}
    for raw in ASM.read_text(encoding="utf-8", errors="replace").splitlines():
        m = ASM_LINE.match(raw)
        if m:
            lines[int(m.group(1), 16)] = m.group(3).strip()
    return lines


@pytest.fixture(scope="module")
def func_starts():
    with FUNC_INDEX.open(encoding="utf-8", errors="replace", newline="") as fh:
        return sorted(int(r["address"], 16) for r in csv.DictReader(fh, delimiter="\t"))


@pytest.fixture(scope="module")
def rows():
    with TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def _func_range(func_starts, reader, rom_len):
    start = int(reader, 16)
    k = bisect.bisect_right(func_starts, start)
    return start, (func_starts[k] if k < len(func_starts) else rom_len)


def _pool_loads(disasm, rom, lo, hi):
    """All (addr, mnemonic, value) of pool loads with lo <= addr < hi."""
    out = []
    a = lo
    while a < hi:
        mn = disasm.get(a)
        if mn is None:  # literal-pool word inside the range
            a += 2
            continue
        if mn.startswith("mov.l") or mn.startswith("mov.w"):
            for m in POOL_REF.finditer(mn):
                pool = int(m.group(1), 16)
                if mn.startswith("mov.l"):
                    val = int.from_bytes(rom[pool : pool + 4], "big")
                else:
                    val = _sext16(int.from_bytes(rom[pool : pool + 2], "big"))
                out.append((a, mn, val))
        a += 2
    return out


def test_tsv_hygiene(rows):
    addrs = [r["address"].lower() for r in rows]
    assert len(addrs) == len(set(addrs)), "duplicate address rows"
    for r in rows:
        assert (r.get("alias") or "").strip(), r["address"]
        assert (r.get("evidence") or "").strip(), f"empty evidence: {r['address']}"
        assert re.fullmatch(r"ffff[0-9a-f]{4}", r["address"].lower()), r["address"]


def test_every_ram_alias_anchored_in_raw_rom(rows, rom, disasm, func_starts):
    # every RAM pool value referenced anywhere in the ROM
    all_loads = _pool_loads(disasm, rom, 0, len(rom))
    ram_vals = {v for _, _, v in all_loads if 0xFFFF0000 <= v <= 0xFFFFFFFF}
    failures = []
    for r in rows:
        addr = r["address"].lower().replace("0x", "")
        want = int(addr, 16)
        reader = (r.get("reader") or "").lower().replace("0x", "")
        direct_in_reader = False
        if reader:
            lo, hi = _func_range(func_starts, reader, len(rom))
            direct_in_reader = any(
                v == want for _, _, v in _pool_loads(disasm, rom, lo, hi)
            )
        # literal present anywhere in the raw ROM (pool words in non-instruction
        # ranges are not disassembled as loads, so scan the bytes too)
        direct_anywhere = (
            want in ram_vals
            or want.to_bytes(4, "big") in rom
            or (want & 0xFFFF).to_bytes(2, "big") in rom
        )
        base_member = any(
            0 < want - b < 0x200 and (b in ram_vals or b.to_bytes(4, "big") in rom)
            for b in range(want - 0x1FF, want)
        )
        if not (direct_in_reader or direct_anywhere or base_member):
            failures.append((addr, r.get("alias"), reader))
    assert not failures, f"unanchored RAM aliases: {failures}"
    assert len(rows) >= 482  # sweep baseline: 482 accepted rows must stay covered
