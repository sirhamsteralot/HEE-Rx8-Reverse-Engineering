/* ROM address: 0x00043560; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042d94 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00043560(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffca44;
  if (uVar1 == 1) {
    DAT_ffffc9b4 = rx8_clamp_float(DAT_ffffbc90,0.0009999999,0.099999994);
    DAT_ffffc9b0 = (DAT_ffffc9b8 * DAT_ffffbc98) / DAT_ffffc9b4;
    uVar1 = extraout_r0;
  }
  return uVar1;
}


