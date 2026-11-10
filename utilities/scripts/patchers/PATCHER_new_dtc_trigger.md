# patch_new_dtc_trigger.py — example: author a new DTC trigger into a ROM copy

Example patcher demonstrating the "how to author a DTC" map
(`docs/investigations/60E15120_N3J1E/dtc_authoring_report.md`). It adds **one new
DTC** to a *copy* of the stock ROM: slot **0x79** with fault arg **0x83**, which the
ROM already pre-wires (`id2slot[0x83] = 0x79` at `0x7df42+2*0x83`, related record
`0x11000083` at `0x7e06c+4*0x79`, and arg 0x83 is already in the E2RAM persistence
lists 0x242ae/0x23f4e). Slot 0x79 is free in stock (code 0xffff, enable#1/#2 = 0).

```sh
python3 utilities/scripts/patchers/patch_new_dtc_trigger.py \
    submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin \
    --code 0x1F01 --threshold 8000 --out patched/
# -> patched/60E15120_N3J1E_newdtc_1f01.bin (+ .json report)
# --code: new OBD code as BE u16 (default 0x1F01 = P1F01, manufacturer-specific —
#         the right class for a custom DTC). --threshold: trigger rpm (float).
```

## What gets patched (60E15120_N3J1E)

| Patch | Address | Value |
|---|---|---|
| DTC code table | 0x7e652 (= 0x7e560 + 2*0x79) | 0x1F01 (P1F01) |
| enable#1 (MIL/aging gate) | 0x7e6f1 (= 0x7e678 + 0x79) | 1 |
| enable#2 (Mode 03 visibility) | 0x7e77d (= 0x7e704 + 0x79) | 1 |
| hook pool word | 0x11ad8 (last entry of `dtc_fault_service_batch` 0x118d0, tail `jmp @r2` at 0x1196a) | code cave |
| code cave | first free 0xff run ≥ 0x80 from 0x6c000 (N3J1E: 0x7f760) | wrapper below |

Already stock-correct for the free slot, untouched: enable#3 0x20 (reportable),
type 0, conf mask 0, monitor-source mask 0xff, arg→slot wiring, related record.

The cave runs in place of the batch's last call (task[13] periodic batch): it calls
the stock 0x3809a first (behavior preserved), then evaluates the trigger —
`engine_speed_rpm` 0xffffb548 (float) > threshold — and on firing calls the stock
set-fault thunk `0x5fd38(0x83, 1, 0)`, exactly like the stock charging monitors
(0x545bc `0x5fd38(0x7b, …)`). Pending → confirmed → stored → MIL → Mode 03/07/22
readout all flow through the stock engine; because arg 0x83 is already in the
0x242ae/0x23f4e E2RAM lists, the code also persists across key-off.

## Safety / validation

- Stock .bin read-only; input SHA-256 asserted unchanged; every target byte must
  hold its expected stock/free value or the patcher refuses (SKIP); output asserted
  to differ only at the pool word, the 3 table bytes and the cave. Reference ROM
  pinned by SHA-256 (`a7cd953c…`); other ROMs SKIP with a reason (per-ROM table
  addresses are in `dtc_authoring_report.md` §8.3).
- Cave uses only volatile registers (r0/r1/r4-r6, fr0/fr1) + saved PR, and every
  emitted opcode exists in the emulator's corpus-derived opcode table, so the
  patched ROM boots and runs in the emulator.
- Emulator-validated: `python -m pytest tests/test_dtc_trigger_patcher.py` (5 tests)
  boots the patched ROM, fires the cave below/above threshold via `harness.call`,
  and proves the stored new DTC is emitted by the stock Mode-03-style path
  (0x615c6 → 0x667c8 → code 0x1F01) and lights the MIL flag (0x5a130 → 0xffffd286).
- **Not hardware-tested.** Nothing here flashes a vehicle; bench validation first
  (AGENTS.md rule 10). Preferred path: bench ECU over OBD (see ROADMAP F items).

## Extending

Change the condition in `build_cave` (any RAM cell + compare), the arg/slot pair
(`SLOT`/`ARG` — pick another pre-wired free pair, e.g. arg 0x84 → slot 0x7a), or the
code. For a cal-editable threshold, move the float into a RomRaider table cell in
the same free run (pattern: `patch_limiter_behavior.py`).
