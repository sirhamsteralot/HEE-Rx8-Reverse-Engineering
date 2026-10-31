/* ROM address: 0x00028d24; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000296cc (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_scaleCoolantTempForCAN__(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffc5e6 == '\0') {
    uVar2 = 0xc2200000;
    fVar1 = rx8_clamp_float(DAT_ffffa994,-40.0,214.0);
    DAT_ffffbaab = rx8_encode_u8_affine_saturate(fVar1,0x3f800000,uVar2);
  }
  else {
    DAT_ffffbaab = 0xff;
  }
  return;
}


