# Live-tuning feasibility study (firmware patch + PC tooling + live logging) — 60E15120_N3J1E

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — this study changes no binaries). Static-analysis disclaimer: findings
come from the canonical export + disassembly + ROM bytes; the two measurements
marked "emulator" were produced by booting the real ROM in the SH-2E emulator
(`utilities/scripts/emu/`, 2M cycles to the idle loop 0x3dac) with RAM-write
tracking, and by scanning the ROM bytes for 0xFF runs.

**Related reports:** [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md)
(service/PID tables, checksum D3, seed/key D4, SBL flash path),
[os_scheduler_can_ivt_report.md](os_scheduler_can_ivt_report.md) +
[os_scheduling_deep_dive_report.md](os_scheduling_deep_dive_report.md) (CAN/ISO-TP/OS),
[design doc](../../architecture/design/README.md) (memory map, lookup layer),
[emulated-obd.md](../../architecture/emulated-obd.md) + [emulator-re-guide.md](../../architecture/emulator-re-guide.md)
(virtual OBD port, replay workflow), [learnings.md](../../learnings.md) (patcher
patterns, free cal-area run), patchers
[`PATCHER_limiter_behavior.md`](../../../../utilities/scripts/patchers/PATCHER_limiter_behavior.md).

## 1. Executive summary

**Verdict: feasible, in three tiers of increasing patch depth.** Inspiration from
aftermarket platforms (Haltech Elite-class: real-time table edits + high-rate
datalog over a PC link) maps cleanly onto this PCM because its diagnostic stack
is fully reversed and the ROM has measured free space.

- **Tier 0 — live logging on the stock ROM: works today, no patch.** Mode 22
  (service 0x22 → 0x567e8 → dispatcher 0x5774c → 99 PID records at 0x5f10c,
  mask 0xfffc = default session) plus UDS **0x23 ReadMemoryByAddress** (0x5b750)
  after security unlock 0x27 — the seed/key is fully reversed (fixed key string
  "MazdA" at 0x5f084, 64-round network 0x5609e; implemented by Rx8Man). 0x23
  reads arbitrary RAM/ROM, so every labeled RAM cell (load 0xffffc0b4, RPM
  0xffffb548, knock retard, …) is loggable, not just the 99 PIDs. Transport is
  CAN 0x7e0/0x7e8 ISO-TP on RCAN mailboxes 14/15 — the same pair that runs to
  the DLC (PCM terminals 4S CAN_L / 4V CAN_H), so a J2534 pass-through cable is
  the PC link on a real car.
- **Tier 1 — fast block logging patch: feasible, small.** A code cave (measured
  free flash, §3) adds a custom service (replace the 0xff terminator record at
  0x5ec90 in a patched image) that streams a hot-RAM block as multi-frame ISO-TP,
  or the tool simply uses 0x23 block reads. This is exactly the "fast RAM
  logging" patch already planned as ROADMAP F item 1.
- **Tier 2 — live tuning (writes while the engine runs): no stock write path,
  needs a patch, and it fits.** The 29-record service table at 0x5eb40 has **no
  0x2E WriteDataByIdentifier**; the app's 0x34/0x36/0x37 (0x5d7bc/0x5d834/0x5d874)
  are NRC stubs — real flashing exists only in the SBL BOOT mode
  (0x1ad6/0x1c04/0x1d30/0x1d78). CPU writes to flash are ignored (read-only), so
  live writes must target **RAM**: patch = new service record → cave handler →
  range-checked write via the firmware's own `ref_updateMemoryAtAddress_*` helpers
  (0x3dc70/0x3dcd0) under the critical-section pair 0x3920/0x3934, aimed at a
  **RAM shadow of selected calibration tables** (descriptor `data_ptr` repointed
  to RAM, buffer initialized from flash at boot by a cave hook in the init
  chain — the same cave pattern the existing patchers use). RAM budget is the
  binding constraint: a 2M-cycle emulator boot never writes
  **0xffff8000–0xffff92ff (4,864 B)**; excluding 8 labeled cells inside it, the
  largest contiguous free runs are **0xffff8901–0xffff90f3 (2,035 B)** and
  **0xffff807d–0xffff8787 (1,803 B)** — enough to shadow the hot tables (main
  fuel / ignition 3D + axes, knock, limiter), not the whole 80 KiB cal region.
  Corpus-wide cross-check: identical free-RAM numbers on all 11 ROMs, and
  per-ROM free-flash budgets 899 B–21,956 B, in
  [free_resources_report.md](free_resources_report.md).
- **Checksum is not a blocker.** The app CVN is a runtime-computed dual-u16
  additive sum over 0x2000–0x7ffff (skipping hole 0x7fb00–0x7fb7f), stored to
  RAM 0xffff9104/0xffff910c by 0x5a3f4/0x5a714 (D3); no boot-time verification
  exists in the app. A patch in the covered range just changes the reported CVN
  (Rx8Man already fixes this host-side; the algorithm is documented so our
  patcher can recompute it), and 120 B of CVN-neutral cave (0x7fb08–0x7fb7f)
  plus the SBL-region run (0xb0e–0xfff, 1,234 B, outside the checksum range) are
  available for code that must not move the CVN.
- **Safety:** SH-2E aligned 32-bit stores are single bus cycles, so per-cell
  writes to the shadow are tear-free (an interpolation may mix old/new adjacent
  cells for one cycle — same class of behavior as aftermarket ECUs). The real
  risk is a wrong-address write; mitigate with a strict shadow-range check and
  an optional engine-state gate in the handler. Per AGENTS.md rule 10 / ROADMAP
  group F, nothing flashes to a vehicle before emulator validation (virtual OBD
  port + real-car datalog replay) and BOOT-mode bench validation.

## 1a. Plain-language summary

Think of the PCM as already having a "read-only USB port": any laptop with a
$20 J2534 adapter can ask it for any engine value while driving (that is what
RomRaider Logger already does), and with the known Mazda seed/key it can even
dump any memory address. What it *cannot* do today is accept changes while
running — the firmware has no "write memory" diagnostic command, and its
calibration tables live in flash, which the CPU cannot write at runtime. The
study shows there is enough spare flash (~2.2 KiB of code caves) and spare RAM
(~2 KiB contiguous) to add both: a small patch that (1) copies the handful of
tables you actually tune into RAM at startup, (2) points the firmware's table
lookups at those RAM copies, and (3) adds a "write these bytes to that RAM
area" diagnostic command with a strict address check. The PC tool then logs
live (stock PIDs or a fast RAM-block stream) and edits table cells on the fly,
with every write read back to confirm. Haltech does the same thing over USB;
here the link is the car's CAN bus, which is slower but plenty for ~30 values
at 20–50 Hz plus occasional table writes.

## 2. How it works (condensed pseudocode)

```python
# ---- transport (stock, fully labeled) ----
# car:  DLC CAN-H/L  <-> PCM 4V/4S  <-> RCAN0 mailbox 14 (0x7e0 RX) / 15 (0x7e8 TX)
# ROM:  CAN RX IVT 0x378 -> 0x11d88 can_rx_poll_move_to_uds_buffer -> uds_rx_buffer 0xffffddc8
#       uds_service_entry 0x680a0 -> isotp 0x6842c -> schedule task -> 0x68dac scans
#       service table 0x5eb40 (29 x 12 B) -> handler; responses -> ch0 ring 0xffffd962
#       -> ref_pack_for_OBD_response_ 0x67e1c -> TX desc 0x4e00c (0x7e8)
#
# ---- Tier 0: live logging, stock ROM ----
# poll:  22 <pid16>            -> 62 <pid16> <payload>     (99 PIDs, default session)
# block: 27 <seed?> / 27 <key> -> unlock (0x57a64, key "MazdA" net 0x5609e)
#        23 01 06 <addr32> <size8> -> 63 <data...>         (0x5b750, range-checked)
# PC tool: J2534 passthrough on the car; emulator obd_port.py TCP for dev/validation
#
# ---- Tier 1: fast logging patch (ROADMAP F item 1) ----
# patched ROM: service table record {0xff terminator @0x5ec90} -> cave handler in free run
#   cave: on request, pack hot-RAM block (e.g. 0xffffa000-0xffffdfff subset) and emit
#         multi-frame ISO-TP on 0x7e8 via the stock TX path (0x4e00c / 0x67e1c)
#   (or unpatched: repeated 23 block reads of the same RAM range)
#
# ---- Tier 2: live tuning patch ----
# patched ROM pieces (all fit in measured caves, §3):
#   a) boot hook: repoint one pool word in the init chain (patcher cave pattern) ->
#      cave copies selected flash tables -> RAM shadow (largest free runs §3),
#      and rewrites those tables' descriptor data_ptr (flash, >HBBII / >HHIIIB)
#      to point at the RAM shadow. lookup_2d/3d_descriptor_scaled (0x2068/0x20dc)
#      follow the pointer at call time -> engine now reads the RAM copy.
#   b) write service: new/repurposed record in 0x5eb40 -> cave handler:
#        if addr in [shadow_lo, shadow_hi) and len sane:
#            sh_raise_interrupt_mask_return_previous (0x3920)   # critical section
#            for each cell: ref_updateMemoryAtAddress_8bit/32bit/float (0x3dc70/0x3dcd0)
#            ref_setSR (0x3934)
#            optional gate: reject unless tune_mode_ram flag set / rpm below limit
#        else: NRC 0x31
#   c) checksum: CVN recomputed at runtime (0x5a3f4) -> reported CVN changes; host
#      tool may fix up per Rx8Man pattern (D3 algorithm documented); CVN-neutral
#      caves available (0x7fb08-0x7fb7f, SBL 0xb0e-0xfff) for code that must not.
#
# ---- PC-side tool (new work, utilities/scripts/) ----
# python tool: ISO-TP/UDS over J2534 (car) or emu obd_port TCP (dev)
#   log loop:  poll PID list (22) and/or RAM block (23 / patched stream) -> CSV
#              (compare vs data/logs/*.csv golden logs)
#   tune loop: load table from data/maps/<rom>/ -> on cell edit: 0x2E-style write
#              (patched service) -> read-back verify -> optional "burn" = reflash
#              via Rx8Man SBL path to make the change permanent
```

## 3. Key tables / structures (measured on this ROM)

| What | Address | Detail |
|---|---|---|
| UDS service dispatch table | 0x5eb40 | 29 × 12 B `{svc<<24, handler, session-mask}`, terminator 0xff → nop stub 0x6689a at 0x5ec90 — the natural insertion point for a patched write service |
| Mode 22 PID table | 0x5f10c | 99 × 12 B records; most mask 0xfffc (default session) — stock live logging |
| Service 0x23 (read memory) | 0x5b750 | sub 01 06, requires 0x27 unlock (NRC 0x33) + address range check — stock arbitrary read |
| Write helpers (firmware's own) | 0x3dc70 / 0x3dcd0 / 0x3dd16 | `ref_updateMemoryAtAddress_8bit/float`, `ref_validateAddressCopy_8bit` — reuse in cave handler |
| Critical section | 0x3920 / 0x3934 | interrupt-mask pair for multi-cell writes |
| Lookup layer | 0x2068 / 0x20dc | `lookup_2d/3d_descriptor_scaled`; descriptors in flash before cal start (0x6c000), format `>HBBII` (2D) / `>HHIIIB`+pad (3D), axes f32 — repoint `data_ptr` to RAM shadow |
| Checksum | 0x5a3f4 / 0x5a714 | dual-u16 additive sum 0x2000–0x7ffff, skips 0x7fb00–0x7fb7f → RAM 0xffff9104/0xffff910c; no boot-time verify found |
| Seed/key | 0x55f5e / 0x5609e / 0x5f084 | 0x27 unlock; fixed key "MazdA" (Rx8Man implements) |

Free flash (0xFF runs ≥16 B scanned from ROM bytes, SHA-256 above):

| Run | Length | Checksum-covered? |
|---|---:|---|
| 0x7f760–0x7faff | 928 B | yes (cal-area tail; the patchers' cal/cave run) |
| 0x7fb08–0x7fb7f | 120 B | **no** (inside the 0x7fb00–0x7fb7f hole) — CVN-neutral cave |
| 0x7fb8c–0x7fc4f | 196 B | yes |
| 0x6bc7c–0x6bfff | 900 B | yes (descriptor-area gap) |
| 0x6c061–0x6c0df | 127 B | yes (cal area) |
| 0x5f026–0x5f03f, 0x6e280–0x6e297, 0x7e317–0x7e329, 0x7e652–0x7e677 | 26/24/19/38 B | yes (code-area gaps) |
| 0xb0e–0xfff | 1,234 B | **no** (SBL region, below 0x2000) — CVN-neutral, but respect flash block layout |

Total cave space ≈ 3.5 KB, of which ≈ 2.2 KB sits in the app image next to the
cal area (the patchers' established location) and 120 B + 1.2 KB are
CVN-neutral. A boot-copy hook + write-service handler + dispatch record fits
comfortably in the 928 B + 196 B runs.

Free RAM (emulator measurement: 2M-cycle boot to idle 0x3dac with per-byte write
tracking; "never written" after boot):

| Run | Length | Note |
|---|---:|---|
| 0xffff8000–0xffff92ff | 4,864 B | only never-written run ≥32 B in the 32 KiB RAM |
| — excl. labeled cells 0xffff8038/0xffff807c/0xffff8788/0xffff87b0/0xffff8900/0xffff90f4/0xffff90fc/0xffff9150 | | largest contiguous: **0xffff8901–0xffff90f3 (2,035 B)**, then **0xffff807d–0xffff8787 (1,803 B)** |

~2 KiB contiguous is enough for one 16×16 f32 3D table + axes, or a set of
smaller 2D tables — i.e. live-tune the hot tables (fuel, ignition, knock
clamps, limiter), not the whole cal region. Re-measure under drive-cycle replay
before committing to addresses (idle boot may under-use RAM — see §9).

CAN bandwidth (estimate, not measured on a real bus): typ. 500 kbit/s → an
8-byte classic frame ≈ 130 µs → ~7.5k frames/s theoretical; one Mode 22
exchange = SF request + SF response ≈ 2 frames, so several hundred PID
reads/s are realistic after arbitration with the PCM's own periodic TX
(0x201/0x231/0x240/… packers). Multi-frame ISO-TP (FF/CF, ROM dispatch
0x6859e/0x6872c) carries 4095 B per transfer — a hot-RAM block streams at tens
of Hz. Polling ~30 values at 20–50 Hz is comfortably within budget.

## 4. Labeling applied

None — this is a feasibility study; no labels changed. All cited labels already
exist in `data/labels/60E15120_N3J1E/` (see the related reports in the header).

## 5. Corrections made in this pass

None. (Two new measurements are recorded in §3: free-flash runs scanned from
ROM bytes; free-RAM runs measured by emulator write-tracking. Neither
contradicts an existing label.)

## 6. Files

- This report: `docs/investigations/60E15120_N3J1E/live_tuning_feasibility_report.md`
- `ROADMAP.md` — new F item 3 pointing at this study
- No binaries touched (`hash_binaries.py --check` unaffected); no code changed.

## 7. Validation

- ROM SHA-256 quoted above re-computed from the submodule ROM and unchanged
  (`a7cd953c…`); free-flash runs scanned from those bytes in this session.
- Free-RAM numbers produced by running the real ROM in the emulator
  (`emu.build`/`emu.run`, profile `60E15120_N3J1E`, 2M cycles, stop = cycle
  limit at idle pc 0x3dac) with `bus.write8/16/32` wrapped to record touched
  RAM bytes; largest free runs computed excluding the labeled cells listed.
  Re-measured corpus-wide (all 11 ROMs, free-flash scan + per-ROM boot) in
  [free_resources_report.md](free_resources_report.md) §7 — every figure quoted
  above for 60E15120_N3J1E matches that scan exactly.
- Stock-read-path claims rest on executed tests, not just statics:
  `tests/test_phase1_dynamic.py::test_mode22_dispatch_full_sweep` (all 99 PIDs
  through the ROM's own 0x5774c), `test_uds_service_router_routes` (15 services
  through 0x68dac), `test_obd_port_uds_log` (virtual OBD port end-to-end).
- `python utilities/scripts/rx8-pcm-pipeline/validate_reports.py` — PASS
  (sections, ROM hash, memory-map addresses vs index/TSVs).
- Not yet done (by design of a study): no patch was built, no write service
  executed, no real-car or bench run — see §9 and ROADMAP F.

## 8. Memory map for validation

### Functions

| Address | Name (function_index.tsv) | Role here |
|---|---|---|
| 0x00067e1c | `ref_pack_for_OBD_response_` | diag response packer (TX path) |
| 0x00068dac | `uds_service_dispatch_table_scan` | service router (table 0x5eb40) |
| 0x00057a64 | `uds_service_27_security_access` | seed/key unlock for 0x23 |
| 0x0005a3f4 | `FUN_0005a3f4` | checksum engine (D3) |
| 0x0005a714 | `FUN_0005a714` | checksum finalize → 0xffff9104/0xffff910c |
| 0x0005b750 | `uds_service_23_read_memory_by_address` | stock arbitrary read |
| 0x0005bc4c | `uds_service_2f_input_output_control` | closest stock "control" service |
| 0x0005df60 | `uds_service_31_routine_control` | routine dispatch (unmapped routines) |
| 0x0005d7bc | `uds_service_34_request_download` | app stub (NRC) — flash is SBL-only |
| 0x0005d834 | `uds_service_36_transfer_data` | app stub |
| 0x0005d874 | `uds_service_37_request_transfer_exit` | app stub |
| 0x0005774c | `diag22_find_and_dispatch_identifier` | Mode 22 dispatcher (table 0x5f10c) |
| 0x00055f5e | `FUN_00055f5e` | 0x27 seed generation |
| 0x0005609e | `FUN_0005609e` | 0x27 key verify ("MazdA" network) |
| 0x000567e8 | `uds_service_22_read_data_by_identifier` | Mode 22 entry |
| 0x000680a0 | `uds_service_entry` | UDS entry (CAN 0x7e0) |
| 0x00011d88 | `can_rx_poll_move_to_uds_buffer` | CAN RX → 0xffffddc8 |
| 0x00003c2a | `os_dispatch` | task dispatcher |
| 0x00009630 | `os_schedule_task_event` | scheduler |
| 0x00002068 | `lookup_2d_descriptor_scaled` | lookup layer (shadow repoint target) |
| 0x00003920 | `sh_raise_interrupt_mask_return_previous` | critical section |
| 0x00003934 | `ref_setSR` | critical-section restore |
| 0x0003dc70 | `ref_updateMemoryAtAddress_8bit_ADDR_VAL` | write helper for cave handler |
| 0x0003dcd0 | `ref_updateMemoryAtAddress_float_VAL_ADDR` | float write helper |
| 0x0003dd16 | `ref_validateAddressCopy_8bit_ADDRESS__` | address validation pattern |
| 0x00001ad6 | `FUN_00001ad6` | SBL 0x34 download (BOOT-mode flash) |
| 0x00001c04 | `FUN_00001c04` | SBL 0x36 transfer |

### RAM

| Address | Alias (accepted_ram_aliases.tsv) | Role here |
|---|---|---|
| 0xffffd1ea | `diag22_current_identifier` | Mode 22 state |
| 0xffffd3b4 | `diag_permission_mask_ffffd3b4` | session/security mask |
| 0xffffddc8 | `uds_rx_buffer` | UDS RX buffer |
| 0xffff9ec8 | `vehicle_inputs_pfdr_latch` | gates UDS entry (E6) |
| 0xffff807c | `inferred_ram_807c_ffff807c` | used cell inside the measured free window |
| 0xffff9150 | `inferred_sensor_block_ffff9150` | used cell inside the measured free window |

(Further RAM cells cited in prose — 0xffff9104/0xffff910c checksum, 0xffff8038
knock-learned retard, 0xffffb548 RPM, 0xffffc0b4 load, 0xffffd962 response ring,
the free runs in §3 — are documented in the related reports; the validator only
requires TSV-alias rows in this table.)

## 9. Limits

- **Free-RAM figure is an idle-boot lower bound of usage.** The 2M-cycle boot
  parks in idle 0x3dac; under a real drive cycle more RAM may be touched. Before
  picking shadow addresses, re-run the write-tracking measurement with
  `hee_replay_load`/`hee_replay_step` over `data/logs/rx8-666p/*.csv`.
- **Free-flash runs are per-ROM.** The runs in §3 are for 60E15120_N3J1E; the
  patchers already do per-ROM free-run discovery (verified all-0xFF) — reuse that.
- **Bandwidth numbers are estimates** (500 kbit/s assumption from
  emulated-obd.md, "confirm against captures"); not measured on a real bus.
- **E6/E8 still apply:** in the emulator, UDS response TX is driven via profile
  entry points (0x11d88/0x680a0/0x3c2a) because the autonomous tick/scheduler gap
  remains; family-B ROMs need a widened opcode table before their diag path is
  dynamically executable. Neither affects the feasibility verdict on the
  reference ROM; both affect how the PC tool is validated per ROM.
- **0x23 requires the 0x27 unlock** (NRC 0x33 without it) — the key algorithm is
  reversed but not proven bit-exact against a known vector (D4 note); Rx8Man's
  implementation is the working reference.
- **Services 0x12/0x18/0x32/0x33/0x3b/0xb1 are table-position labels only** — one
  of them might already hide a write-ish routine; worth a quick look before
  adding a new service record (cheap check, could shrink the patch).
- **No patch was built or executed in this study**; no real-car, bench, or
  flash validation exists for any of it (ROADMAP F gating, AGENTS.md rule 10).
  Safety design (range check, engine-state gate, read-back verify) is proposed,
  not implemented.

## 10. Related subsystems / next steps

- ROADMAP **F item 3** (added with this study): implement the Tier 1/2 patch in
  the emulator first (virtual OBD port + golden datalogs), then bench — the
  existing patcher pattern (`utilities/scripts/patchers/`) is the template.
- PC tool: new `utilities/scripts/` tool (hee.py-style) speaking ISO-TP/UDS over
  J2534 (car) and the emulator TCP port (dev), with CSV logging against
  `data/logs/` and table edit/write/read-back against `data/maps/<rom>/` +
  `data/definitions/` — RomRaider stays the offline editor; the new tool is the
  live one.
- Quick win before any patch: a logging-only tool on the **stock** ROM (Tier 0)
  gives live logging today and validates the whole PC-side path in the emulator
  against real-car logs.
