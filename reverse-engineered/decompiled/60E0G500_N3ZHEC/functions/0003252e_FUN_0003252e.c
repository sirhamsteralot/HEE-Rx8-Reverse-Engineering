/* ROM address: 0x0003252e; body bytes: 164; decompiled */

uint FUN_0003252e(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = DAT_ffffc530;
  if (((DAT_ffffbfe7 == '\0') && (DAT_ffffc530 == '\x01')) && (DAT_ffffbfe6 == '\0')) {
    FUN_0003238c();
    uVar2 = 1;
    DAT_ffffbfe6 = '\x01';
  }
  else if ((DAT_ffffa41c != '\x01') || (DAT_ffffc6b4 <= 350.0)) {
    if ((350.0 <= DAT_ffffc6b4) || (DAT_ffffbfd6 < 0x5267)) {
      uVar2 = (uint)DAT_ffffbfd4;
      if ((uVar2 == 1) && (DAT_ffffbfd8 != 0)) {
        DAT_ffffbfd8 = DAT_ffffbfd8 + -1;
      }
    }
    else {
      uVar2 = FUN_000020c4(DAT_ffffaa10,&PTR_DAT_0006b1bc);
      DAT_ffffbfd8 = (short)uVar2;
    }
  }
  else {
    DAT_ffffbfd8 = 0;
    uVar2 = 1;
  }
  DAT_ffffbfe7 = cVar1;
  return uVar2;
}


