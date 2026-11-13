/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0005_coolant_temp_c [high]: dispatch record 0x5f13c -> handler verified in ROM bytes + function_index; 0x5542a: coolant_temperature_ffff9f70*1.0-40.0 = OBD PID 05 A-40
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0005: Coolant Temp. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056940; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f144 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0005_coolant_temp_c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ect_c();
  diag_append_u8((int)param_1,uVar1);
  return;
}


