# UDS service dispatch + Mode 22 PID dispatch-table labeling report — 60E15120_N3J1E

Date: 2026-10-31. Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — labels only, no binary change). Static-analysis disclaimer: findings come
from the canonical export + disassembly + ROM bytes, **plus dynamic execution in the
SH-2E emulator** (`utilities/scripts/emu/`, `tests/test_phase1_dynamic.py`); every
dynamically-cited claim names the emulator observation. Full evidence:
`data/labels/60E15120_N3J1E/uds_dispatch_labels.json`,
`diagnostic_dispatch_named.tsv`, `uds_service_dispatch.tsv`.

**Related reports:** builds on [os_scheduler_can_ivt_report.md](os_scheduler_can_ivt_report.md)
(CAN/ISO-TP plumbing, UDS entry 0x680a0, task table 0x4998); PID semantics cross-checked
against [fueling_control_report.md](fueling_control_report.md),
[ignition_timing_report.md](ignition_timing_report.md),
[knock_control_report.md](knock_control_report.md),
[load_fueling_report.md](load_fueling_report.md); logger scalings from
`submodules/RX8Defs/RomRaider/logger_rx8_defs.xml` and
[docs/references/rx8club-user-guide-thread.md](../../references/rx8club-user-guide-thread.md).

## 1. Executive summary

- The **Mode 22 (ReadDataByIdentifier) dispatch table** is at **0x5f10c**: **99 x 12-byte
  records** `{u16 pid, u8 response_length, u8 byte3, u16 availability_mask, u16 unk,
  u32 handler}` (layout asserted in `rx8_analysis_types.h` `Rx8DiagnosticRecord`).
  Scanned linearly by **0x5774c `diag22_find_and_dispatch_identifier`**, which matches
  `diag22_current_identifier_ffffd1ea`, rejects when
  `(record.availability_mask & DAT_ffffd3b4) == 0` (NRC 0x31), appends the 0x62 header
  (0x57858) unless `DAT_ffffd1e8 == -0x80`, calls `handler(0x22)`, and returns
  `response_length + 3`. **All 99 records are now labeled** (previously 1).
- A second table at **0x5f5b2** (36 x 6-byte records `{u16 pid, u8 supported_bit,
  u8 sub, u16 mask}`) backs the "status bitmap" PIDs (0x0968, 0x09d3, 0x11xx, 0x16xx,
  0x17xx, 0xa211, 0xff10): handlers build a status byte from RAM/GPIO latches and call
  **0x579a8 `diag22_subpid_supported_mask`**, which ANDs it with the OR of matching
  records' `supported_bit` bytes.
- The **UDS service dispatch table** is at **0x5eb40**: **29 x 12-byte records**
  `{u8 service<<24, u32 handler, u32 param}`, terminator service 0xff -> nop;rts stub
  0x6689a. Scanned by **0x68dac `uds_service_dispatch_table_scan`** (literal @0x68ed0;
  byte0==service, `record[8] & session_mask` check, `jsr record[4]`). This maps services
  0x10/0x11/0x14/0x21/0x22/0x23/0x27/0x28/0x2f/0x31/0x34/0x36/0x37/0x3e/0x85 + OBD modes
  0x01-0x09 + Mazda-specific 0x12/0x18/0x32/0x33/0x3b/0xb1 — **all now labeled**.
- The ISO-TP frame-type dispatcher is **0x6842c `isotp_frame_type_dispatch`** (r4 =
  PCI byte & 0xf0 from 0x683d4): SF->0x68548, FF->0x6859e, CF->0x6872c, FC->0x68764.
  UDS entry 0x680a0 -> 0x683d4 -> 0x6842c -> (accept) 0x684b4 schedules OS task 2
  (entry 0x96be -> queue dequeue 0x6010 -> handler from the 20-byte queue record).
- ROM identity strings confirmed at binary level: firmware ID `"60E15120"` at **0x2000**,
  `"N3J1E_1W.Z05"` at **0x6c000**, `"SW-N3ZHEB000.HEX"` at **0x6c043** (PID 0xe611 returns
  the 24-byte field; PIDs 0xe21b-0xe21e return immediate chunks "N3ZH"/"18"/"881"/"B"),
  `"15120 "` at 0x6c05c (PIDs 0xff40/0xff41), ROM ID bytes 0xff8-0xffd (PIDs
  0xff42/0xff43). Note D1: the file is named N3J1E while the cal-ID string at 0x6c046
  reads N3ZHEB000.HEX — already documented in the ROADMAP register.
- Dynamic verification (emulator): dispatching PIDs 0x0000/0x0005/0x000c/0x000d/0x0043/
  0xe611/0x0200/0x0202 through the ROM's own 0x5774c produces the exact labeled response
  bytes in the channel-0 ring (0xffffd962): e.g. `62 0005 82` for ECT 90 degC
  ((90-(-40))/1 = 130), `62 000c 2ee0` for 3000 rpm (3000/0.25 = 12000),
  `62 0043 006b` for load 0.42 g/rev (0.42/(1/255) = 107), `62 e611 "SW-N3ZHEB000.HEX"...`,
  and `7f 22 31` (NRC requestOutOfRange) when the permission mask rejects
  (PID 0xc115, mask 0x3bfc, DAT_ffffd3b4 = 0). See
  `test_mode22_dispatch_table_payloads`.

## 1a. Plain-language summary

- A diagnostic tester (RomRaider Logger, Mazda IDS) asks the PCM for data two ways:
  **Mode 22** ("read this data identifier", PID) and **UDS services** (session control,
  security unlock, memory read, flash download...). This pass named every entry in both
  lookup tables, so every PID/service now has a readable handler in the decompiled code.
- Each PID handler is tiny: it reads one internal value (engine load, coolant temp, RPM...),
  converts it to the OBD-II raw-byte format with the ROM's own fixed-point encoder, and
  appends it to the response. The response is a `0x62` header + the 2-byte PID + payload.
- ROM-vs-applied-values note: the PIDs report *internal* RAM values (e.g. PID 0x43 is the
  computed g/rev load cell 0xffffc0b4 scaled by 1/255), not the calibration tables — same
  distinction as the other subsystem reports.
- Nothing here changes what the car does; it makes the diagnostic interface fully
  navigable, which is what loggers and flash tools rely on.

## 2. How it works (condensed pseudocode)

```python
# UDS request path: CAN 0x7e0 -> IVT 0x378 -> 0x11d88 can_rx_poll -> UDS RX buf 0xffffddc8
#   uds_service_entry 0x680a0(0x7e0): pci = 0x683d4()  (buf[0] & 0xf0, clamp 0x40)
#   0x6842c isotp_frame_type_dispatch: 0x00 SF -> 0x68548, 0x10 FF -> 0x6859e,
#     0x20 CF -> 0x6872c, 0x30 FC -> 0x68764
#   0x68548 (SF): len = buf[0]&0xf; svc = buf[1]; ch = 0x68a86(svc); ddf5|=4; 0x683b4();
#     ddec = ch; ddea = svc; dde6 = len; pack_for_OBD_response(ch, &buf[1], 7)
#   accept -> 0x684b4 uds_request_schedule_service_task -> ref_osTaskScheduler(2,0,rec)
#   task[2] 0x96be: rec = 0x6010 os_queue_dequeue_record(1); rec.handler(rec+1)
#   service router: 0x68dac scans 0x5eb40 records {svc<<24, handler, param}:
#     byte0 == svc and (param & session_mask) -> jsr handler(svc)
#   service 0x22 -> 0x567e8 (parse 2-byte PID into 0xffffd1ea, d1ec=1)
#   periodic task 0x11534 -> 0x56856 -> if d1ec==1: 0x5774c dispatch
# 0x5774c diag22_find_and_dispatch_identifier: for each of 99 records at 0x5f10c:
#     pid match? (mask & 0xffffd3b4)==0 -> NRC 0x31; else header + handler(0x22);
#     r0 = response_length + 3   (or error)
# status-bitmap PIDs: handler builds byte from RAM/GPIO latches -> 0x579a8(byte, sub)
#   scans 0x5f5b2 (36 x 6B) for pid+sub with mask&dd3b4 -> returns byte & OR(supported_bit)
```

## 3. Key tables / structures

| Address | Name | Contents |
|---|---|---|
| 0x5f10c | `tbl_diag22_dispatch_records_0005f10c` | 99 x 12-byte Mode 22 records (below) |
| 0x5f5b2 | `tbl_diag22_subpid_supported_bits_0005f5b2` | 36 x 6-byte {pid, bit, sub, mask} |
| 0x5eb18 | jump table (caseD_22..caseD_26) | 5 x 8-byte {key<<24, handler}; literal @0x55c64 |
| 0x5eb40 | `tbl_uds_service_dispatch_0005eb40` | 29 x 12-byte service records (below) |
| 0x4998 | `os_task_table` | 18 x 16-byte task records; task[2] = 0x96be (UDS service task) |
| 0xd74c / 0xd87c | queue tables | `PTR_DAT_0000d74c` (0x6010 dequeue), `PTR_DAT_0000d87c` (0x9630 scheduler) |
| 0xffffddc8 | `uds_rx_buffer` | CAN RX payload (PCI first byte) |
| 0xffffd962 | channel-0 response ring | `ref_pack_for_OBD_response_` 0x67e1c write target (pos u16 at 0xffffd95c) |
| 0xffffd1ea/d1e8/d1ec | diag22 state | current identifier / response code / request-pending flag |
| 0xffffd3b4 | `diag_permission_mask_ffffd3b4` | session/security mask ANDed with record masks |
| 0x2000 / 0x6c000 / 0x6c043 / 0x6c046 / 0x6c05c | ROM ID strings | fw id, cal strings (see section 1) |

### Mode 22 dispatch records (0x5f10c, 99 x 12 bytes)

| record | PID | len | mask | handler | label |
|---|---|---|---|---|---|
| 0x5f10c | 0x0000 | 4 | 0xfffc | 0x56890 | `diag22_pid0000_pids_supported_01_20` |
| 0x5f118 | 0x0002 | 2 | 0xfffc | 0x568b4 | `diag22_pid0002_active_cal_id_field` |
| 0x5f124 | 0x0003 | 2 | 0xfffc | 0x568ca | `diag22_pid0003_fuel_system_status_ol_cl` |
| 0x5f130 | 0x0004 | 1 | 0xfffc | 0x568f0 | `diag22_pid0004_calculated_engine_load_pct` |
| 0x5f13c | 0x0005 | 1 | 0xfffc | 0x56940 | `diag22_pid0005_coolant_temp_c` |
| 0x5f148 | 0x0006 | 1 | 0xfffc | 0x56956 | `diag22_pid0006_stft_bank1_pct` |
| 0x5f154 | 0x0007 | 1 | 0xfffc | 0x5696c | `diag22_pid0007_ltft_bank1_pct` |
| 0x5f160 | 0x000c | 2 | 0xfffc | 0x56982 | `diag22_pid000c_engine_rpm` |
| 0x5f16c | 0x000d | 1 | 0xfffc | 0x56998 | `diag22_pid000d_vehicle_speed_kmh` |
| 0x5f178 | 0x000e | 1 | 0xfffc | 0x569ae | `diag22_pid000e_leading_ignition_timing_deg` |
| 0x5f184 | 0x000f | 1 | 0xfffc | 0x569c4 | `diag22_pid000f_intake_air_temp_c` |
| 0x5f190 | 0x0010 | 2 | 0xfffc | 0x569da | `diag22_pid0010_maf_g_s` |
| 0x5f19c | 0x0011 | 1 | 0xfffc | 0x569f0 | `diag22_pid0011_throttle_position_pct` |
| 0x5f1a8 | 0x0012 | 1 | 0xfffc | 0x56a06 | `diag22_pid0012_secondary_air_status` |
| 0x5f1b4 | 0x0013 | 1 | 0xfffc | 0x56a1c | `diag22_pid0013_o2_sensors_present` |
| 0x5f1c0 | 0x0015 | 2 | 0xfffc | 0x56a32 | `diag22_pid0015_o2s2_voltage_trim` |
| 0x5f1cc | 0x001c | 1 | 0xfffc | 0x56a58 | `diag22_pid001c_obd_standard` |
| 0x5f1d8 | 0x001f | 2 | 0xfffc | 0x56a6e | `diag22_pid001f_engine_runtime_s` |
| 0x5f1e4 | 0x0020 | 4 | 0xfffc | 0x56a84 | `diag22_pid0020_pids_supported_21_40` |
| 0x5f1f0 | 0x0021 | 2 | 0xfffc | 0x56aa8 | `diag22_pid0021_distance_while_mil_on` |
| 0x5f1fc | 0x002e | 1 | 0xfffc | 0x56abc | `diag22_pid002e_ram_b2f0_pct` |
| 0x5f208 | 0x002f | 1 | 0xfffc | 0x56ad2 | `diag22_pid002f_ram_d287_raw` |
| 0x5f214 | 0x0030 | 1 | 0xfffc | 0x56ae6 | `diag22_pid0030_gear_or_vin_byte` |
| 0x5f220 | 0x0031 | 2 | 0xfffc | 0x56afa | `diag22_pid0031_ram_90fc_float` |
| 0x5f22c | 0x0033 | 1 | 0xfffc | 0x56b0e | `diag22_pid0033_ram_ad10_scaled` |
| 0x5f238 | 0x0034 | 4 | 0xfffc | 0x56b22 | `diag22_pid0034_afr_lambda_words` |
| 0x5f244 | 0x003c | 2 | 0xfffc | 0x56b42 | `diag22_pid003c_ram_c644_scaled` |
| 0x5f250 | 0x0040 | 4 | 0xfffc | 0x56b56 | `diag22_pid0040_pids_supported_41_60` |
| 0x5f25c | 0x0042 | 2 | 0xfffc | 0x56b76 | `diag22_pid0042_battery_voltage_v` |
| 0x5f268 | 0x0043 | 2 | 0xfffc | 0x56b8a | `diag22_pid0043_engine_load_g_rev` |
| 0x5f274 | 0x0044 | 2 | 0xfffc | 0x56b9e | `diag22_pid0044_lambda_target` |
| 0x5f280 | 0x0045 | 1 | 0xfffc | 0x56bb2 | `diag22_pid0045_ram_ad48_pct` |
| 0x5f28c | 0x0047 | 1 | 0xfffc | 0x56bc6 | `diag22_pid0047_ram_ad5e_pedal` |
| 0x5f298 | 0x0049 | 1 | 0xfffc | 0x56bda | `diag22_pid0049_ram_a9c4_pedal` |
| 0x5f2a4 | 0x004a | 1 | 0xfffc | 0x56c78 | `diag22_pid004a_ram_a9c6_pedal` |
| 0x5f2b0 | 0x004c | 1 | 0xfffc | 0x56c8c | `diag22_pid004c_ram_b410_pct` |
| 0x5f2bc | 0x0200 | 1 | 0xfffc | 0x56ca0 | `diag22_pid0200_dtc_count_stored` |
| 0x5f2c8 | 0x0202 | 1 | 0xfffc | 0x56cb4 | `diag22_pid0202_dtc_count_ram_list` |
| 0x5f2d4 | 0x0904 | 1 | 0xfffc | 0x56cc8 | `diag22_pid0904_trailing_ignition_timing_deg` |
| 0x5f2e0 | 0x0914 | 2 | 0xfffc | 0x56ce8 | `diag22_pid0914_ram_a9c4_scaled_s16` |
| 0x5f2ec | 0x0915 | 2 | 0xfffc | 0x56d1a | `diag22_pid0915_ram_a9c6_scaled_s16` |
| 0x5f2f8 | 0x0917 | 2 | 0xfffc | 0x56d4c | `diag22_pid0917_ram_ad5c_scaled_s16` |
| 0x5f304 | 0x0918 | 2 | 0xfffc | 0x56db4 | `diag22_pid0918_ram_ad5e_scaled_s16` |
| 0x5f310 | 0x091a | 2 | 0xfffc | 0x56de6 | `diag22_pid091a_ram_b410_raw_512` |
| 0x5f31c | 0x093c | 2 | 0xfffc | 0x56e04 | `diag22_pid093c_throttle_position_raw` |
| 0x5f328 | 0x096e | 2 | 0xfffc | 0x56e22 | `diag22_pid096e_ram_a7ac_quarter` |
| 0x5f334 | 0x097c | 2 | 0xfffc | 0x56e40 | `diag22_pid097c_ram_b59c_div2048` |
| 0x5f340 | 0x114a | 2 | 0xfffc | 0x56e5e | `diag22_pid114a_ram_add4_raw` |
| 0x5f34c | 0x114d | 2 | 0xfffc | 0x56e7c | `diag22_pid114d_ram_a984_raw` |
| 0x5f358 | 0x1153 | 2 | 0xfffc | 0x56e9a | `diag22_pid1153_ram_a834_lambda` |
| 0x5f364 | 0x1154 | 2 | 0xfffc | 0x56eb8 | `diag22_pid1154_throttle_raw_ad5c` |
| 0x5f370 | 0x1169 | 2 | 0xfffc | 0x56efc | `diag22_pid1169_ram_807c_scaled` |
| 0x5f37c | 0x1177 | 2 | 0xfffc | 0x56f30 | `diag22_pid1177_maf_voltage_latched_v` |
| 0x5f388 | 0x1340 | 1 | 0xfffc | 0x56f4e | `diag22_pid1340_ram_a9bc_pct` |
| 0x5f394 | 0x1410 | 2 | 0xfffc | 0x56f6c | `diag22_pid1410_injector_pulse_time` |
| 0x5f3a0 | 0x163e | 2 | 0xfffc | 0x56f8a | `diag22_pid163e_ram_b074_scaled_s16` |
| 0x5f3ac | 0x16b3 | 2 | 0xfffc | 0x56faa | `diag22_pid16b3_ram_ad10_raw` |
| 0x5f3b8 | 0x16e8 | 2 | 0xfffc | 0x56fc8 | `diag22_pid16e8_ram_b5ac_raw` |
| 0x5f3c4 | 0x16e9 | 2 | 0xfffc | 0x56fe6 | `diag22_pid16e9_ram_b654_eighth` |
| 0x5f3d0 | 0x16f0 | 2 | 0xfffc | 0x57004 | `diag22_pid16f0_tire_revolutions_per_mile` |
| 0x5f3dc | 0xa216 | 2 | 0xfffc | 0x5705c | `diag22_pida216_ram_bc30_raw` |
| 0x5f3e8 | 0x1746 | 1 | 0xfffc | 0x5707a | `diag22_pid1746_knock_retard_deg` |
| 0x5f3f4 | 0x1782 | 2 | 0xfffc | 0x57098 | `diag22_pid1782_ram_c6ac_raw` |
| 0x5f400 | 0x17a6 | 1 | 0xfffc | 0x570b6 | `diag22_pid17a6_ram_d1ac_scaled` |
| 0x5f40c | 0x172a | 1 | 0xfffc | 0x570ee | `diag22_pid172a_ram_c4c8_temp_c` |
| 0x5f418 | 0x172d | 1 | 0xfffc | 0x5710c | `diag22_pid172d_ram_a8f4_raw` |
| 0x5f424 | 0x1634 | 1 | 0x155c | 0x5711a | `diag22_pid1634_apv_position_voltage` |
| 0x5f430 | 0x0968 | 2 | 0xfffc | 0x57138 | `diag22_pid0968_io_status_b5b4_bc35` |
| 0x5f43c | 0x09d3 | 2 | 0x155c | 0x571ac | `diag22_pid09d3_pedr_bit10_status` |
| 0x5f448 | 0x1101 | 1 | 0xfffc | 0x571e4 | `diag22_pid1101_io_status_bf3c_ad18_cdd8` |
| 0x5f454 | 0x1102 | 1 | 0xfffc | 0x57226 | `diag22_pid1102_io_status_bdb8` |
| 0x5f460 | 0x1103 | 1 | 0xfffc | 0x57248 | `diag22_pid1103_io_status_pedr_cab4_d1a` |
| 0x5f46c | 0x1104 | 1 | 0xfffc | 0x572d0 | `diag22_pid1104_io_status_pjdr_bf6c` |
| 0x5f478 | 0x1631 | 1 | 0xfffc | 0x5730e | `diag22_pid1631_tol_status_b570_b584` |
| 0x5f484 | 0x1681 | 1 | 0xfffc | 0x5734a | `diag22_pid1681_io_status_ce1c` |
| 0x5f490 | 0x1688 | 1 | 0xfffc | 0x5736c | `diag22_pid1688_secondary_air_status_bit` |
| 0x5f49c | 0xa211 | 2 | 0xfffc | 0x5738e | `diag22_pida211_status_b53b_aa62_bf9c` |
| 0x5f4a8 | 0x1711 | 1 | 0xfffc | 0x573f0 | `diag22_pid1711_pedr_bit1_status` |
| 0x5f4b4 | 0x1706 | 1 | 0xfffc | 0x5741e | `diag22_pid1706_io_status_a8f5` |
| 0x5f4c0 | 0x1718 | 1 | 0xfffc | 0x57440 | `diag22_pid1718_pedr_bit2_status` |
| 0x5f4cc | 0x1715 | 1 | 0xfffc | 0x5746e | `diag22_pid1715_pedr_pddr_status` |
| 0x5f4d8 | 0x17de | 1 | 0xfffc | 0x574b6 | `diag22_pid17de_io_status_ce32` |
| 0x5f4e4 | 0xe21b | 4 | 0xfffc | 0x574d8 | `diag22_pide21b_cal_id_chunk_0` |
| 0x5f4f0 | 0xe21c | 2 | 0xfffc | 0x57506 | `diag22_pide21c_cal_id_chunk_1` |
| 0x5f4fc | 0xe21d | 3 | 0xfffc | 0x5752c | `diag22_pide21d_cal_id_chunk_2` |
| 0x5f508 | 0xe21e | 1 | 0xfffc | 0x57546 | `diag22_pide21e_cal_id_chunk_3` |
| 0x5f514 | 0xe611 | 24 | 0xfffc | 0x5755c | `diag22_pide611_sw_name_string` |
| 0x5f520 | 0x1710 | 7 | 0xfffc | 0x57594 | `diag22_pid1710_sensor_snapshot_7byte` |
| 0x5f52c | 0xc115 | 1 | 0x3bfc | 0x576b4 | `diag22_pidc115_ram_c1d2_raw` |
| 0x5f538 | 0xc116 | 4 | 0x3bfc | 0x576c2 | `diag22_pidc116_dtc_state_machine` |
| 0x5f544 | 0xc117 | 4 | 0x3bfc | 0x57704 | `diag22_pidc117_ram_c1d3_c1d4` |
| 0x5f550 | 0xc124 | 1 | 0x3bfc | 0x57738 | `diag22_pidc124_diag_status_bits` |
| 0x5f55c | 0xff10 | 4 | 0x0001 | 0x57884 | `diag22_pidff10_dtc_status_c1d5_c1d8` |
| 0x5f568 | 0xff40 | 2 | 0x0001 | 0x578e8 | `diag22_pidff40_fw_id_chunk_15` |
| 0x5f574 | 0xff41 | 4 | 0x0001 | 0x57902 | `diag22_pidff41_fw_id_chunk_120` |
| 0x5f580 | 0xff42 | 3 | 0x0001 | 0x5792e | `diag22_pidff42_rom_id_bytes_ff8` |
| 0x5f58c | 0xff43 | 3 | 0x0001 | 0x5794e | `diag22_pidff43_rom_id_bytes_ffb` |
| 0x5f598 | 0xff50 | 2 | 0x0001 | 0x5796e | `diag22_pidff50_ram_d3a0_raw` |
| 0x5f5a4 | 0xff44 | 2 | 0x0001 | 0x57974 | `diag22_pidff44_ram_ce30_raw` |

### UDS service dispatch records (0x5eb40, 29 x 12 bytes)

| record | service | handler | param | label |
|---|---|---|---|---|
| 0x5eb40 | 0x01 | 0x6581c | 0x00000001 | `obd_mode01_current_data` |
| 0x5eb4c | 0x02 | 0x65c88 | 0x00000001 | `obd_mode02_freeze_frame` |
| 0x5eb58 | 0x03 | 0x65ff8 | 0x00000001 | `obd_mode03_stored_dtc` |
| 0x5eb64 | 0x04 | 0x660d0 | 0x00000001 | `obd_mode04_clear_dtc` |
| 0x5eb70 | 0x06 | 0x6725c | 0x00000001 | `obd_mode06_test_results` |
| 0x5eb7c | 0x07 | 0x661ec | 0x00000001 | `obd_mode07_pending_dtc` |
| 0x5eb88 | 0x09 | 0x662c0 | 0x00000001 | `obd_mode09_vehicle_info` |
| 0x5eb94 | 0x28 | 0x5b9f6 | 0x00000001 | `uds_service_28_communication_control` |
| 0x5eba0 | 0x85 | 0x5dc44 | 0x00000001 | `uds_service_85_control_dtc_setting` |
| 0x5ebac | 0x10 | 0x57c8c | 0x1000000f | `uds_service_10_diagnostic_session_control` |
| 0x5ebb8 | 0x27 | 0x57a64 | 0x1000000e | `uds_service_27_security_access` |
| 0x5ebc4 | 0x3e | 0x56508 | 0x1000000f | `uds_service_3e_tester_present` |
| 0x5ebd0 | 0x11 | 0x5af54 | 0x0000000e | `uds_service_11_ecu_reset` |
| 0x5ebdc | 0x21 | 0x5b414 | 0x1000000f | `uds_service_21_read_data_by_local_id` |
| 0x5ebe8 | 0x22 | 0x567e8 | 0x1000000f | `uds_service_22_read_data_by_identifier` |
| 0x5ebf4 | 0x23 | 0x5b750 | 0x00000006 | `uds_service_23_read_memory_by_address` |
| 0x5ec00 | 0x3b | 0x5d8b4 | 0x0000000e | `uds_service_3b` |
| 0x5ec0c | 0x18 | 0x57db0 | 0x00000005 | `uds_service_18` |
| 0x5ec18 | 0x12 | 0x5b094 | 0x00000001 | `uds_service_12` |
| 0x5ec24 | 0x14 | 0x558ac | 0x10000005 | `uds_service_14_clear_diagnostic_information` |
| 0x5ec30 | 0x2f | 0x5bc4c | 0x10000004 | `uds_service_2f_input_output_control` |
| 0x5ec3c | 0x31 | 0x5df60 | 0x00000005 | `uds_service_31_routine_control` |
| 0x5ec48 | 0x32 | 0x5e024 | 0x00000005 | `uds_service_32` |
| 0x5ec54 | 0x33 | 0x5e0ce | 0x00000005 | `uds_service_33` |
| 0x5ec60 | 0x34 | 0x5d7bc | 0x00000002 | `uds_service_34_request_download` |
| 0x5ec6c | 0x36 | 0x5d834 | 0x00000002 | `uds_service_36_transfer_data` |
| 0x5ec78 | 0x37 | 0x5d874 | 0x00000002 | `uds_service_37_request_transfer_exit` |
| 0x5ec84 | 0xb1 | 0x565e8 | 0x0000000f | `uds_service_b1_mazda_specific` |
| 0x5ec90 | 0xff | 0x6689a | 0x00000000 | `uds_service_ff_default` |

## 4. Labeling applied (2026-10-31 pass)

- **175 functions** renamed via `source_review/accepted_function_aliases.tsv` + `integrate_reviewed_names.py`
  (symbols.tsv, function_index.tsv, callgraph.tsv, functions/*.c, named/firmware_named.c,
  firmware_decompiled.c; 3,355 bodies re-verified intact): 99 PID handlers
  (`diag22_pidXXXX_*`), 29 service handlers (`uds_service_XX_*` / `obd_modeXX_*`),
  ~34 diag reader/encoder helpers, ISO-TP/queue infrastructure (0x683d4, 0x6842c,
  0x68548, 0x6859e, 0x6872c, 0x68764, 0x68a86, 0x68b10, 0x68dac, 0x6010, 0x96be,
  0x579a8, 0x5fb08, 0x5fab2, 0x54884, 0x55316, 0x37358, 0x37546).
- **63 RAM cells** named via `accepted_ram_aliases.tsv` (incl. `diag_permission_mask_ffffd3b4`,
  `dtc_ram_flag_table_ffffd570`, `engine_runtime_counter_ffffd284`, `fuel_correction_sum_ffffc644`,
  `cranking_active_ffffaa62`); uncertain ones carry `inferred_`.
- **3 tables** named in `named/lookup_aliases.tsv` (0x5f10c, 0x5f5b2, 0x5eb40).
- Machine-readable pass record: `data/labels/60E15120_N3J1E/uds_dispatch_labels.json`;
  annotated tables: `diagnostic_dispatch_named.tsv`, `uds_service_dispatch.tsv`.

## 5. Corrections made in this pass

- `fueling_control_report.md` section 7.1 referenced the pre-rename names of the PID handlers
  (0x56b22/0x56b8a/0x56b9e/0x56f6c); updated to the new `diag22_pidXXXX_*` labels with a
  pointer to this report (found by `validate_reports.py`).
- The encode helpers are **divide**-by-step encoders: `rx8_encode_u16_affine_saturate`
  (0x2490) computes `trunc((signal-offset)/units_per_count + 0.5)` — e.g. PID 0x0005 ECT
  90 degC encodes to 130 (0x82), PID 0x000c 3000 rpm to 12000 (0x2ee0). Earlier notes that
  read the float constants as multipliers were corrected in the per-PID evidence strings.
- Service 0x33's record points to 0x5e0ce, a real code entry (prologue verified) that is
  **not** in function_index.tsv (Ghidra merged it into 0x5e024's body); it is named in
  `uds_service_dispatch.tsv` only. Service 0xff's handler is a `nop; rts` stub (0x6689a).

## 6. Files

- `data/labels/60E15120_N3J1E/uds_dispatch_labels.json` (this pass, full evidence per record)
- `data/labels/60E15120_N3J1E/diagnostic_dispatch_named.tsv` (99 annotated records)
- `data/labels/60E15120_N3J1E/uds_service_dispatch.tsv` (29 service records)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv` and
  `accepted_ram_aliases.tsv` (appended)
- `reverse-engineered/decompiled/60E15120_N3J1E/`: symbols.tsv, function_index.tsv,
  callgraph.tsv, functions/*.c, named/firmware_named.c, named/lookup_aliases.tsv,
  firmware_decompiled.c (renamed via `integrate_reviewed_names.py`)
- `data/labels/60E15120_N3J1E/integrated_names.json` (regenerated)
- `tests/test_phase1_dynamic.py` (`test_mode22_dispatch_table_payloads` added)
- `docs/investigations/60E15120_N3J1E/fueling_control_report.md` (one label reference updated)

## 7. Validation

- Binary level: every one of the 99 dispatch records and 29 service records re-read from
  the ROM and asserted byte-exact against the extraction TSVs; every handler address
  asserted to be a code entry (function start in `function_index.tsv`, disassembly
  instruction boundary, or prologue/`nop;rts` stub); ROM SHA-256 `a7cd953c...` unchanged.
- Dispatcher semantics verified in the disassembly: 0x5774c (12-byte record scan, mask
  check, header append, `r0 = rlen+3`), 0x68dac (table scan at 0x5eb40 via literal
  @0x68ed0, `record[8] & mask`, `jsr record[4]`), 0x6842c (frame-type switch),
  0x579a8 (0x5f5b2 sub-table scan).
- Dynamic (emulator): `test_mode22_dispatch_table_payloads` drives 0x5774c for 8 PIDs and
  asserts exact response bytes incl. the 0x62 header, plus the NRC 0x31 rejection path;
  `test_mode22_dispatch_pid_0043` (pre-existing) asserts r0 == 5 for PID 0x43.
- `python -m pytest tests/` — **59/59 pass**.
- Pipeline validators from repo root: `validate_export.py`, `validate_reports.py`,
  `verify_readability.py`, `verify_math_units.py` — all PASS; `hash_binaries.py --check`
  OK (binaries untouched).

## 8. Memory map for validation

Functions: dispatch 0x5774c, PID handlers 0x56890-0x57974 (per-record table in section 3),
service router 0x68dac, service handlers per table in section 3, ISO-TP 0x683d4/0x6842c/
0x68548/0x6859e/0x6872c/0x68764/0x68a86/0x68b10, entry/scheduler 0x680a0/0x684b4/0x6010/
0x96be, helpers 0x579a8/0x5fb08/0x5fab2/0x54884/0x55316/0x37358/0x37546/0x57858/0x57a0c/0x57a2e.
RAM: 0xffffd1ea/d1e8/d1ec diag22 state; 0xffffd3b4 permission mask; 0xffffddc8 UDS RX buf;
0xffffd962 ch0 response ring (pos 0xffffd95c); 0xffffddf5 UDS flags; 0xffffddec/ddea/dde6
channel/service/length; 0xffff9ec8 vehicle-present latch; 0xffffd570 DTC flag table;
plus the 63 named cells appended to `accepted_ram_aliases.tsv` (0xffffad5c/adec/ad10/ad48/
ad5e/a9c4/a9c6/a834/a984/add4/807c/a8f4/a8f5/a9bc/b074/b0d0/b2f0/b410/b53b/b570/b584/
b59c/b5ac/b5b4/b654/bc30/bc35/bdb8/bf3c/bf9c/c1d0-c1d8/c274/c4c8/c644/c6ac/cab4/cdd8/
ce1c/ce30/ce32/d1a1/d1a2/d284/d287/d3a0/d570/d1ac/d1ea/8788/90f4/90fc/9150/aa62...).
ROM strings: 0x2000 fw id, 0x6c000/0x6c043/0x6c046/0x6c05c cal ids, 0xff8-0xffd ID bytes.

## 9. Limits

- PID semantics for the 0x00xx range follow the public OBD-II PID definitions, anchored
  to the handler's encode math and RAM cell — the OBD standard is external reference
  knowledge, not a ROM read; Mazda-specific PIDs (0x09xx/0x11xx/0x16xx/0x17xx/0xa2xx/
  0xc1xx/0xe2xx/0xffxx) rest on logger defs + thread + handler behavior, and most carry
  medium confidence. They are hypotheses until cross-checked against a real-car datalog.
- The service table's `param` word (record[8]) is only partially decoded (used as a
  session-mask by 0x68dac); sub-function handling inside each service is not mapped.
- Services 0x12/0x18/0x32/0x33/0x3b/0xb1 are labeled by table position only; 0x33's
  handler entry (0x5e0ce) is missing from function_index.tsv (see section 5).
- E6 remainder still applies: response TX over CAN is driven via the profile `uds` entry
  points; the dynamic tests therefore call 0x5774c directly (the ROM's own dispatcher).
- `diag22_subpid_supported_mask` (0x579a8) return semantics (param & OR of bits) verified
  statically; the 0x1710 multi-byte snapshot PID is labeled only at the block level.

## 10. Update — 2026-10-31 (initial record of this pass)
