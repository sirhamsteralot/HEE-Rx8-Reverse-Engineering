/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0045_ram_ad48_pct [medium]: dispatch record 0x5f280 -> handler verified in ROM bytes + function_index; 0x55774: DAT_ffffad48*0.392157
 */
/* ROM address: 0x00056bb2; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f288 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid0045_ram_ad48_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_encode_ad48();
  diag_append_u8((int)param_1,uVar1);
  return;
}


