# Low-confidence label proof pass, 2026-11-05

Scope: every `medium`/`candidate` confidence label under `data/labels/`
(1,079 rows at pass start). Goal (ROADMAP C item 10 / D6 / D10): find more
proof for each, upgrade confidence where new evidence exists, and record the
evidence in the label files themselves.

Method: three independent proof sources, all re-run this session against
ROM 60E15120_N3J1E (SHA-256 a7cd953c…f264f1):

1. **Dynamic, in the SH-2E emulator** (profile
   `utilities/scripts/emu/profiles/60E15120_N3J1E.json`): drive the ROM's own
   Mode 22 dispatcher 0x5774c with source RAM cells at 0/sentinel/sentinel2
   and compare the 0xffffd962 response ring against an exact float32 model
   of each handler's encoder (models built from the decompiled encoder
   bodies: `rx8_encode_u8/u16_affine_saturate` 0x24d0, `rx8_decode_u16_affine`,
   `candidate_diag_encode_s16_div` 0x54884, `diag22_subpid_supported_mask`
   0x579a8 over the 36×6-byte table at ROM 0x5f5b2). Plus `harness.call`
   tests of control-path functions and an end-to-end physical chain through
   the real ADC read path. Durable regression test:
   [`tests/test_lowconf_dynamic_proof.py`](../../../../tests/test_lowconf_dynamic_proof.py)
   (6 passed).
2. **Cross-ROM byte matches** (`cross_rom_function_matches.tsv`,
   `cross_rom_mode22_pid_handlers.tsv`): every upgraded function/handler is
   byte-identical in 5–10 of the other 10 ROMs.
3. **Producer/consumer + caller analysis** in the decompiled export
   (`functions/*.c`, `callgraph.tsv`): which labeled function writes each
   RAM cell, which labeled task calls each function.

## What was proven (and upgraded to `high`)

### diag22 dispatch table (58 medium records in `uds_dispatch_labels.json`)

56 of 58 upgraded to `high`: the response payload matched the exact encoder
model at all three sentinel points for PIDs 0x15, 0x2e, 0x2f, 0x30, 0x31,
0x33, 0x3c, 0x45, 0x47, 0x49, 0x4a, 0x4c, 0x914–0x91a, 0x968, 0x96e, 0x97c,
0x9d3, 0x1101–0x1104, 0x114a, 0x114d, 0x1153, 0x1154, 0x1169, 0x1340, 0x1631,
0x163e, 0x1681, 0x1688, 0x16b3, 0x16e8, 0x16e9, 0xa211, 0xa216, 0x1706,
0x1711, 0x1715, 0x1718, 0x172a, 0x172d, 0x1782, 0x17a6, 0x17de, 0xc115,
0xc117, 0xc124, 0xff10, 0xff44, 0xff50. Each is also byte-identical in 5–7
other ROMs for the same PID.

- PIDs 0x31/0x1169 read checksummed-window floats (`ref_readValue_float_
  DEFAULTVAL_ADDRESS` validates `u16@+4 == ~(u16@+2 + hi16(bits))`); with a
  valid checksum written, 100.0 → 0x0064 / 25.0 → 0x3333 / 50.0 → 0x6666
  exact; without it the ROM returns the default (observed 0x1eb8 for the
  15.0 default on 0x1169).
- Pedal/throttle semantics proven **physically**: ADC AN18 raw 32768 →
  0x6884 (`ADDR18H_B`) → ffff9f08 → 0x1afb0 → ffffad5c → PID 0x11 wire 0x80
  = 50.2 % (and PID 0x1154 raw 0x8000, PID 0x917 exact); AN19 raw 16384 →
  ffffad5e → PID 0x47 wire 0x40 = 25.1 %. So ffffad5c = throttle sensor,
  ffffad5e = pedal (distinct cells, as `ram_aliases` say).
- **D10 resolved**: PID 0x1410 (handler 0x56f6c) reads float
  `injector_pulse_time_ffffbe24` with step 8.0 — 80.0 → 0x000a, 800.0 →
  0x0064 exact — and its response is independent of ffffad5c (throttle),
  which lives on PID 0x11/0x093c. Cross-ROM check done: the byte-matched
  handler is labeled `diag22_pid1410_injector_pulse_time` (high) in
  60E0E500, 60E0E700_N3YLEE, 60E1C500_N3J6EB. D10 can be closed.
- Remaining medium: 0x0002 (cal-id TLV tag 2; reader chain 0x55316 →
  0x61af4/0x6071e → 0x54994 re-read; TLV tag table at ROM 0x5edbc lists tag 2
  len 2; returns 0 in emu boot state) and 0x1710 (sensor block ffff9150–916c
  is checksummed so direct writes revert; bytes 1–3 match the boot values).
  0xc116 verified via the existing `test_mode22_dispatch_full_sweep`
  (cold path header-only).

The same upgrades propagate to `diagnostic_dispatch_named.tsv` (58 rows),
`cross_rom_mode22_pid_handlers.tsv` (336 rows) and the 7 per-ROM
`cross_rom/mode22/*.tsv` files (55–56 rows each).

### UDS service dispatch (8 medium rows in `uds_service_dispatch.tsv`)

Router 0x68dac driven in the emulator: services 0x21, 0x18, 0x12, 0x32,
0x33, 0xb1 reached their handlers at session bit 0 (r0 = 33/24/18/50/51/177),
0x3b with session bits 1–3 (record param 0x0e, r0 = 59). All upgraded to
`high` except 0xff (catch-all nop stub 0x6689a; router returns not-found
r0=1 at session bit 0 — kept medium with note). `uds_rx_channel_alloc`
0x68a86 / `uds_rx_channel_set_service` 0x68b10 upgraded: 0x68b10 was called
58× per sweep binding ch0←service 0x22.

### Control-path function labels

fueling (`fueling_labels.json`, 13 medium → all high): 0x8340
`injector_pulse_set_dispatch` (callers are the six ATU ch8 compare ISRs
0x59a4/0x59b2/0x59c0/0x59ce/0x59dc/0x59ea; thunk target 0x8a68 already
dynamically verified), 0x86ac `injector_zero_offset_set` (per-channel
zero/offset pairs observed: ch0→a0ac/a0b8, ch1→a0b0/a0bc, ch2→a0b4/a0c0),
0xe48e `injection_angle_limit_lookup` (rpm 1000→120.0 / 6000→60.0 = cal
tables tbl_068ef8/068f0c/068f20 × 2.0 exactly), 0xedc4 `fuel_cut_arbitration`
(a464=1, mode 0 → a444=a445=1), 0xee82 `rev_limit_conditionals` (coolant
ffffa98c hysteresis 18/20 °C exact: 10→1, 19→hold, 25→0, 19→hold, 10→1;
countdown arm observed), 0x18cfe `fuel_cut_rpm_condition` (2500/1700 rpm
thresholds exact), 0x19f4e MAF volts+fault (9eea=32768 → 2.5 V exact;
0xffff → aa35 fault counter), 0x19f40 MAF latch (a9e8→a9ec/a9f4 = 42.0),
0x1a418 (already covered by `test_fuel_chain_dynamic.py`), 0x1ddfc
cold-start (b0c4 = 0.0 observed), 0x56f6c (D10, above), 0x556ec/0x55702 AFR
words (caller `diag_air_fuel_ratio` 0x56b22 high; byte-exact high-confidence
renames in 60E0G500).

intake (`intake_labels.json`, 19 medium → 11 high): SSV/VDI/VFAD
thunk+wrappers 0x21760/0x21766/0x348e4/0x348ea/0x34910/0x34916 (thunk targets
labeled, init 0x1102a + task 0x11744 callers), APV counters/command
0x31ece/0x31f0a/0x31f32 (dynamic), `apv_pwm_service` 0xa936 (PLDR_W
0xfffff75e bit 0x100 set / 0x20 cleared at the 0x60-period boundary —
opposite polarity confirmed), `apv_drive_status_sample` 0xaac4 (PHDR_W
0x3000/0x2000/0x1000/0x0000 → a1bc 0/1/2/3 exact), `apv_position_voltage_
scale` 0x43a86 (9ef0=32768 → cab0 = 2.5 V exact). Left medium with enriched
evidence: 0x31c6c (multi-input target condition), 0x31bec (wrapper), the four
diag-override hooks 0x5c3c0/0x5c9ac/0x5cdc4/0x5cf7c, 0x3174a.

ignition (`ignition_timing_labels.json`): 0x12e60 `timing_trim_scale_calc`
high (a66c = a67c × a698 with a698 = tbl 0x6a04c(decode(a688)) — ratio exact).

knock/evap (`knock_loop_labels.json`, 6 medium, kept medium with new
evidence): ROM task-table pointers found for 0x64ba (ptr at 0x4a28),
0x390b8 (0x11978), 0x145c8 (0x116e0), 0x1467c (0x11a84), 0x22144 (0x21bfc).
**0x22144 `evap_open_loop_condition` looks misnamed**: its body gates on
`open_loop_active_ffffb12c` (the *fuel* open-loop flag, high label) and
DAT_ffffbe00 ≥ 66.5, then clamps b308 ≤ 0 — a fuel open-loop condition, not
EVAP. Flagged in the label evidence; rename needs a report-level decision.

OS (`os_scheduler_can_ivt_labels.json`, `os_task_12_16_labels.json`): 0x6cdc
`adc_read_ect_iat_group` high (with group selector ffff9f31=8, AN28/29 land
exactly in 9f1c/9f1e); 0x6fb0 high (body polls ADC bank-2 ADCSR2_B/ADCR2_B;
caller `knock_reference_adc_read` 0xc276); 0x11880 high (caller task12
entry 0x6592, already ROM-byte + emulator verified in C item 7).

### defs table candidates (23 in `defs_table_labels.json`)

Descriptor bytes at each address re-verified in ROM (type/dims/pointers);
evidence appended. Names remain `candidate` (not in RX8Defs; dataflow
hypotheses) — no upgrade claimed.

### 60E0G500 renames (`cross_rom_renames_applied.tsv`)

72 of 102 medium renames upgraded to `high`: each is a `unique_exact_bytes`
match to a 60E15120_N3J1E function that this pass proved high (evidence
string names the base address + alias). The remaining 30 keep medium with
the base-address cross-reference appended.

## Validation

- `python utilities/scripts/rx8-pcm-pipeline/verify_claims.py` → PASS
- `python utilities/scripts/rx8-pcm-pipeline/validate_reports.py` → PASS
- `python -m pytest tests/` → 106 passed, 1 pre-existing failure
  (`test_extract_scalars.py::test_generated_outputs_exist_and_are_consistent`,
  UnicodeDecodeError — fails identically on unmodified HEAD, unrelated).
- New: `tests/test_lowconf_dynamic_proof.py` — 6 passed.

## Limits

- The emulator executes the handlers, not the full OS tick loop; PID
  responses were driven through dispatcher 0x5774c directly (E6 remainder).
- Checksummed RAM window (0xffff8000–0xffff92ff) cells reject plain writes;
  0x1710's sensor block could not be sentinel-tested for that reason.
- Cross-ROM propagation for family-B ROMs (60E0FB00/60E0FC00/60E1B900/
  60E32000_N3N5EB) uses `pid_match`/table-location mapping (E8 opcode gap),
  not byte-exact handlers; their mode22 rows were not touched.
