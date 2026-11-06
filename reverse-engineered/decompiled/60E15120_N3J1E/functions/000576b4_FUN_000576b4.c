/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidc115_ram_c1d2_raw [medium]: dispatch record 0x5f52c -> handler verified in ROM bytes + function_index; raw DAT_ffffc1d2 u8
 * RAM 0xffffc1d2 inferred_ram_c1d2_ffffc1d2 (uint8): PID 0xc115 raw
 */
/* ROM address: 0x000576b4; body bytes: 14; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f52c. Table purpose inferred from
   neighboring code. */

void candidate_diag22_pidc115_ram_c1d2_raw(undefined4 param_1)

{
  diag_append_u8(param_1,(int)inferred_ram_c1d2_ffffc1d2_ffffc1d2);
  return;
}


