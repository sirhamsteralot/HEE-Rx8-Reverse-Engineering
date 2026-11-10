/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0033_ram_ad10_scaled [medium]: dispatch record 0x5f22c -> handler verified in ROM bytes + function_index; 0x556ce: DAT_ffffad10*25.325+0.0182
 */
/* ROM address: 0x00056b0e; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f234 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0033_ram_ad10_scaled(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ad10();
  diag_append_u8((int)param_1,uVar1);
  return;
}


