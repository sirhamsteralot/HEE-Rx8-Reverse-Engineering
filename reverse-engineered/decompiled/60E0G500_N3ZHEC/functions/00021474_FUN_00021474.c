/* ROM address: 0x00021474; body bytes: 276; decompiled */

uint FUN_00021474(void)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  
  cVar1 = DAT_ffffa445;
  fVar3 = (float)FUN_00002068(DAT_ffffb5cc,&DAT_0006aa4c);
  if ((((((0xb < DAT_ffffb2c4) && (cVar1 == '\0')) && (DAT_ffffb2d2 == '\x01')) &&
       ((DAT_ffffb139 == '\0' && (DAT_ffffa428 == '\x01')))) &&
      ((fVar3 < DAT_ffffb48c || ((DAT_ffffaada == '\0' && (DAT_ffffa450 == '\0')))))) &&
     ((0x2c < DAT_ffffb2c8 || (DAT_ffffb2d4 == 0)))) {
    DAT_ffffb2d4 = 1;
    DAT_ffffb2b8 = 0x43fa0000;
    DAT_ffffb2cd = 0;
    DAT_ffffb2c8 = 0;
    DAT_ffffb2d9 = 1;
  }
  uVar2 = (uint)DAT_ffffb2d4;
  if (uVar2 == 1) {
    if (DAT_ffffb2cd < 5) {
      FUN_00009630(0,4);
      DAT_ffffb2cd = FUN_00002478((int)(char)DAT_ffffb2cd,1);
    }
    else {
      DAT_ffffb2d9 = 0;
    }
    uVar2 = FUN_00002460((int)(short)DAT_ffffb2c8,1);
    DAT_ffffb2c8 = (ushort)uVar2;
  }
  if (cVar1 == '\0') {
    DAT_ffffb2c4 = 0;
  }
  else {
    uVar2 = FUN_00002460((int)(short)DAT_ffffb2c4,1);
    DAT_ffffb2c4 = (ushort)uVar2;
  }
  DAT_ffffb2d2 = cVar1;
  return uVar2;
}


