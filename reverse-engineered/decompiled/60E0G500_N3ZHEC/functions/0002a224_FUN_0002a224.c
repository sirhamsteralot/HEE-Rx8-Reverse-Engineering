/* ROM address: 0x0002a224; body bytes: 162; decompiled */

uint FUN_0002a224(void)

{
  char cVar2;
  uint uVar1;
  float fVar3;
  float arg1;
  
  arg1 = 0.0;
  cVar2 = FUN_00002440(DAT_ffffbb88,0,0x3727c5ac);
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbb82 = 0xff;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
    if ((DAT_ffffa428 == '\0') || (uVar1 = (uint)DAT_ffffb13b, uVar1 == 1)) {
      DAT_ffffbb82 = 0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffbb82 = 0xfe;
    }
    else {
      fVar3 = (DAT_ffffbd14 * 100.0) / DAT_ffffbb88;
      if (DAT_ffffb13a == '\x01') {
        fVar3 = fVar3 * 0.5;
      }
      fVar3 = rx8_clamp_float(fVar3,arg1,100.0);
      uVar1 = FUN_000024d0(fVar3,0x3ec99326,arg1);
      DAT_ffffbb82 = (undefined1)uVar1;
    }
  }
  return uVar1;
}


