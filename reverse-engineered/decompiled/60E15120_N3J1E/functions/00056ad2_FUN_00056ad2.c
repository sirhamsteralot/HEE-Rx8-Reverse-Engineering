/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid002f_ram_d287_raw [medium]: dispatch record 0x5f208 -> handler verified in ROM bytes + function_index; 0x5562c: DAT_ffffd287 raw byte
 */
/* ROM address: 0x00056ad2; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f210 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid002f_ram_d287_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_d287();
  diag_append_u8((int)param_1,uVar1);
  return;
}


