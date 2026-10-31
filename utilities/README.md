# utilities/

Scripts and tool configurations used to acquire, hash, parse, disassemble, and verify
HEE artifacts.

| Subfolder | Contents |
|---|---|
| `scripts/` | Python/bash utilities (hashing, parsing, extraction, comparison). Runnable, documented. |
| `tools/` | Configs/patches for external tools (Ghidra scripts, ImHex patterns, OpenOCD/JTAG configs). |

## Rules

- Every script: usage in a docstring/`--help`, exit codes meaningful, no hardcoded
  personal paths. Python 3, stdlib-only unless a `requirements.txt` is added here.
- Scripts that read `binaries/` must verify against `binaries/manifest.csv` first.
- Add a short usage note at the top of each script and link it from the relevant
  investigation doc.
