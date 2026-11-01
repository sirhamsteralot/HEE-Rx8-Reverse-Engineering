/* ROM address: 0x000576d4; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5fb28 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1177_maf_voltage_latched_v(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00002490(DAT_ffffaa80,0x39800000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


