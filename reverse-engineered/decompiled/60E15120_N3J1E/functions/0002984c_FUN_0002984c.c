/* ROM address: 0x0002984c; body bytes: 128; decompiled */

int FUN_0002984c(void)

{
  char cVar2;
  int iVar1;
  float fVar3;
  float arg1;
  
  arg1 = 0.0;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffbb20,0,0x3727c5ac);
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb1b = 0xff;
    iVar1 = 1;
  }
  else {
    iVar1 = (int)engine_running_ffffa428;
    if (iVar1 == 0) {
      DAT_ffffbb1b = 0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffbb1b = 0xfe;
    }
    else {
      fVar3 = rx8_clamp_float((DAT_ffffbcb4 / DAT_ffffbb20) * 100.0,arg1,100.0);
      iVar1 = rx8_encode_u8_affine_saturate(fVar3,0x3ec99326,arg1);
      DAT_ffffbb1b = (undefined1)iVar1;
    }
  }
  return iVar1;
}


