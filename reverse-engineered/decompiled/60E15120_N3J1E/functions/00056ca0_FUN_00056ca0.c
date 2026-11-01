/* ROM address: 0x00056ca0; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2c4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0200_dtc_count_stored(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_dtc_count_stored();
  diag_append_u8((int)param_1,uVar1);
  return;
}


