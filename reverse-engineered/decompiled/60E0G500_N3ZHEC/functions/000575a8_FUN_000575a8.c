/* ROM address: 0x000575a8; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5fac8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid093c_throttle_position_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00002490(DAT_ffffadbc,0x3b000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


