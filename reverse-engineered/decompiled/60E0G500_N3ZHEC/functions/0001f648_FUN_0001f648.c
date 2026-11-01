/* ROM address: 0x0001f648; body bytes: 186; decompiled */

uint FUN_0001f648(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  float fVar4;
  
  cVar2 = DAT_ffffb14e;
  sVar1 = DAT_ffffb144;
  fVar4 = DAT_ffffae6c;
  if (((DAT_ffffb16f == '\0') && (DAT_ffffb14e == '\x01')) ||
     ((DAT_ffffb168 != 0 && (DAT_ffffb144 == 0)))) {
    DAT_ffffb146 = FUN_000020c4(DAT_ffffb290,&PTR_PTR_0006a2d0);
  }
  if ((((DAT_ffffae97 == 1) && (1.0 < fVar4)) && (fVar4 < 1.002)) && (DAT_ffffb146 != 0)) {
    DAT_ffffb146 = DAT_ffffb146 + -1;
  }
  if (DAT_ffffb146 != 0) {
    if (DAT_ffffb166 < 0x1d5) {
      uVar3 = FUN_00002460((int)(short)DAT_ffffb166,1);
      DAT_ffffb166 = (short)uVar3;
      DAT_ffffb168 = sVar1;
      DAT_ffffb16f = cVar2;
      return uVar3;
    }
    DAT_ffffb146 = 0;
  }
  DAT_ffffb166 = 0;
  DAT_ffffb168 = sVar1;
  DAT_ffffb16f = cVar2;
  return (uint)DAT_ffffae97;
}


