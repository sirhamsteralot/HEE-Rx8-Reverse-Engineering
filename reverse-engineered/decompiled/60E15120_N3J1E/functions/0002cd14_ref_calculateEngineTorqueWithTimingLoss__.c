/* ROM address: 0x0002cd14; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d3b8 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineTorqueWithTimingLoss__(void)

{
  float fVar1;
  
  fVar1 = (float)rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffbc83);
  DAT_ffffbcac = (4.0 - fVar1) * DAT_ffffbca4 * 0.25;
  return;
}


