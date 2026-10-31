/* ROM address: 0x00029f6e; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a6c2 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00029f6e(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb3e = 0xffff;
    uVar2 = 1;
  }
  else {
    if ((engine_running_ffffa428 == '\0') || (DAT_ffffb0cb == '\x01')) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = DAT_ffffbcac;
      if (DAT_ffffb0ca == '\x01') {
        fVar1 = DAT_ffffbcac * 0.5;
      }
    }
    uVar2 = 0xc4000000;
    fVar1 = rx8_clamp_float(fVar1,-512.0,65022.0);
    uVar2 = rx8_encode_u16_affine_saturate(fVar1,0x3f800000,uVar2);
    DAT_ffffbb3e = (undefined2)uVar2;
  }
  return uVar2;
}


