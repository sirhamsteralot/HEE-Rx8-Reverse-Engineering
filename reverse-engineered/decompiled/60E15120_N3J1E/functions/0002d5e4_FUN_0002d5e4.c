/* ROM address: 0x0002d5e4; body bytes: 84; decompiled */

void FUN_0002d5e4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffbced;
  if (DAT_ffffbced == '\x01') {
    if ((DAT_ffffbd3f == '\0') || (0xf < DAT_ffffbd38)) {
      DAT_ffffbd3e = 1;
      DAT_ffffbd38 = 0;
    }
    else {
      DAT_ffffbd3e = 0;
    }
    DAT_ffffbd38 = rx8_add_u16_saturate((int)(short)DAT_ffffbd38,1);
  }
  else {
    DAT_ffffbd3e = 0;
    DAT_ffffbd38 = 0;
  }
  DAT_ffffbd3f = cVar1;
  return;
}


