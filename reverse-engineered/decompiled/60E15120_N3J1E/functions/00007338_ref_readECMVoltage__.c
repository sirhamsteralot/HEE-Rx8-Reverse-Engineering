/* ROM address: 0x00007338; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007338 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_readECMVoltage__(void)

{
  DAT_ffff9f6c = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f00,DAT_ffff9f6c,0x100);
  DAT_ffff9f68 = ((float)DAT_ffff9f6c / 65536.0) * 20.0;
  return &DAT_0000738c;
}


