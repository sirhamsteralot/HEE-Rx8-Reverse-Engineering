# Candidate-label promotion review — prove-or-demote pass over the export's `candidate_*` labels

ROM 60E15120_N3J1E, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`
(asserted unchanged; the pass never writes to the ROM). Static analysis of the
decompiled export plus targeted raw-ROM/disassembly re-verification; dynamic
evidence comes from the emulator proof tests listed in §Validation.

## Scope and method

At pickup, `reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv`
carried **181** `candidate_*` function names (all sourced from
`source_review/accepted_function_aliases.tsv` rows at confidence `medium`, which
`integrate_reviewed_names.py` prefixes with `candidate_`). For each address the
pass collected the best recorded confidence from every per-subsystem label
record (`data/labels/60E15120_N3J1E/*.json`, investigation review JSONs), plus
curated binary-level decisions for the control-path candidates. Decision rule
(label ladder): promote (drop the `candidate_` prefix) only where a
high-confidence record or fresh binary-level proof exists; rename where the
name itself is wrong; otherwise keep `candidate_` with the evidence recorded —
plausibility is not proof.

Applied by the re-runnable pipeline pass
[`review_candidate_promotions.py`](../../../../utilities/scripts/rx8-pcm-pipeline/review_candidate_promotions.py)
(wired into `rebuild.sh` after `review_dtc_thunk_labels.py`; record
[`data/labels/60E15120_N3J1E/candidate_promotions.json`](../../../../data/labels/60E15120_N3J1E/candidate_promotions.json)).
The pass updates the TSV confidences and label records; in this environment the
export rename was applied by the same pass via `--apply-export` using
`errors='surrogateescape'` (byte-exact, CRCRLF preserved) because
`integrate_reviewed_names.py` crashes on pre-existing non-UTF-8 bytes in
tracked files — a full `rebuild.sh` run re-applies the identical renames from
the TSV. The pass is idempotent (re-run reports `tsv_rows_changed: 0` and the
same counts).

## Decisions: 112 promoted to high, 1 renamed (stays medium), 68 kept as `candidate_`

### Promoted on existing high-confidence label records (107)

Dynamic emulator proof (Mode 22 dispatcher 0x5774c driven with sentinel source
cells and exact float32 encoder models; UDS router 0x68dac; `harness.call`
control-path tests; ADC→PID physical chain) plus cross-ROM byte matches, as
recorded in the per-subsystem label JSONs:

- diag22 PID handlers + diag encoders (86): 0x6a32 `diag22_pid0015_o2s2_voltage_trim`,
  0x6abc `diag22_pid002e_ram_b2f0_pct`, 0x6ad2 `diag22_pid002f_ram_d287_raw`,
  0x6ae6 `diag22_pid0030_gear_or_vin_byte`, 0x6afa `diag22_pid0031_ram_90fc_float`,
  0x6b0e `diag22_pid0033_ram_ad10_scaled`, 0x6b42 `diag22_pid003c_ram_c644_scaled`,
  0x6bb2 `diag22_pid0045_ram_ad48_pct`, 0x6bc6 `diag22_pid0047_ram_ad5e_pedal`,
  0x6bda `diag22_pid0049_ram_a9c4_pedal`, 0x6c78 `diag22_pid004a_ram_a9c6_pedal`,
  0x6c8c `diag22_pid004c_ram_b410_pct`, 0x6ce8 `diag22_pid0914_ram_a9c4_scaled_s16`,
  0x6d1a `diag22_pid0915_ram_a9c6_scaled_s16`, 0x6d4c `diag22_pid0917_ram_ad5c_scaled_s16`,
  0x6db4 `diag22_pid0918_ram_ad5e_scaled_s16`, 0x6de6 `diag22_pid091a_ram_b410_raw_512`,
  0x6e22 `diag22_pid096e_ram_a7ac_quarter`, 0x6e40 `diag22_pid097c_ram_b59c_div2048`,
  0x6e5e `diag22_pid114a_ram_add4_raw`, 0x6e7c `diag22_pid114d_ram_a984_raw`,
  0x6e9a `diag22_pid1153_ram_a834_lambda`, 0x6eb8 `diag22_pid1154_throttle_raw_ad5c`,
  0x6efc `diag22_pid1169_ram_807c_scaled`, 0x6f4e `diag22_pid1340_ram_a9bc_pct`,
  0x6f8a `diag22_pid163e_ram_b074_scaled_s16`, 0x6faa `diag22_pid16b3_ram_ad10_raw`,
  0x6fc8 `diag22_pid16e8_ram_b5ac_raw`, 0x6fe6 `diag22_pid16e9_ram_b654_eighth`,
  0x705c `diag22_pida216_ram_bc30_raw`, 0x7098 `diag22_pid1782_ram_c6ac_raw`,
  0x70b6 `diag22_pid17a6_ram_d1ac_scaled`, 0x70ee `diag22_pid172a_ram_c4c8_temp_c`,
  0x710c `diag22_pid172d_ram_a8f4_raw`, 0x7138 `diag22_pid0968_io_status_b5b4_bc35`,
  0x71ac `diag22_pid09d3_pedr_bit10_status`, 0x71e4 `diag22_pid1101_io_status_bf3c_ad18_cdd8`,
  0x7226 `diag22_pid1102_io_status_bdb8`, 0x7248 `diag22_pid1103_io_status_pedr_cab4_d1a`,
  0x72d0 `diag22_pid1104_io_status_pjdr_bf6c`, 0x730e `diag22_pid1631_tol_status_b570_b584`,
  0x734a `diag22_pid1681_io_status_ce1c`, 0x736c `diag22_pid1688_secondary_air_status_bit`,
  0x738e `diag22_pida211_status_b53b_aa62_bf9c`, 0x73f0 `diag22_pid1711_pedr_bit1_status`,
  0x741e `diag22_pid1706_io_status_a8f5`, 0x7440 `diag22_pid1718_pedr_bit2_status`,
  0x746e `diag22_pid1715_pedr_pddr_status`, 0x74b6 `diag22_pid17de_io_status_ce32`,
  0x76b4 `diag22_pidc115_ram_c1d2_raw`, 0x76c2 `diag22_pidc116_dtc_state_machine`,
  0x7704 `diag22_pidc117_ram_c1d3_c1d4`, 0x7738 `diag22_pidc124_diag_status_bits`,
  0x7884 `diag22_pidff10_dtc_status_c1d5_c1d8`, 0x796e `diag22_pidff50_ram_d3a0_raw`,
  0x7974 `diag22_pidff44_ram_ce30_raw`, plus encoders/readers 0x54884, 0x55586,
  0x555ac, 0x55616, 0x5562c, 0x55632, 0x556b0, 0x556ce, 0x5571a, 0x55774,
  0x5578a, 0x557b6, 0x55838, 0x55864 (`diag_encode_*` / `diag_read_*`).
- UDS services / RX channels (7): 0x57db0 `uds_service_18`, 0x5b094
  `uds_service_12`, 0x5b414 `uds_service_21_read_data_by_local_id`, 0x5d8b4
  `uds_service_3b`, 0x5e024 `uds_service_32`, 0x68a86 `uds_rx_channel_alloc`,
  0x68b10 `uds_rx_channel_set_service`, plus 0x565e8 `uds_service_b1_mazda_specific`.
- fueling chain (8): 0x8340 `injector_pulse_set_dispatch`, 0x86ac
  `injector_zero_offset_set`, 0xe48e `injection_angle_limit_lookup`, 0xedc4
  `fuel_cut_arbitration`, 0xee82 `rev_limit_conditionals`, 0x18cfe
  `fuel_cut_rpm_condition`, 0x19f40 `maf_filtered_update`, 0x19f4e
  `maf_voltage_and_fault_counters`, 0x1a418 `maf_per_rotation_calc`, 0x1ddfc
  `cold_start_enrichment`.
- intake solenoids / APV (10): 0x21760/0x21766 SSV thunk+wrapper,
  0x348e4/0x348ea VDI thunk+wrapper, 0x34910/0x34916 VFAD thunk+wrapper,
  0x31ece/0x31f0a/0x31f32 APV counters/command, 0xa936 `apv_pwm_service`,
  0xaac4 `apv_drive_status_sample`, 0x43a86 `apv_position_voltage_scale`.
- knock/DTC/OS (5): 0x37358 `dtc_state_machine_step`, 0x37546
  `diag_status_bit_pack`, 0x12e60 `timing_trim_scale_calc`, 0x6cdc
  `adc_read_ect_iat_group`, 0x6fb0 `adc_read_result_bank2`, 0x11880
  `monitor_service_batch`, 0x5fab2 `dtc_count_stored`.

### Promoted on fresh binary-level re-verification (5)

Re-verified this session against the raw ROM, the disassembly and
`callgraph.tsv` (task-table pointers are u32 words in ROM; jsr pools decoded
from ROM bytes):

- 0x64ba `knock_sensor_fault_task` — task-table record at ROM 0x4a28 holds
  0x000064ba; body jsr chain via pools 0x655c–0x6570 = 0xd21e, 0x6842, 0x94fc,
  **0xc290 `ref_knockSensorADCFault`**, 0x1150e, tail jmp 0x3d58
  `ref_taskEndRoutine_`; byte-exact match in 10/10 other ROMs.
- 0x390b8 `knock_sensor_monitor_task` — ROM pointer 0x11978; caller 0x11744;
  callees 0x4a084 `knock_sensor_dtc_report` + 0x49fac
  `knock_sensor_health_persistence`.
- 0x145c8 `timing_retard_fast_task` — ROM pointer 0x116e0; caller 0x11534;
  callees include 0x1391c `ref_calcKnockRAMUpdate_`, 0x13b40
  `knock_retard_slow_recovery`, 0x214f8/0x215f8 AC-compressor timing retards.
- 0x1467c `knock_rough_correction_update` — ROM pointer 0x11a84; caller
  0x118d0; callees 0x13034 `knock_rough_correction_targets` + 0x13210
  `ref_roughKnockCorrection`.
- 0x3d010 `o2_monitor_integrator` — body: integrator 0xffffc5ec decays by
  MAF×0.1 clamped ≥ 0, loaded from tbl 0x6b61c vs catalyst-temp model
  0xffffa998; countdowns gated by vehicle speed > 95.88; callers 0x3ccec (sets
  tolerance bounds 0xffffc5f0=−40.0 / 0xffffc5f4=200.0) and 0x3cd06
  (out-of-tolerance → 0xffffc5fc/c5fd); pools 0x3d0c4–0x3d0ec ROM-verified.

### Renamed, stays `candidate_` (1)

- 0x22144 `candidate_evap_open_loop_condition` → **`candidate_fuel_open_loop_condition`**.
  The body (200 B; pools 0x22218/0x2221c/0x22220 ROM-verified) sets
  0xffffb319 = 1 iff 0xffffb318==1 && `open_loop_active_ffffb12c`==1 &&
  0xffffbe00 ≥ 66.5 && `closed_loop_active_ffffae1f`==0 && b2f6/b0c8/b0c9 clear.
  The gate uses the **fuel** open-loop flag (high label, set by
  `set_open_loop_flag` 0x1ee30); the "evap" attribution came only from the
  inherited caller name `ref_evapRelated` 0x21b8a, which is a `ref_`
  hypothesis. Kept at medium until the EVAP-chain attribution is proven.

### Kept as `candidate_` (68)

Idle cluster (0x148a4, 0x148c4, 0x14944, 0x14baa, 0x14d10, 0x14f6c, 0x15f5c,
0x15fa0, 0x15ffc, 0x1617e, 0x16358, 0x16380, 0x16432, 0x165d6, 0x16672, 0x16720,
0x16748, 0x16900, 0x3337c, 0x3354e, 0x34650), alternator/charging (0x257b4,
0x2590a, 0x25a22, 0x25a3c, 0x25aa0, 0x25ba4, 0x25c6c, 0x2616e, 0x2635c, 0x264f0,
0x26624, 0x26760, 0x2ce18, 0x54590, 0x545a6, 0x545bc, 0x5c800, 0x5cba4), DSC CAN
(0x2b046, 0x2b1d6, 0x2b496, 0x2b6a4, 0x2b6c2, 0x2b754, 0x2b788, 0x2b7a6, 0x2b7c4,
0x2b816), E2RAM device layer (0xbe5e, 0xbe8c, 0x35a8c, 0x35d36, 0x379e4),
intake/diag hooks (0x2f260, 0x3174a, 0x31bec, 0x31c6c, 0x5c3c0, 0x5c648,
0x5c724, 0x5c9ac, 0x5cdc4, 0x5cf7c), fuel-cut resume 0x15a40, and the
diag02/PID-0x1710 readers 0x55316, 0x568b4, 0x57594 (checksummed RAM window
rejects sentinel writes). These have structural evidence recorded in their
subsystem label records but no dynamic/cross-ROM proof yet, so the label ladder
keeps them at `candidate_`.

## Files changed

- `utilities/scripts/rx8-pcm-pipeline/review_candidate_promotions.py` (new pass),
  `rebuild.sh` (wired in).
- `docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv`
  (113 rows: 112 confidence medium→high, 1 alias rename), label records
  `data/labels/60E15120_N3J1E/knock_loop_labels.json`, new record
  `data/labels/60E15120_N3J1E/candidate_promotions.json`.
- Export: `function_index.tsv`, `callgraph.tsv`, `symbols.tsv`,
  `functions/*.c`, `firmware_decompiled.c`, `named/firmware_named.c`,
  `data/labels/60E15120_N3J1E/integrated_names.json`,
  `data/labels/cross_rom_mode22_pid_handlers.tsv`,
  `data/labels/cross_rom/mode22/*.tsv`.
- Docs: the promoted/renamed names in the subsystem reports and review notes
  under `docs/investigations/60E15120_N3J1E/` (the historical proof-pass review
  `reviews/low_confidence_proof_pass_2026-11-05.md` is left as written),
  plus the corrected 0x22144 row and promotion note in
  [knock_control_report.md](../knock_control_report.md).
- `tests/test_candidate_label_promotions.py` (6 tests).

## Validation

- `python -m pytest tests/test_candidate_label_promotions.py` — 6 passed.
- `python -m pytest tests/` — full suite (see commit record; the one
  pre-existing `test_extract_scalars.py` UnicodeDecodeError failure on clean
  main is unrelated).
- Pipeline validators from the repo root: `validate_export.py`,
  `validate_reports.py`, `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py` — PASS (run after this pass; results in the commit).
- `python utilities/scripts/hash_binaries.py --check` — binaries untouched.
- ROM SHA-256 asserted unchanged by the pass itself.

## Limits

- The 68 kept `candidate_` labels are decisions, not proofs: several (idle
  select-flag consumers, alternator model, DSC CAN decodes, E2RAM device
  protocol) remain open questions tracked in their subsystem reports.
- The export rename in this environment was applied by the scoped
  surrogateescape pass; the Ghidra database is not updated
  (`ghidra_database_updated: false` in the record), same as all prior passes —
  a full `rebuild.sh` run re-applies everything from the TSV.
- Dynamic proof for the 107 record-sourced promotions lives in
  `tests/test_lowconf_dynamic_proof.py` and the per-subsystem
  `tests/test_*_dynamic.py`; this pass did not re-run the emulator, it consumed
  their recorded results plus fresh static/ROM verification.
