/* [ADDITIONAL SOURCE REVIEW]
 * apv_duty_split [high]: param * 96.0 (period u16 at ROM 0x78bb6); positive -> a1c4, negative -> a1c6 (other zeroed): signed duty split into forward/reverse tick counts. See reconstructed/rx8_apv.c.
 * RAM 0xffffa1c4 apv_pwm_forward_ticks (uint16): Forward duty ticks from apv_duty_split (param*96).
 * RAM 0xffffa1c6 apv_pwm_reverse_ticks (uint16): Reverse duty ticks (other direction zeroed).
 */
/* ROM address: 0x0000aa90; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000aa90 (52 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV signed duty splitter. Firmware fact: period u16 at ROM 0x78bb6 (96); forward/reverse ticks -> 0xffffa1c4/a1c6. pinout v3: APV motor wires PCM 3J/3G (HP ³), colours L/R / R/W (*). See reconstructed/rx8_apv.c. */

void apv_duty_split(float param_1)

{
  param_1 = param_1 * 96.0;
  if (0.0 <= param_1) {
    apv_pwm_forward_ticks_ffffa1c4 = (undefined2)(int)param_1;
    apv_pwm_reverse_ticks_ffffa1c6 = 0;
  }
  else {
    apv_pwm_forward_ticks_ffffa1c4 = 0;
    apv_pwm_reverse_ticks_ffffa1c6 = (undefined2)(int)-param_1;
  }
  return;
}


