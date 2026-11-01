/* ROM address: 0x000570e4; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f8e8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0005_coolant_temp_c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ect_c();
  diag_append_u8((int)param_1,uVar1);
  return;
}


