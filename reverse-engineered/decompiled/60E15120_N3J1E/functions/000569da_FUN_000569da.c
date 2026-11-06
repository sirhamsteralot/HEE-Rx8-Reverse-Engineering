/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0010_maf_g_s [high]: dispatch record 0x5f190 -> handler verified in ROM bytes + function_index; 0x55528: mass_air_flow_ffffa9ec*0.01 = OBD PID 10 A/100
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0010: Mass Air Flow. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x000569da; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f198 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0010_maf_g_s(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_maf();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


