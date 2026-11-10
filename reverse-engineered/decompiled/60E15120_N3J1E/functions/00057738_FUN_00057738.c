/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidc124_diag_status_bits [medium]: dispatch record 0x5f550 -> handler verified in ROM bytes + function_index; 0x37546: DAT_ffffc1d0 -> 0x40, DAT_ffffc274 -> 4
 */
/* ROM address: 0x00057738; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f558 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidc124_diag_status_bits(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_status_bit_pack();
  diag_append_u8((int)param_1,uVar1);
  return;
}


