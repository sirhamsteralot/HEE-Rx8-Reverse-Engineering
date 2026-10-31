/* [ADDITIONAL SOURCE REVIEW]
 * trailing_timing_cranking_blend [high]: Trailing mirror: a650 = a5ec*a654 + (a5f4 + a71c + caa0)*(1-a654) + a784 - a77c. Dynamically verified bit-exact in the emulator (a650=18.115 for scripted inputs).
 */
/* ROM address: 0x000124d6; body bytes: 164; decompiled */

undefined4 trailing_timing_cranking_blend(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  
  if (engine_speed_rpm_ffffb548 < DAT_ffffa7ac + 10000.0) {
    if (engine_speed_rpm_ffffb548 < (DAT_ffffa7ac + 10000.0) - 100.0) {
      DAT_ffffa669 = '\0';
    }
  }
  else {
    DAT_ffffa669 = '\x01';
  }
  fVar2 = 1.0;
  if ((DAT_ffffaa62 == '\x01') && (DAT_ffffa669 == '\0')) {
    DAT_ffffa654 = rx8_max_float(DAT_ffffa654 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa654 = rx8_min_float(DAT_ffffa654 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa650 = (DAT_ffffa5ec * DAT_ffffa654 +
                  (DAT_ffffa5f4 + DAT_ffffa71c + DAT_ffffcaa0) * (fVar2 - DAT_ffffa654) +
                 DAT_ffffa784) - DAT_ffffa77c;
  return uVar1;
}


