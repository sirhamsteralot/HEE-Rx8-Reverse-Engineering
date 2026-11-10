/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff50_ram_d3a0_raw [medium]: dispatch record 0x5f598 -> handler verified in ROM bytes + function_index; raw DAT_ffffd3a0 u16
 * RAM 0xffffd3a0 inferred_ram_d3a0_ffffd3a0 (uint16): PID 0xff50 raw
 */
/* ROM address: 0x0005796e; body bytes: 6; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f598. Table purpose inferred from
   neighboring code. */

void diag22_pidff50_ram_d3a0_raw(undefined4 param_1)

{
  diag_append_u16_be(param_1,(int)inferred_ram_d3a0_ffffd3a0_ffffd3a0);
  return;
}


