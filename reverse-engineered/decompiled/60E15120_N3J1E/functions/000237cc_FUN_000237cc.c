/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): 0x41a00000; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000237cc; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00024040 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000237cc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = 0x3cfa0000;
  DAT_ffffb442 = rx8_encode_u16_affine_saturate(0x41a00000,0x3cfa0000,0);
  DAT_ffffb444 = DAT_ffffb442;
  DAT_ffffb44a = rx8_encode_u16_affine_saturate(0x41700000,uVar1,uVar2);
  DAT_ffffb44c = rx8_encode_u16_affine_saturate(0x41700000,uVar1,uVar2);
  DAT_ffffb44e = inferred_pedal_volts_ffffa9c4_ffffa9c4;
  DAT_ffffb459 = DAT_ffffb459 | 1;
  DAT_ffffb45e = rx8_encode_u16_affine_saturate(0x41a00000,uVar1,uVar2);
  DAT_ffffb462 = rx8_encode_u16_affine_saturate(0x412db22d,0x3b800000,uVar2);
  return;
}


