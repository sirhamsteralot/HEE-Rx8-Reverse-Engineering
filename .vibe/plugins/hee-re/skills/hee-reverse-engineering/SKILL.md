---
name: hee-reverse-engineering
description: Reverse-engineering workflow for the HEE RX-8 PCM using the heeRe MCP tools (emulator, debugger, ROM data) and this repo's evidence rules. Use when analyzing ROMs, labeling functions, validating findings dynamically, or diffing tuned vs stock binaries.
user-invocable: true
allowed-tools: heeRe.*
---

# HEE RX-8 PCM reverse engineering with agent tools

You are working in the HEE-Rx8-Reverse-Engineering repo. The `heeRe.*` MCP tools
give you a live SH-2E emulator + debugger over the real ROMs, plus ROM/label/diff
helpers. Follow the repo rules in `AGENTS.md` (evidence ladder, immutable binaries,
binary-level verification, report format) — the tools are for *producing evidence*,
not for asserting conclusions.

## Typical workflows

1. **Orient:** `hee_rom_list` → profiles + ROMs; `hee_rom_info` on a dump
   (fw/cal IDs at 0x2000/0x6c046, SHA-256); `hee_manifest_check`.
2. **Boot and explore dynamically:** `hee_boot {profile: "60E15120_N3J1E", cycles: N}`
   → `hee_state` (pc, heartbeats = firmware alive). Set inputs with `hee_set_sensor`
   (sensors are wired to the real ADC ADDRn channels / ATU-II crank capture, not
   placeholder registers), `hee_run` more, watch outputs via `hee_state` (`watch`,
   e.g. engine load at RAM 0xffffc0b4, rpm at 0xffff9f80). For function-level
   dynamic checks (e.g. call a ROM helper and read r0/fr0), use
   `utilities/scripts/emu/harness.py` (`harness.call`) — see
   `tests/test_phase1_dynamic.py` for examples (knock clamp 0x13bd2, injector
   map 0x8a68 vs ROM 0xd7d4, math helpers vs the reimplementation, RCAN/UDS).
3. **Debug a function:** `hee_break` at the address (from `hee_labels` or
   `hee_disasm_rom`), `hee_continue`, then `hee_step` / `hee_regs` / `hee_mem` /
   `hee_disasm` at the stop. Watchpoints (`hee_watch`) catch RAM/ MMIO writes —
   use them to find who writes a variable. The SH7055 UBC model is available for
   hardware-style breaks.
4. **Static reading:** `hee_disasm_rom {rom_id, addr, n}` reads the committed
   disassembly; `hee_labels {rom_id, query}` searches label TSVs/JSON
   (candidate_/ref_/CAL_ prefixes carry evidence strength — never upgrade without
   new evidence).
5. **Diff binaries:** `hee_diff_roms {a, b}` — e.g. tuned streetport vs stock
   `binaries/dumps/aron-N3ZHEC-2026-10-31.bin`; record ranges in an investigation doc.
6. **Drive-cycle validation:** `hee_replay_load` a `data/logs/` CSV, then
   `hee_replay_step` per row; compare emulated watch values against the log columns.

## Rules while using the tools

- Every claim in docs must trace to an address + evidence; run the binary-level
  verification (pipeline validators) before claiming a labeling pass done.
- Write findings to `docs/investigations/<rom-id>/` (10-section report format),
  data to `data/`, scripts to `utilities/scripts/`. Never edit `binaries/` or
  `submodules/`.
- Emulator traces you produce should be diffed against goldens / the Renesas
  simulator (`compare_traces.py`) before being trusted (see ROADMAP E1–E7 limits).
  The Renesas tool is not installed on every machine; without it, run the
  self-check against `tests/fixtures/boot-60E15120_N3J1E-200k.trace` and record
  that external validation is pending.
- When in doubt about hardware behavior, cite `Sh7055h.pdf` by table/section and
  `13Electrical.pdf` (ground truth) for wiring.
