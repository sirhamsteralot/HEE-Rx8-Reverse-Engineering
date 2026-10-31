/* ROM address: 0x00028c52; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000295fa (38 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context: oil pressure switch is PCM 2E and closes on low pressure (pp18-19); oil level
   switch is separate at PCM 2R. This inherited oil-pressure status name is not proof that the
   underlying input bit has been traced to PCM 2E. */

void ref_setOilPressureGaugeStatus(void)

{
  if ((DAT_ffffbc14 == '\0') || (DAT_ffffb6c8 == '\x01')) {
    DAT_ffffbab0 = 1;
  }
  else {
    DAT_ffffbab0 = 0;
  }
  return;
}


