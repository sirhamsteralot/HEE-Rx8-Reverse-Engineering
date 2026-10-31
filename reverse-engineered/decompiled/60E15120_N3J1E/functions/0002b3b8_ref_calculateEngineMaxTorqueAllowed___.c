/* ROM address: 0x0002b3b8; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bb0c (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateEngineMaxTorqueAllowed___(void)

{
  float fVar1;
  float arg1;
  
  arg1 = 0.0;
  if ((((DAT_ffffbb24 == '\0') && (DAT_ffffbb28 == '\0')) && (engine_running_ffffa428 == '\x01')) &&
     (((DAT_ffffbbe8 != 0 && (DAT_ffffa401 == '\0')) && (DAT_ffffa40a == '\0')))) {
    fVar1 = (float)rx8_decode_u8_affine(0x3ec99326,0,(int)DAT_ffffbbc8);
  }
  else {
    fVar1 = 512.0;
  }
  DAT_ffffbbd8 = rx8_clamp_float(((DAT_ffffbb20 * fVar1) / 100.0 - DAT_ffffbcb8) - DAT_ffffbcbc,arg1
                                 ,512.0);
  return;
}


