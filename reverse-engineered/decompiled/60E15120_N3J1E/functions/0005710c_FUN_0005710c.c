/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid172d_ram_a8f4_raw [medium]: dispatch record 0x5f418 -> handler verified in ROM bytes + function_index; raw DAT_ffffa8f4 u8
 * RAM 0xffffa8f4 inferred_ram_a8f4_ffffa8f4 (uint8): PID 0x172d raw
 */
/* ROM address: 0x0005710c; body bytes: 14; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f418. Table purpose inferred from
   neighboring code. */

void diag22_pid172d_ram_a8f4_raw(undefined4 param_1)

{
  diag_append_u8(param_1,(int)inferred_ram_a8f4_ffffa8f4_ffffa8f4);
  return;
}


