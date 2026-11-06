/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid000d_vehicle_speed_kmh [high]: dispatch record 0x5f16c -> handler verified in ROM bytes + function_index; 0x5549a: vehicle_speed_ffffbbb4*1.0 = OBD PID 0D
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x000d: Vehicle Speed. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056998; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f174 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid000d_vehicle_speed_kmh(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_vss();
  diag_append_u8((int)param_1,uVar1);
  return;
}


