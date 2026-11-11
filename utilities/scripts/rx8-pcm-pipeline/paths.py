#!/usr/bin/env python3
"""Path shim for the rx8-pcm-pipeline scripts.

The pipeline was written against the legacy `input/Tuning-merged` workspace
layout (`b = <workspace>/utilities/scripts`, with `decompiled/`, `metadata/`,
`source_review/`, ... as siblings, and upstream repos directly under the
workspace root). This repo promotes those into tracked folders:

  decompiled/     -> reverse-engineered/decompiled/60E15120_N3J1E/
                     (except the disassembly outputs, see below)
  disassembly     -> reverse-engineered/disassembly/60E15120_N3J1E/
  source_review/  -> docs/investigations/60E15120_N3J1E/source_review/
  cross_ecu/      -> docs/investigations/60E15120_N3J1E/cross_ecu/
  math_units/     -> docs/investigations/60E15120_N3J1E/math_units/
  lookup_family/  -> docs/investigations/60E15120_N3J1E/lookup_family/
  readability/    -> docs/investigations/60E15120_N3J1E/readability/
  backups/        -> docs/investigations/60E15120_N3J1E/backups/
  metadata/       -> data/labels/60E15120_N3J1E/
  named/          -> reverse-engineered/decompiled/60E15120_N3J1E/named/
  design/         -> docs/architecture/design/
  hardware/       -> docs/architecture/hardware/
  processor/      -> utilities/tools/ghidra/processor/
  scripts/ (Java) -> utilities/tools/ghidra/scripts/
  reference_project/, ghidra_project/ -> $GHIDRA_WORK (default input/ghidra-work;
                     Ghidra project DBs are NOT committed - AGENTS.md)
  Mazda_RX8_PCM_ReverseEngineering/..., RX8Defs/..., Rx8Man/... -> submodules/...

Scripts keep working unchanged: they do `from paths import b` (or `base`) and
use `b/'decompiled/...'` / `b.parents[1]` exactly as before; this shim remaps
the first path component. Run scripts from anywhere; paths resolve to the repo.
"""
import os
from pathlib import Path, PosixPath

ROOT = Path(__file__).resolve().parents[3]          # repo root
ROM_ID = "60E15120_N3J1E"
DEC = ROOT / "reverse-engineered/decompiled" / ROM_ID
DISASM = ROOT / "reverse-engineered/disassembly" / ROM_ID
INV = ROOT / "docs/investigations" / ROM_ID
LABELS = ROOT / "data/labels" / ROM_ID
SUBM = ROOT / "submodules"
GHIDRA_WORK = Path(os.environ.get("GHIDRA_WORK", ROOT / "input/ghidra-work"))

# files the legacy export wrote into decompiled/ that live in disassembly/ here
DISASM_FILES = {"firmware_disassembly.asm", "decompiler_issues.tsv", "non_instruction_ranges.tsv"}

# legacy first path component -> real directory
DIR_MAP = {
    "decompiled": DEC,
    "disassembly": DISASM,
    "source_review": INV / "source_review",
    "cross_ecu": INV / "cross_ecu",
    "math_units": INV / "math_units",
    "lookup_family": INV / "lookup_family",
    "readability": INV / "readability",
    "comment_merge": INV / "comment_merge",
    "backups": INV / "backups",
    "metadata": LABELS,
    "named": DEC / "named",
    "design": ROOT / "docs/architecture/design",
    "hardware": ROOT / "docs/architecture/hardware",
    "processor": ROOT / "utilities/tools/ghidra/processor",
    "scripts": ROOT / "utilities/tools/ghidra/scripts",
    "reference_project": GHIDRA_WORK / "reference_project",
    "ghidra_project": GHIDRA_WORK / "ghidra_project",
}

# upstream repo prefixes that lived at the workspace root -> pinned submodules
REPO_PREFIXES = ("Mazda_RX8_PCM_ReverseEngineering/", "RX8Defs/", "Rx8Man/")


def remap(key):
    key = str(key)
    first = key.split("/")[0].split(os.sep)[0]
    if first == "decompiled" and key.split("/")[-1] in DISASM_FILES:
        return DISASM / Path(key).name
    if first in DIR_MAP:
        rest = key[len(first):].lstrip("/").lstrip(os.sep)
        return DIR_MAP[first] / rest if rest else DIR_MAP[first]
    for p in REPO_PREFIXES:
        if key.startswith(p):
            return SUBM / key
    return ROOT / key


class WS:
    """Path-like shim: `b / 'legacy/key'` remaps to the promoted repo path."""
    def __truediv__(self, key):
        return remap(key)

    def __rtruediv__(self, key):
        return remap(key)

    @property
    def parents(self):
        # keep dividing through the shim so parents[1]/'Mazda_RX8_...' remaps
        return [WS(), WS()]

    # a few scripts call methods on b itself (e.g. b.glob(...)): run them on ROOT
    def glob(self, pattern):
        return ROOT.glob(pattern)

    def rglob(self, pattern):
        return ROOT.rglob(pattern)

    def exists(self):
        return ROOT.exists()

    def read_text(self, *a, **k):
        return ROOT.read_text(*a, **k)

    def mkdir(self, *a, **k):
        return ROOT.mkdir(*a, **k)


b = WS()
base = b  # some scripts name it `base`


def rom_file():
    """Resolve the ROM path recorded in metadata/input.json ('file').
    Legacy absolute paths fall back to the pinned submodule copy by basename."""
    import json
    p = Path(json.loads((LABELS / "input.json").read_text())["file"])
    if p.is_file():
        return p
    cand = SUBM / "Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs" / p.name
    if cand.is_file():
        return cand
    raise FileNotFoundError(f"ROM not found: {p} (nor {cand})")
