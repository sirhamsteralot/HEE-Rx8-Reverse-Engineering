/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0042_battery_voltage_v [high]: dispatch record 0x5f25c -> handler verified in ROM bytes + function_index; 0x55732: inferred_battery_voltage_ffffb590*0.001 = OBD PID 42
 */
/* ROM address: 0x00056b76; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f264 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0042_battery_voltage_v(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_battery_v();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


