/* ROM address: 0x0005706e; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f8d0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0003_fuel_system_status_ol_cl(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = FUN_00055b02();
  uVar1 = FUN_00055b7c();
  diag_append_u16_be((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


