/* ROM address: 0x00043a9e; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000432d2 (60 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV feedback-range logic on 0xffffcab0. pinout v3: APV position sensor power PCM 1S (R/W), return 1U (BR). */

char ref_getApvVoltageRange(void)

{
  if (apv_position_voltage_ffffcab0 < 1.5) {
    if (apv_position_voltage_ffffcab0 < 1.4) {
      DAT_ffffcab5 = '\0';
    }
  }
  else {
    DAT_ffffcab5 = '\x01';
  }
  inferred_ram_cab4_ffffcab4_ffffcab4 = DAT_ffffcab5 == '\x01';
  return DAT_ffffcab5;
}


