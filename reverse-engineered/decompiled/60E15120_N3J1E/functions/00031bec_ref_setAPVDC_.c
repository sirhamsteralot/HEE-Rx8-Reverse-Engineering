/* [ADDITIONAL SOURCE REVIEW]
 * apv_command_wrapper [medium]: bf84 negated when bf8b==1, divided by 100, passed to apv_duty_split (0xaa90) — signed percent command.
 * RAM 0xffffbf84 apv_command_percent (float): APV command from 0x31f32 (staged 100.0/12.5 constants); negated when bf8b, /100 -> 0xaa90.
 * RAM 0xffffbf8b apv_direction_flag (uint8): When 1, negates the APV command (reverse) and resets bf8a.
 */
/* ROM address: 0x00031bec; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032094 (34 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV command wrapper. Firmware fact: float 0xffffbf84 negated when 0xffffbf8b==1, /100 -> 0xaa90. pinout v3: APV motor 3J/3G (HP ³). */

void candidate_apv_command_wrapper(void)

{
  float fVar1;
  
  fVar1 = apv_command_percent_ffffbf84;
  if (apv_direction_flag_ffffbf8b == '\x01') {
    fVar1 = -apv_command_percent_ffffbf84;
  }
  candidate_apv_command_wrapper(fVar1 / 100.0);
  return;
}


