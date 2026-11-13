/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0011_throttle_position_pct [high]: dispatch record 0x5f19c -> handler verified in ROM bytes + function_index; 0x5553e: inferred_throttle_sensor_volts_ffffad5c_ffffad5c decode(7.63e-05)*20*0.392157 = OBD PID 11 throttle %
 */
/* ROM address: 0x000569f0; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f1a4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0011_throttle_position_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_throttle_pct();
  diag_append_u8((int)param_1,uVar1);
  return;
}


