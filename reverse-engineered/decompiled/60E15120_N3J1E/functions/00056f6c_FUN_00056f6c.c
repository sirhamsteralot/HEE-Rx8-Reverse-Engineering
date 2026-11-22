/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1410_injector_pulse_time [high]: dispatch record 0x5f394 -> handler verified in ROM bytes + function_index; injector_pulse_time_ffffbe24*8 (logger 0x221410, ms scale)
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x1410: Injector Pulse Time. CONFLICT: same identifier also named Throttle Pedal Position. Do not assign a semantic alias.
 * RX8Defs service 0x22 identifier 0x1410: Throttle Pedal Position. CONFLICT: same identifier also named Injector Pulse Time. Do not assign a semantic alias.
 */
/* ROM address: 0x00056f6c; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f39c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1410_injector_pulse_time(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(injector_pulse_time_ffffbe24,0x41000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


