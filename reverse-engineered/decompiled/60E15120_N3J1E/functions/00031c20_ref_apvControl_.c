/* [ADDITIONAL SOURCE REVIEW]
 * apv_control_task [high]: APV wrapper under mask 0x10: calls 0x31c6c (target/condition), ref_apvPositionVoltageCounter (0x31ece), ref_calcAPVCounter (0x31f0a), 0x31f32 (command), ref_setAPVDC_00031bec. Called from 0x11744 (task 0x64f6 chain). Harness: APV motor PCM 3J/3G, signal 3B, ref 1S, return 1U.
 */
/* ROM address: 0x00031c20; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000320c8 (48 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV control wrapper (0x31c6c/0x31ece/0x31f0a/0x31f32/0x31bec). pinout v3: APV motor 3J/3G, signal 3B, power 1S, return 1U (all HP ³); colours L/R, G/B, R/G, R/W. Electrical proof still absent. */

void apv_control_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  candidate_apv_target_condition();
  candidate_apv_position_voltage_counter();
  candidate_apv_counter_calc();
  candidate_apv_command_calc();
  candidate_apv_command_wrapper();
  ref_setSR(uVar1);
  return;
}


