/* ROM address: 0x00056a58; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f1d4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid001c_obd_standard(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_obd_standard_const();
  diag_append_u8((int)param_1,uVar1);
  return;
}


