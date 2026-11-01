/* ROM address: 0x00056ad2; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f210 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid002f_ram_d287_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = candidate_diag_read_d287();
  diag_append_u8((int)param_1,uVar1);
  return;
}


