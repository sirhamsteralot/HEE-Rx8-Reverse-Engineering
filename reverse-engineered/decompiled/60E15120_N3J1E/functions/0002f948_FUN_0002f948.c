/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_request_force_step [medium]: Calls 0x2fbf0 (DAT_ffffbdd8 = 1), 0x2fbf8 (DAT_ffffbddc = 0xffff), 0x2f890 (PE2 output) - pools 0x2f9a4/0x2f9a8/0x2f9ac. Called from FUN_0001102a (pool 0x11308, jsr at 0x11136), which is itself entered once from the init chain (pool 0x628c = 0x0001102a, jsr at 0x61e4): the prime is a start-up action, not a periodic pass.
 */
/* ROM address: 0x0002f948; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fe00 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_fuel_pump_request_force_step(void)

{
  candidate_fuel_pump_request_set();
  fuel_pump_run_on_disable();
  candidate_fuel_pump_relay_drive_pe2();
  return;
}


