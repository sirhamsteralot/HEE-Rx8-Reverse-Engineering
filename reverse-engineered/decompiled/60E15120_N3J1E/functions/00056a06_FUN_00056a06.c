/* ROM address: 0x00056a06; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f1b0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0012_secondary_air_status(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_secondary_air_status();
  diag_append_u8((int)param_1,uVar1);
  return;
}


