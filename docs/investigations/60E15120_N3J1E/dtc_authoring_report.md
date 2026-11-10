# Authoring a new DTC in the RX-8 PCM — checklist + raise path — 60E15120_N3J1E (SH7055 / SH-2E)

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — documentation only). Findings are from static analysis
of the canonical export, the disassembly and the raw ROM bytes (byte dump:
[`reviews/dtc_authoring/tables_dump.txt`](reviews/dtc_authoring/tables_dump.txt));
no hardware execution was performed. This report is the **authoring guide**: it lists
every ROM/RAM address a **new** DTC must touch (§3 checklist) and what its raise call
triggers (§2). The complete DTC chain — engine, state bytes, MIL/CAN, E2RAM key-off
persistence, scanner readout, UDS 0x85 — is documented in
[`dtc_control_report.md`](dtc_control_report.md) §1–§2b and cross-referenced from here.

**Related reports:** the entire DTC chain — engine, slots, state bytes, enable
gates, MIL/CAN, E2RAM key-off persistence (§2b), end-to-end flowchart (§2a), readout
services, UDS 0x85 — in
[`dtc_control_report.md`](dtc_control_report.md); key-off persistence codec in
[`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) and the device layer in
[`e2ram_device_layer_report.md`](e2ram_device_layer_report.md); a concrete detection
site (charging P2502/P2503/P2504) in
[`alternator_control_report.md`](alternator_control_report.md); the UDS service table
and Mode 22 dispatcher in
[`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md); OS event plumbing
(group-2 event 2, table 0x67d00) in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md).

## 1. Executive summary

- A DTC is addressed by a **fault argument** (`arg`, r4 of the set-fault call) that
  maps to a **slot** through ROM table **0x7df42** (BE u16 per arg, args 0x00–0x8b;
  many-to-one from arg 0x15 on — e.g. args 0x7b/0x7c/0x7d → slots 0x71/0x72/0x73).
  The slot indexes the OBD code table **0x7e560** (BE u16 per slot, 140 slots),
  enable switches **0x7e678 / 0x7e704 / 0x7e790**, type byte **0x7e32a** and
  confirmation mask **0x7e81c**; the status mask **0x7e934** (u32) and monitor-source
  mask **0x7e29e** (u8) are **arg**-indexed (`ref_getFaultStatus__` 0x66a00 does
  `0x7e934 + 4*arg` directly). Table semantics and the runtime chain:
  [`dtc_control_report.md`](dtc_control_report.md) §1–§2.
- **Free capacity:** all 140 slots carry a stock code, but slots **0x79–0x8b hold code
  0xffff** with stock enable#1=#2=0 (19 free slots), and 11 more slots carry a real
  code with stock enable#1=#2=0 (0x07/0x08/0x35/0x36/0x38/0x3c/0x3d/0x48/0x71/0x72/
  0x73 = P0076/P0077/P0480/P0481/P0505/P0564/P0571/P1260/P2502/P2503/P2504) and can be
  repurposed. Authoring a code = write its BE u16 at `0x7e560 + 2*slot`, set the
  slot's config bytes, bind an arg at `0x7df42 + 2*arg`, call the set-fault thunk —
  the full checklist is §3.
- **Raise:** call **0x5fd38(arg, mode)** (71 existing call sites; mode 1 = fault
  active, 2 = healed, 4 = confirm; charging example 0x545bc
  `0x5fd38(0x7b, b5b1==0 ? 2 : 1)` → slot 0x71 → P2502). Everything after the call —
  gates (0xffffd688 eval-on from UDS 0x85, conf mask 0x5f9c2, enable#3 0x5f9b0),
  transition 0x60062, master table, MIL, readout — is stock engine behavior, mapped
  end-to-end in [`dtc_control_report.md`](dtc_control_report.md) §2/§2a.
- **Persistence is opt-in per arg:** only the 19 args hardcoded in 0x242ae/0x23f4e
  survive key-off (E2RAM; chain in [`dtc_control_report.md`](dtc_control_report.md)
  §2b). Arg 0x83 — pre-wired to free slot 0x79 — is on the list, so the patcher
  example below persists; the charging args 0x7b–0x7d are not.
- **Readout is automatic** once stored (Mode 03/07/02/06, Mode 22 0x0200/0x0202,
  UDS 0x18; no 0x19/0x1a) — [`dtc_control_report.md`](dtc_control_report.md) §2; the
  authoring view is checklist row 13.

## 1a. Plain-language summary

Think of a DTC as a row in a fixed 140-row table — how the engine treats those rows
(state bytes, switches, aging) is explained in
[`dtc_control_report.md`](dtc_control_report.md) §1a. Adding a new code means: pick a
free row (rows 0x79–0x8b are empty), write the P-code into the code table, set the
row's switches, bind a fault number to the row in the arg→slot table, and call the
set-fault function from your monitor with that fault number. If you want the code to
survive key-off, also add the fault number to the EEPROM collect and replay lists
(§3 row 12); they have free flag bits. Everything the engine then does — aging, lamp,
scanner output — happens automatically; the whole chain is diagrammed in
[`dtc_control_report.md`](dtc_control_report.md) §2a.

## 2. What your raise call triggers (chain slice)

The complete end-to-end chain — detection → set → gates → transition → master table
→ MIL/CAN → E2RAM persistence → scanner readout → clear/UDS 0x85 — is documented
with full pseudocode and a flowchart in
[`dtc_control_report.md`](dtc_control_report.md) §2/§2a/§2b; the ROM tables involved
are listed in §8.3 below. What an author needs to know about the call itself:

```python
# --- ROM tables a new DTC lives in (semantics in dtc_control_report.md §2; dump in §8.3) ---
id2slot   = u16be @ 0x7df42 + 2*arg        # fault arg -> slot (args 0x00..0x8b; tail at 0x7e05a unreferenced)
code_tbl  = u16be @ 0x7e560 + 2*slot       # slot -> OBD code (BE = the two mode-03 response bytes)
enable1   = u8    @ 0x7e678 + slot        # def "Enable/Disable #1" (MIL/aging gate)
enable2   = u8    @ 0x7e704 + slot        # def "#2" (Mode-03 visibility gate)
enable3   = u8    @ 0x7e790 + slot        # def "#3" BITMASK 0x02/0x04/0x08/0x10/0x20
dtc_type  = u8    @ 0x7e32a + slot        # 0..3 -> aging state machine
conf_mask = u16be @ 0x7e81c + 2*slot      # confirmation gate (0x5f9c2)
status_msk= u32be @ 0x7e934 + 4*arg       # ARG-indexed; ANDed with RAM 0xffffd930 in 0x66a00
mon_src   = u8    @ 0x7e29e + arg         # ARG-indexed monitor-source mask (0x5fb68)
related   = u32be @ 0x7e06c + 4*slot      # per-slot related record; low byte = the arg

# --- detection site: call the set-fault thunk (71 call sites) ---
0x5fd38(arg, mode)                          # mode 1 = fault active, 2 = healed, 4 = confirm
  -> 0x5fe20 dtc_set_fault(arg, mode, x):
       slot = id2slot[arg]
       gates: 0xffffd688 eval on (UDS 0x85)? conf mask 0x5f9c2? enable#3 0x5f9b0?
       -> 0x60062 dtc_state_transition / 0x601cc direct store / OS event (2,2) -> 0x61092
       # everything downstream (master table 0xffff87b0, MIL 0x5a130 -> 0xffffd286,
       # CAN status, E2RAM persistence, scanner readout) is automatic:
       # dtc_control_report.md §2/§2a/§2b
```

## 2a. End-to-end flowchart

The end-to-end flowchart of the whole DTC chain (detection → engine → RAM → MIL/CAN
→ E2RAM persistence → scanner readout, including the UDS 0x85 gate and the clear
path) is in [`dtc_control_report.md`](dtc_control_report.md) §2a.

**How to add a DTC** (what the example patcher
[`patch_new_dtc_trigger.py`](../../../utilities/scripts/patchers/patch_new_dtc_trigger.py)
automates): pick free **slot 0x79** (arg **0x83** is pre-wired to it), write the code
at `0x7e560+2*0x79` (e.g. 0x1F01 = P1F01), set enable#1/#2 at `0x7e678/0x7e704+0x79` =
1, and call `0x5fd38(0x83, 1)` from your monitor — everything downstream then happens
automatically (chain: [`dtc_control_report.md`](dtc_control_report.md) §2a). Because
arg 0x83 is already in the 0x242ae/0x23f4e persistence lists, key-off persistence
works too ([`dtc_control_report.md`](dtc_control_report.md) §2b). The patcher hooks
the trigger into the periodic `dtc_fault_service_batch` 0x118d0 via a code cave,
preserving stock behavior.

## 3. What a new DTC must touch (the authoring checklist)

Everything below is ROM-verified (byte dump:
[`reviews/dtc_authoring/tables_dump.txt`](reviews/dtc_authoring/tables_dump.txt)).
A working example that applies this checklist to a ROM copy — new code on free slot
0x79 / arg 0x83 plus a cave trigger hooked into the periodic DTC service batch —
lives in
[`utilities/scripts/patchers/patch_new_dtc_trigger.py`](../../../utilities/scripts/patchers/patch_new_dtc_trigger.py)
(spec: [`PATCHER_new_dtc_trigger.md`](../../../utilities/scripts/patchers/PATCHER_new_dtc_trigger.md),
tests: [`tests/test_dtc_trigger_patcher.py`](../../../tests/test_dtc_trigger_patcher.py)).

| # | Touch | Address (60E15120_N3J1E) | Notes |
|---|---|---|---|
| 1 | Free slot | slots **0x79–0x8b** (19 slots) | stock code 0xffff, enable#1/#2 = 0; or repurpose a disabled real-code slot (0x07/0x08/0x35/0x36/0x38/0x3c/0x3d/0x48/0x71/0x72/0x73) |
| 2 | OBD code | **0x7e560 + 2*slot** (BE u16) | these two bytes are exactly what Mode 03/0x18 emit; 0x0420 → P0420 decoding per SAE J2012 (see [dtc_control_report.md](dtc_control_report.md) §5b) |
| 3 | arg → slot binding | **0x7df42 + 2*arg** (BE u16) | args 0x00–0x8b; many-to-one allowed (e.g. args 0x15/0x16 share slot 0x15); tail entries at 0x7e05a exist for args ≥ 0x8c but no code references that base (unreferenced) |
| 4 | Enable switches | **0x7e678 + slot** (#1), **0x7e704 + slot** (#2), **0x7e790 + slot** (#3 bitmask) | #1 gates MIL+aging, #2 gates Mode 03/freeze frame, #3 bits gate set/confirm/store/heal/report (0x02/0x04/0x08/0x10/0x20); the defs' `DTC xxxx Enable/Disable #N` tables are generated from these exact bytes |
| 5 | Type byte | **0x7e32a + slot** | 0 = default aging machine 0x60ca6; stock uses 1/2/3 only for slots 0x00/0x01/0x1e/0x1f |
| 6 | Confirmation mask | **0x7e81c + 2*slot** (BE u16) | gates confirmation in 0x5f9c2; stock P2502 slot 0x71 has 0xfffc |
| 7 | Status mask | **0x7e934 + 4*arg** (BE u32) | **arg-indexed**; low 16 ANDed with RAM 0xffffd930, high 16 with 0x66a58() mask in `ref_getFaultStatus__` 0x66a00 — needed if the code should be E2RAM-persisted or readable via 0x66a00 |
| 8 | Monitor-source mask | **0x7e29e + arg** (u8) | ANDed with 8 monitor checks in 0x5fb68 (ptr table 0x604f8), gates the mode-1 store |
| 9 | Related record | **0x7e06c + 4*slot** (BE u32) | low byte conventionally = the arg (slot 0x71 → 0x1100007b); nibbles select eval-state caching in 0x5ff5a |
| 10 | Detection site | call **0x5fd38(arg, mode)** | mode 1 active / 2 healed / 4 confirm; example 0x545bc; 71 existing call sites |
| 11 | MIL / CAN | nothing to add | automatic via 0x5a130 → 0xffffd286, 0x55278 into the CAN status message (0x54d90); a separate warning lamp is a plain flag like 0x26760 → 0xffffb5b4 |
| 12 | Key-off persistence (optional) | add the arg to **0x242ae** (collect) **and 0x23f4e** (replay) with a free flag bit (arg↔flag-byte map below) | only the 19 stock args persist; save/load chain, staging cells and codec in [dtc_control_report.md](dtc_control_report.md) §2b |
| 13 | Readout | nothing to add | Mode 03/07/02/06, Mode 22 0x0200/0x0202, UDS 0x18 all emit from 0x7e560 once stored (services in [dtc_control_report.md](dtc_control_report.md) §2); **no UDS 0x19/0x1a** — adding ReadDTCInformation would need a new record in service table 0x5eb40 + handler |
| 14 | Defs | regenerate per-ROM defs (`extend_defs_all_roms.py`) | `DTC xxxx Enable/Disable #N` entries are rebuilt from the ROM tables automatically, so #1/#2/#3 addresses track any slot change |

Persisted-arg ↔ flag-byte map (from decompiled 0x23f4e; mode 1 / mode 2 bits):

| arg | replay flag bytes (RAM) | | arg | replay flag bytes (RAM) |
|---|---|---|---|---|
| 0x14 | 0xffffb500 / 0xffffb501 | | 0x5f | 0xffffb510 / 0xffffb511 |
| 0x13 | 0xffffb503 / 0xffffb504 | | 0x60 | 0xffffb512 / 0xffffb513 |
| 0x6a | 0xffffb50a / 0xffffb50b | | 0x6b | 0xffffb514 / 0xffffb515 |
| 0x22 | 0xffffb505 / 0xffffb506 | | 0x42 | 0xffffb518 / 0xffffb519 |
| 0x21 | 0xffffb507 / 0xffffb508 | | 0x84 | 0xffffb516 / 0xffffb517 |
| 0x47 | 0xffffb4f0 / 0xffffb4f1 | | 0x5b | 0xffffb4f7 / 0xffffb4f8 |
| 0x64 | 0xffffb4f3 / 0xffffb4f4 | | 0x5c | 0xffffb4f9 / 0xffffb4fa |
| 0x5d | 0xffffb4f5 / 0xffffb4f6 | | 0x83 | 0xffffb4fb / 0xffffb4fc |
| 0x4f | 0xffffb50c / 0xffffb50d | | 0x65 | 0xffffb4fd / 0xffffb4fe |
| 0x61 | 0xffffb50e / 0xffffb50f | | | |

Collect-side staging bytes (0x242ae): 0xffffb4dc (args 0x13/0x14), 0xffffb4dd (0x6a),
0xffffb4de (0x21/0x22), 0xffffb4df (0x47), 0xffffb4e0 (0x64), 0xffffb4e1 (0x5d),
0xffffb4e2 (0x5b/0x5c), 0xffffb4e3 (0x83), 0xffffb4e4 (0x65), 0xffffb4e5 (0x4f),
0xffffb4e6 (0x61), 0xffffb4e7 (0x5f), 0xffffb4e8 (0x60), 0xffffb4e9 (0x6b),
0xffffb4ea (0x42 with rpm ≥ 7500 and load < 13.48 condition), 0xffffb4eb (diag-mode
0xffffd43d/0xffffd1c5), 0xffffb51c (0xffffbd48 clear). Encode (0x244bc) packs these
into block bytes 0xffffb459–0xffffb45d.

## 4. Labeling applied

None. Every function/RAM/table cited already carries a label
(`dtc_engine_labels.tsv`, `e2ram_nv_storage_labels.json`,
`e2ram_device_labels.json`, `alternator_labels.json`); no label was added,
renamed or upgraded, and no decompiled artifact was modified.

## 5. Corrections and new findings

- **Free slot capacity identified from ROM:** slots 0x79–0x8b hold code 0xffff with
  enable#1=#2=0 (19 slots) — the natural home for a new code; 11 further slots carry
  a real code but ship disabled (enable#1=#2=0: slots 0x07, 0x08, 0x35, 0x36, 0x38,
  0x3c, 0x3d, 0x48, 0x71, 0x72, 0x73 = P0076/P0077/P0480/P0481/P0505/P0564/P0571/
  P1260/P2502/P2503/P2504).
- **Save trigger traced:** the callgraph shows **0x64ba** (task[9] entry) → **0x1150e**,
  which contains the E2RAM save (thunk → 0x236cc) — the open question "who calls
  0x1150e" from [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) §9 is
  answered at callgraph level: the save runs inside the task[9] batch (chain:
  [`dtc_control_report.md`](dtc_control_report.md) §2b).
- **Service table dumped from ROM bytes:** 29 records at 0x5eb40; services 0x19 and
  0x1a are absent (confirming at byte level that ReadDTCInformation is not
  implemented on this PCM — readout is Mode 03/07 + 0x18 + Mode 22 0x0200/0x0202).
- **id2slot is many-to-one, not identity:** from arg 0x15 on, two args share a slot
  (arg 0x15/0x16 → slot 0x15, ..., args 0x7b/0x7c/0x7d → slots 0x71/0x72/0x73 →
  P2502/P2503/P2504). ROM also contains continuation entries at 0x7e05a (args 0x8c.. →
  slots 0x82..), but no literal-pool word references that base — treated as an
  unused tail.
- **Status-mask table is arg-indexed** (0x7e934 + 4*arg in 0x66a00), while the code/
  enable/type tables are slot-indexed — a new DTC must get both indexings right
  (§3 rows 3, 7, 8).
- **The set-fault "thunks" are verified direct trampolines, not indirect calls:**
  0x5fd38 is `bra 0x5fe20` + delay `mov #0,r6` (x fixed to 0; 71 callers) and 0x5fd3c
  defaults r6 to 0xffff (pool 0x5fe0c) before the same tail-call; 0x5fe20's only
  callers are these two. 0x5fd4a is a plain setter of the eval-enable flag 0xffffd688
  (pool 0x5fe10). Labels promoted from `FUN_0005fd38` /
  `ref_updateFaultStatusTHUNKNoR6_` (a misnomer — the body is set_fault, not a status
  update) to `dtc_set_fault_x0` / `dtc_set_fault_xdefault` / `dtc_set_eval_enable`
  (record: `data/labels/60E15120_N3J1E/dtc_thunk_labels.json`, aliases in
  `source_review/accepted_function_aliases.tsv`, applied to the export; test
  `tests/test_dtc_set_fault_thunk.py`).

## 6. Files

- `docs/investigations/60E15120_N3J1E/dtc_authoring_report.md` — this report.
- `docs/investigations/60E15120_N3J1E/reviews/dtc_authoring/` —
  [`dump_dtc_authoring_tables.py`](reviews/dtc_authoring/dump_dtc_authoring_tables.py)
  (re-runnable ROM evidence dump),
  [`tables_dump.txt`](reviews/dtc_authoring/tables_dump.txt) (its output),
  [`README.md`](reviews/dtc_authoring/README.md) (evidence notes),
  `validation.json` (validator results).
- Cross-links in [`dtc_control_report.md`](dtc_control_report.md) and
  [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) (Related reports sections).
- `utilities/scripts/patchers/patch_new_dtc_trigger.py` +
  [`PATCHER_new_dtc_trigger.md`](../../../utilities/scripts/patchers/PATCHER_new_dtc_trigger.md) —
  example patcher implementing this report's checklist (emulator-validated by
  [`tests/test_dtc_trigger_patcher.py`](../../../tests/test_dtc_trigger_patcher.py)).

## 7. Validation

- Binary level (rule 7), checked against the raw ROM
  (SHA-256 `a7cd953c…`): DTC table region dumped byte-exact
  (`reviews/dtc_authoring/tables_dump.txt`): id2slot 0x7df42, code table 0x7e560,
  prefix 0x7e55a, enables 0x7e678/0x7e704/0x7e790, type 0x7e32a, conf 0x7e81c,
  status 0x7e934, monitor mask 0x7e29e, related 0x7e06c, service table 0x5eb40;
  literal-pool words pointing at those tables located in ROM (e.g. 0x5ff1c, 0x60134,
  0x6027c, 0x66c38 → 0x7df42; 0x60928, 0x669f4 → 0x7e560; 0x66bfc → 0x7e934) and
  cross-checked against `non_instruction_ranges_classified.tsv`; set/transition
  disassembly re-read at 0x5fe20 / 0x60062 / 0x601cc (arg*2 indexing of 0x7df42,
  mode dispatch on r5 = 2/4/1/0, store path writing 0xffffd570[slot] and first-code
  0xffffd3c0); call counts from `callgraph.tsv`: 0x5fd38 = 71 callers,
  0x66a00 = 80 callers, 0x64ba → 0x1150e edge present.
- Pipeline validators run from the repo root: `validate_export.py`,
  `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`, plus `python -m pytest tests/` — results recorded in
  [`reviews/dtc_authoring/validation.json`](reviews/dtc_authoring/validation.json).
- Dynamic proof of the reporting half of the chain:
  [`reviews/dtc_control/dynamic_validation_log.txt`](reviews/dtc_control/dynamic_validation_log.txt).

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Label | Role in the DTC path |
|---|---|---|
| 0x0005fd38 | `dtc_set_fault_x0` — set-fault trampoline (x=0) | raise entry, 71 callers; (arg, mode) |
| 0x0005fd3c | `dtc_set_fault_xdefault` — trampoline defaulting x to 0xffff when r6==0 | 2 callers (0x44724, 0x44cec) |
| 0x0005fd4a | `dtc_set_eval_enable` | writes 0xffffd688; callers 0x5fd6c (boot), 0x5dde8 (UDS 0x85) |
| 0x0005fe20 | `FUN_0005fe20` — dtc_set_fault | core set path; arg→slot via pool 0x5ff1c = 0x7df42 |
| 0x00060062 | `FUN_00060062` — dtc_state_transition | modes 1/2/4 (r5), type via pool 0x60138 = 0x7e32a |
| 0x000601cc | `FUN_000601cc` — dtc_mark_stored | 0xffffd570[slot]=1, first code 0xffffd3c0 (pool 0x60278) |
| 0x00061092 | `FUN_00061092` | OS group-2 event-2 handler → master table |
| 0x000612ee | `FUN_000612ee` — dtc_aging_sweep | per-type aging, from 0x1102a |
| 0x00066a00 | `ref_getFaultStatus__` | status query: 0x7e934 + 4*arg vs RAM 0xffffd930; 80 callers |
| 0x0005a130 | `ref_faultSomething0x1` — dtc_update_mil_flag | MIL flag 0xffffd286 (from 0x1102a, 0x118d0) |
| 0x0005a188 | `FUN_0005a188` | distance-while-MIL 0xffff90f4 |
| 0x00055278 | `FUN_00055278` | CAN status word = stored count \| 0x80 |
| 0x00054d90 | `FUN_00054d90` | CAN status message builder (case 0 → 0x55278) |
| 0x00026760 | `candidate_alternator_warning_light_flag` (inherited `ref_setAlternatorWarningLight`) | separate warning-lamp flag 0xffffb5b4 |
| 0x000545bc / 0x00054590 / 0x000545a6 | `candidate_charging_dtc_raise_p2502/_p2503/_p2504` | detection-site examples: 0x5fd38(0x7b/0x7c/0x7d, 1\|2) |
| 0x000242ae | `e2ram_fault_status_collect` | persist collect: 18× 0x66a00 → 0xffffb4dc–0xffffb4eb |
| 0x00023f4e | `e2ram_stored_dtc_replay` | persist replay: 38× 0x5fd38(arg, 1\|2) |
| 0x00023844 / 0x000244bc | `e2ram_block_decode` / `e2ram_block_encode` | E2RAM block codec; fault bits 0xffffb48a–0xffffb490 ↔ 0xffffb459–0xffffb45d |
| 0x0002376c / 0x0002377a | `e2ram_load_decode_entry` / `e2ram_save_encode_entry` | load / save wrappers |
| 0x000235c8 / 0x000235f8 / 0x000236cc | `FUN_000235c8` / `FUN_000235f8` / `FUN_000236cc` | load / verify / save drivers |
| 0x0001150e | `FUN_0001150e` | periodic batch containing the save; called from 0x64ba |
| 0x000064ba | `candidate_knock_sensor_fault_task` | task[9] entry → 0x1150e |
| 0x00057db0 / 0x00058168 | `candidate_uds_service_18` / `FUN_00058168` | Mazda UDS 0x18 readout (record 0x5ec0c); 0x58168 sets 0xffffd228 |
| 0x00065ff8 / 0x000661ec / 0x00065c88 / 0x0006725c | `obd_mode03_stored_dtc` / `obd_mode07_pending_dtc` / `obd_mode02_freeze_frame` / `obd_mode06_test_results` | scanner readout |
| 0x000667c8 | `FUN_000667c8` — dtc_build_response_codes | slot→code emission from 0x7e560 |
| 0x00061450 / 0x000615c6 | `FUN_00061450` / `FUN_000615c6` | master-table count / list scanners |
| 0x0005fab2 / 0x0005fb08 | `candidate_dtc_count_stored` / `dtc_count_ram_table` | Mode 22 PIDs 0x0200 / 0x0202 (via 0x5774c, table 0x5f10c) |
| 0x000558ac | `uds_service_14_clear_diagnostic_information` | clear (Mode 04 shared) |
| 0x0005dc44 | `uds_service_85_control_dtc_setting` | UDS 0x85 handler (record 0x5eba0) |
| 0x0005dde8 | `ref_setDiagMode85Bool2` | 0x85 sub 1/2 -> dtc_set_eval_enable(1/0) + 0xffffd378 |
| 0x0005ddb4 | `ref_setDiagMode85Bool_` | auto re-enable when 0xffffd37a >= 0x271 and 0xffffd378==1 |
| 0x0005de18 | `FUN_0005de18` | builds positive response 58 85 sub |
| 0x00066a58 | `FUN_00066a58` | high-half status mask builder |
| 0x0005f9b0 / 0x0005f9c2 / 0x0005ff5a / 0x0005fb68 | `ref_faultEnableStatus2` / `ref_faultConfirmationSomething_` / `FUN_0005ff5a` / `FUN_0005fb68` | enable#3, conf-mask, eval-state, monitor-source gates |

### 8.2 RAM

| Address | Label | Content |
|---|---|---|
| 0xffff87b0 | `dtc_master_table_21` | 21 × 0x10 B master entries (slot +0, state +6, priority +0x0d) |
| 0xffff8900 | `dtc_master_current_index` | u16, skipped by scans |
| 0xffffd570 | `dtc_ram_flag_table_ffffd570` — dtc_stored_flag_table | 0x8c stored flags |
| 0xffffd5fc | `dtc_state_array` | 0x8c state mirror |
| 0xffffd458 | `dtc_eval_state_array` | 0x8c eval states |
| 0xffffd4e4 | `dtc_transition_state_array` | 0x8c transition states |
| 0xffffd3c0 | `dtc_first_stored_code` | u16 |
| 0xffffd286 | `mil_lamp_flag` | MIL flag |
| 0xffffd688 | `dtc_eval_enable` | global eval enable (UDS 0x85) |
| 0xffffd930 | `dtc_status_bits` | u32 ANDed with 0x7e934 masks in 0x66a00 |
| 0xffffd228 | `DAT_ffffd228` | UDS 0x18 report selector (0x58168) |
| 0xffffd378 | `DAT_ffffd378` | UDS 0x85 "setting off" flag (0x5dde8/0x5ddb4) |
| 0xffffd37a | `DAT_ffffd37a` | UDS 0x85 off-counter, re-enable threshold 0x271 (0x5dd78/0x5de3c) |
| 0xffff90f4 | `distance_mil_on_ffff90f4` | distance-while-MIL (PID 0x21) |
| 0xffffb440 / 0xffffb478 | `e2ram_staging_block` / `e2ram_read_staging` | 28-u16 E2RAM block (save / load) |
| 0xffffb459–0xffffb45d | packed fault bits (encode, 0x244bc) | save side |
| 0xffffb48a–0xffffb490 | raw packed fault bytes (read staging) | load side, unpacked by 0x23844 |
| 0xffffb4dc–0xffffb4eb, 0xffffb51c | collect staging (0x242ae) | live fault-status bytes |
| 0xffffb4ec–0xffffb51b | `stored_dtc_flag_bits` | unpacked flags read by 0x23f4e |
| 0xffffb5b4 | `inferred_ram_b5b4_ffffb5b4` | alternator warning flag, from 0x26760 → CAN 0xffffbab2 bit 0x40 |

### 8.3 ROM tables (60E15120_N3J1E)

| Address | Content |
|---|---|
| 0x7e55a | P0300/P0301/P0302 prefix codes |
| 0x7e560 | DTC code table, 140 × BE u16 (slots 0x79–0x8b = 0xffff free) |
| 0x7df42 | arg → slot map, BE u16 per arg 0x00–0x8b (tail entries at 0x7e05a, unreferenced) |
| 0x7e678 / 0x7e704 / 0x7e790 | enable #1 / #2 / #3 per slot |
| 0x7e32a | type byte per slot |
| 0x7e81c | confirmation mask, u16 per slot |
| 0x7e934 | status mask, u32 per **arg** |
| 0x7e29e | monitor-source mask, u8 per **arg** |
| 0x7e06c | related/type records, u32 per slot (low byte = arg) |
| 0x5eb40 | UDS service dispatch table, 29 × 12 B (no 0x19/0x1a; 0x18 record at 0x5ec0c → 0x57db0) |
| 0x5f10c | Mode 22 PID table (0x0200/0x0202 → 0x5fab2/0x5fb08 via 0x5774c) |
| 0x67d00 | OS event table (group-2 event 2 → 0x61092) |

## 9. Limits

- **MIL lamp pin not traced to a package pin** — 0xffffd286 and the CAN status word
  (0x55278 via 0x54d90) are verified, but whether the cluster drives the lamp from
  that CAN word or the PCM drives a GPIO is board-level routing
  ([docs/architecture/hardware/](../../architecture/hardware/)).
- **UDS 0x19 / 0x1A are not implemented** (absent from the 0x5eb40 service table,
  ROM-verified; readout services listed in
  [`dtc_control_report.md`](dtc_control_report.md) §2/§9): adding one means a new
  service-table record + handler.
- **Key-off persistence covers only the 19 hardcoded args** (§3; save/load chain in
  [`dtc_control_report.md`](dtc_control_report.md) §2b). A new arg needs
  edits in both 0x242ae and 0x23f4e plus a free flag bit; the arg→flag-byte map is
  from the decompiled replay, and the packed-bit placement is verified at byte level
  (0xffffb459–0xffffb45d save / 0xffffb48a–0xffffb490 load), not bit-by-bit.
- **Save cadence** is known only to callgraph level (task[9] 0x64ba → 0x1150e); the
  exact trigger condition inside 0x1150e was not traced.
- **Aging/confirmation counters** (0x60ca6/0x64918/0x64972/0x6400a) remain
  statically read only — see [dtc_control_report.md](dtc_control_report.md) §9.
- The **0x7e05a tail** of the arg→slot table exists in ROM but no code references it;
  treated as unused. Using args ≥ 0x8c requires finding the referencing code path
  first.
- Static analysis only; dynamic proof of the reporting half:
  [`reviews/dtc_control/dynamic_validation_log.txt`](reviews/dtc_control/dynamic_validation_log.txt).
