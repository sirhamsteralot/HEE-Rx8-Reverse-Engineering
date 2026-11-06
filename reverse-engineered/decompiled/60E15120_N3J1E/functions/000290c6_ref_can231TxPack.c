/* ROM address: 0x000290c6; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029a6e (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte ref_can231TxPack(void)

{
  DAT_ffffbaec = DAT_ffffbae5 >> 4;
  cruise_switch_code_ffffbaed = DAT_ffffbae6 >> 4;
  DAT_ffffbae8 = rx8_decode_u16_affine(0x3c23d70a,0x3dcccccc,(int)DAT_ffffbaf2);
  DAT_ffffbaee = (DAT_ffffbaf1 & 0x80) == 0x80;
  DAT_ffffbaef = (DAT_ffffbaf1 & 8) == 8;
  return DAT_ffffbaf1 & 8;
}


