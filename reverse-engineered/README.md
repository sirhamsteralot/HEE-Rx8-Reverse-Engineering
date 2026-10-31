# reverse-engineered/

All reverse-engineering output for the HEE target. Three layers, kept separate on
purpose:

| Subfolder | Contents | Audience |
|---|---|---|
| `disassembly/` | Annotated disassembly exports, disassembler project notes/scripts, function lists with original addresses. | RE engineers |
| `decompiled/` | Decompiler output (Ghidra/IDA/Binja), cleaned up but still address-bound. | RE engineers |
| `reimplementation/` | Clean-room source that builds and runs standalone (C/Python/whatever fits). No copied decompiler dumps here. | Developers |

## Rules

- Always reference the original address (`0x08001234`) in symbol names, comments,
  and commit messages so work traces back to `binaries/`.
- Prefer small, reviewable diffs: one subsystem per commit.
- Keep disassembler *projects* (`.gzf`, `.idb`, `.bnproj`) out of git unless small;
  commit the exported annotations/scripts instead, or note the project location.
- Reimplementation code must be verifiable — pair it with a test in `../tests/`.
