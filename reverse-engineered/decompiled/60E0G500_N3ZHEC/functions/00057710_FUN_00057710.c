/* ROM address: 0x00057710; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5fb40 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1410_injector_pulse_time(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00002490(DAT_ffffbe90,0x41000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


