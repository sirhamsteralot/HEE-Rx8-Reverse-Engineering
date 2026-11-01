/* ROM address: 0x0005731a; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa08 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0042_battery_voltage_v(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_battery_v();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


