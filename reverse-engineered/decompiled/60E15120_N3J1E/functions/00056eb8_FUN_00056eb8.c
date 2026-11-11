/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1154_throttle_raw_ad5c [high]: dispatch record 0x5f364 -> handler verified in ROM bytes + function_index; raw DAT_ffffad5c u16 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056eb8; body bytes: 14; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f364. Table purpose inferred from
   neighboring code. */

void diag22_pid1154_throttle_raw_ad5c(undefined4 param_1)

{
  diag_append_u16_be(param_1,(int)inferred_throttle_sensor_volts_ffffad5c_ffffad5c);
  return;
}


