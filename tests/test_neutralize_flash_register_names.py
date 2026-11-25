"""The flash-module registers at 0xFFFFE800-0xFFFFE806 are named by address.

The reference Ghidra project ships two register maps that differ only in that block,
and the only flash manual in the tree (`docs/references/Sh7055h.pdf`, ADE-602-155B)
documents the 0.35 um part alone, so the exported artifacts may not carry either
variant's register names on those addresses.

Run: python -m pytest tests/test_neutralize_flash_register_names.py
"""
import csv
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
DEC = REPO / "reverse-engineered/decompiled/60E15120_N3J1E"
SCRIPT = "utilities/scripts/rx8-pcm-pipeline/neutralize_flash_register_names.py"

# Both variants' names for the block: regs_7055_180.csv (FCCS/FPCS/FECS/FKEY/FMATS/
# FTDAR) and regs_7055_350.csv (FLMCR1/FLMCR2/EBR1/EBR2).
VARIANT_NAMES = (
    "FLASH_FCCS_B", "FLASH_FPCS_B", "FLASH_FECS_B", "FLASH_FKEY_B",
    "FLASH_FMATS_B", "FLASH_FTDAR_B",
    "FLASH_FLMCR1_B", "FLASH_FLMCR2_B", "FLASH_EBR1_B", "FLASH_EBR2_B",
)

NEUTRAL = {
    "ffffe800": "DAT_ffffe800",
    "ffffe801": "DAT_ffffe801",
    "ffffe802": "DAT_ffffe802",
    "ffffe804": "DAT_ffffe804",
    "ffffe805": "DAT_ffffe805",
    "ffffe806": "DAT_ffffe806",
}


def _artifacts():
    return [
        DEC / "symbols.tsv",
        DEC / "firmware_decompiled.c",
        DEC / "named/firmware_named.c",
        *sorted((DEC / "functions").glob("*.c")),
    ]


def test_exported_artifacts_carry_no_variant_register_names():
    hits = []
    for path in _artifacts():
        data = path.read_bytes()
        hits += [f"{path.relative_to(REPO)}: {name}" for name in VARIANT_NAMES if name.encode() in data]
    assert not hits, (
        "flash-module registers must be named by address, not after one silicon variant: "
        + ", ".join(hits)
    )


def test_flash_registers_are_address_anchored():
    with (DEC / "symbols.tsv").open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        names = {r["address"]: r["name"] for r in csv.DictReader(fh, delimiter="\t")}
    found = {addr: names.get(addr) for addr in NEUTRAL}
    assert found == NEUTRAL, f"symbols.tsv flash block drifted: {found}"


def test_generator_idempotent_on_60E15120():
    """AGENTS.md rule 6d: re-running the rename step must leave the committed
    artifacts byte-identical (it only acts on a fresh export that still carries a
    variant's names)."""
    before = {path: path.read_bytes() for path in _artifacts()}
    subprocess.run([sys.executable, SCRIPT], cwd=REPO, check=True, capture_output=True)
    after = {path: path.read_bytes() for path in _artifacts()}
    drifted = [str(path.relative_to(REPO)) for path in before if before[path] != after[path]]
    assert not drifted, f"neutralize_flash_register_names.py rewrote committed artifacts: {drifted}"
