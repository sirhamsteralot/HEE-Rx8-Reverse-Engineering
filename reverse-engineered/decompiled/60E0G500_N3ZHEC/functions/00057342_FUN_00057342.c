/* ROM address: 0x00057342; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa20 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0044_lambda_target(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_lambda_target();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


