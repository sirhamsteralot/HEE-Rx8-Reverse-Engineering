/* ROM address: 0x00014914; body bytes: 88; decompiled */

void FUN_00014914(void)

{
  undefined **ppuVar1;
  float fVar2;
  
  if (DAT_ffffb5a4 == '\x01') {
    fVar2 = (float)FUN_00002068(&PTR_DAT_0006a670);
  }
  else {
    if (DAT_ffffb5ac == '\x01') {
      ppuVar1 = &PTR_DAT_0006a698;
    }
    else {
      ppuVar1 = &PTR_DAT_0006a684;
    }
    fVar2 = (float)FUN_00002068(DAT_ffffb618,ppuVar1);
  }
  DAT_ffffa7b4 = FUN_0003ea74(fVar2 * 0.6345 * 60.0,DAT_ffffa7bc);
  return;
}


