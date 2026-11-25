#!/usr/bin/env python3
"""Give the flash-module registers at 0xFFFFE800-0xFFFFE806 address-anchored names.

The reference Ghidra project ships two register maps that differ in exactly one
block:

  script_stuff/regs_7055_180.csv  FLASH_FCCS_B / FPCS / FECS / FKEY / FMATS / FTDAR
  script_stuff/regs_7055_350.csv  FLASH_FLMCR1_B / FLMCR2 / EBR1 / EBR2

SetupTarget.java imports one of them into the program, so the exported symbols carry
that map's names at those addresses. The two maps disagree, and neither is verified
against the part fitted to a PCM: the only flash manual in the tree
(docs/references/Sh7055h.pdf, ADE-602-155B, HD64F7055) documents the 0.35 um part,
where the block is FLMCR1/FLMCR2/EBR1/EBR2 at 0xFFFFE800-0xFFFFE803 and
0xFFFFE804-0xFFFFEBFF is reserved (section 22.5, Table 22.3, Appendix A.1). Naming
one variant's registers on those addresses asserts a hardware fact this analysis does
not have, so the exported artifacts use the DAT_ convention already used for
unidentified addresses in symbols.tsv.

The rename is the pipeline step between a fresh export and the committed artifacts;
SetupTarget.java writes the same neutral names, so a re-export lands here directly.
Idempotent: a rerun finds nothing to rename and writes nothing.

Run from anywhere: python utilities/scripts/rx8-pcm-pipeline/neutralize_flash_register_names.py
"""
import re
import sys

from paths import DEC

# Both variants' flash-block names map onto the same address-anchored name.
RENAME = {
    "FLASH_FCCS_B": "DAT_ffffe800",
    "FLASH_FLMCR1_B": "DAT_ffffe800",
    "FLASH_FPCS_B": "DAT_ffffe801",
    "FLASH_FLMCR2_B": "DAT_ffffe801",
    "FLASH_FECS_B": "DAT_ffffe802",
    "FLASH_EBR1_B": "DAT_ffffe802",
    "FLASH_EBR2_B": "DAT_ffffe803",
    "FLASH_FKEY_B": "DAT_ffffe804",
    "FLASH_FMATS_B": "DAT_ffffe805",
    "FLASH_FTDAR_B": "DAT_ffffe806",
}

TARGETS = [
    DEC / "symbols.tsv",
    DEC / "firmware_decompiled.c",
    DEC / "named/firmware_named.c",
    *sorted((DEC / "functions").glob("*.c")),
]


def neutralize(path):
    """Rename the flash-block identifiers in one artifact; return the change count."""
    data = path.read_bytes()
    out = data
    for old, new in RENAME.items():
        out = re.sub(rb"\b" + old.encode() + rb"\b", new.encode(), out)
    changed = sum(1 for a, b in zip(data.splitlines(), out.splitlines()) if a != b)
    if out != data:
        path.write_bytes(out)
    return changed


def main():
    total = 0
    for path in TARGETS:
        if not path.exists():
            continue
        changed = neutralize(path)
        if changed:
            print(f"{path.relative_to(DEC.parent.parent)}: {changed} line(s)")
        total += changed
    if not total:
        print("flash-module register names already neutral; nothing to do")
    return 0


if __name__ == "__main__":
    sys.exit(main())
