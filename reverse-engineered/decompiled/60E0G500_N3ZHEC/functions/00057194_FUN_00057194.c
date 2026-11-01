/* ROM address: 0x00057194; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f948 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0011_throttle_position_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_throttle_pct();
  diag_append_u8((int)param_1,uVar1);
  return;
}


