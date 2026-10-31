/* [ADDITIONAL SOURCE REVIEW]
 * diag_injector_pulse_time [medium]: PID 0x1410 handler (logger def conflicts: 'Injector Pulse Time' vs 'Throttle Pedal Position' - do not trust either name): encodes DAT_ffffbe24 with step 8 (0x41000000); logger expr x*8*0.001 ms.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x1410: Injector Pulse Time. CONFLICT: same identifier also named Throttle Pedal Position. Do not assign a semantic alias.
 * RX8Defs service 0x22 identifier 0x1410: Throttle Pedal Position. CONFLICT: same identifier also named Injector Pulse Time. Do not assign a semantic alias.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): injector_pulse_time_ffffbe24; decode = raw * 8 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056f6c; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f39c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag_injector_pulse_time(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(injector_pulse_time_ffffbe24,0x41000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


