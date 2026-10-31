/* ROM address: 0x00029694; body bytes: 162; decompiled */

uint FUN_00029694(void)

{
  char cVar2;
  uint uVar1;
  float fVar3;
  float arg1;
  
  arg1 = 0.0;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffbb20,0,0x3727c5ac);
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb1a = 0xff;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
    if ((engine_running_ffffa428 == '\0') || (uVar1 = (uint)DAT_ffffb0cb, uVar1 == 1)) {
      DAT_ffffbb1a = 0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffbb1a = 0xfe;
    }
    else {
      fVar3 = (DAT_ffffbca8 * 100.0) / DAT_ffffbb20;
      if (DAT_ffffb0ca == '\x01') {
        fVar3 = fVar3 * 0.5;
      }
      fVar3 = rx8_clamp_float(fVar3,arg1,100.0);
      uVar1 = rx8_encode_u8_affine_saturate(fVar3,0x3ec99326,arg1);
      DAT_ffffbb1a = (undefined1)uVar1;
    }
  }
  return uVar1;
}


