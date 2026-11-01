/* ROM address: 0x00021302; body bytes: 276; decompiled */

uint FUN_00021302(void)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  
  cVar1 = DAT_ffffa444;
  fVar3 = (float)FUN_00002068(DAT_ffffb5cc,&DAT_0006aa4c);
  if ((((((0xb < DAT_ffffb2c2) && (cVar1 == '\0')) && (DAT_ffffb2d1 == '\x01')) &&
       ((DAT_ffffb138 == '\0' && (DAT_ffffa428 == '\x01')))) &&
      ((fVar3 < DAT_ffffb48c || ((DAT_ffffaada == '\0' && (DAT_ffffa450 == '\0')))))) &&
     ((0x2c < DAT_ffffb2c6 || (DAT_ffffb2d3 == 0)))) {
    DAT_ffffb2d3 = 1;
    DAT_ffffb2b4 = 0x43fa0000;
    DAT_ffffb2cc = 0;
    DAT_ffffb2c6 = 0;
    DAT_ffffb2d8 = 1;
  }
  uVar2 = (uint)DAT_ffffb2d3;
  if (uVar2 == 1) {
    if (DAT_ffffb2cc < 5) {
      FUN_00009630(0,4);
      DAT_ffffb2cc = FUN_00002478((int)(char)DAT_ffffb2cc,1);
    }
    else {
      DAT_ffffb2d8 = 0;
    }
    uVar2 = FUN_00002460((int)(short)DAT_ffffb2c6,1);
    DAT_ffffb2c6 = (ushort)uVar2;
  }
  if (cVar1 == '\0') {
    DAT_ffffb2c2 = 0;
  }
  else {
    uVar2 = FUN_00002460((int)(short)DAT_ffffb2c2,1);
    DAT_ffffb2c2 = (ushort)uVar2;
  }
  DAT_ffffb2d1 = cVar1;
  return uVar2;
}


