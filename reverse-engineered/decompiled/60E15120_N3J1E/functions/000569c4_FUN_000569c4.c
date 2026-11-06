/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid000f_intake_air_temp_c [high]: dispatch record 0x5f184 -> handler verified in ROM bytes + function_index; 0x554c6: intake_air_temperature_ffff9f60*1.0-40 = OBD PID 0F
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x000f: Intake Air Temperature. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x000569c4; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f18c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000f_intake_air_temp_c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_iat();
  diag_append_u8((int)param_1,uVar1);
  return;
}


