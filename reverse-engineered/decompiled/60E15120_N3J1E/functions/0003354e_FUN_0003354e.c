/* [ADDITIONAL SOURCE REVIEW]
 * idle_ac_blend_ramp [medium]: 0xffffc048: MT (b534==0) 0 when b53c==0, 0.04 when c05b==0, else decays 0.0008 to 0; AT (b534==1) forces 0. Called from 0x167c0 via pool 0x168e0.
 */
/* ROM address: 0x0003354e; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033876 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_idle_ac_blend_ramp(void)

{
  char cVar1;
  
  cVar1 = at_drive_range_engaged_ffffb53c;
  if (automatic_transmission_ffffb534 == '\0') {
    if (at_drive_range_engaged_ffffb53c == '\0') {
      DAT_ffffc048 = 0.0;
    }
    else if (DAT_ffffc05b == '\0') {
      DAT_ffffc048 = 0.04;
    }
    else {
      DAT_ffffc048 = rx8_max_float(DAT_ffffc048 - 0.0008,0.0);
    }
    DAT_ffffc05b = cVar1;
  }
  else {
    DAT_ffffc048 = 0.0;
  }
  return;
}


