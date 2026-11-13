/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid000c_engine_rpm [high]: dispatch record 0x5f160 -> handler verified in ROM bytes + function_index; 0x55484: engine_speed_rpm_ffffb548*0.25 = OBD PID 0C A/4
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x000c: Engine Speed. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056982; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f168 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000c_engine_rpm(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_rpm();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


