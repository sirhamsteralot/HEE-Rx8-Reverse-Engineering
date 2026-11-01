/* ROM address: 0x0004a082; body bytes: 138; decompiled */

undefined4 FUN_0004a082(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = DAT_ffffaa10;
  fVar3 = DAT_ffffb5b8;
  cVar1 = FUN_000671a4(0x1e);
  if ((((((cVar1 != '\0') || (DAT_ffffcd72 < 0x20)) || (DAT_ffffcd60 != '\x01')) ||
       ((fVar3 < 500.0 || (5000.0 <= fVar3)))) ||
      ((fVar2 < 70.0 || ((120.0 <= fVar2 || (DAT_ffffad9c != '\x01')))))) || (DAT_ffffd201 != '\0'))
  {
    DAT_ffffcd74 = 0;
  }
  else {
    DAT_ffffcd74 = 1;
  }
  return 0;
}


