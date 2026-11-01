/* ROM address: 0x0001486c; body bytes: 102; decompiled */

void FUN_0001486c(void)

{
  char cVar1;
  
  if (DAT_ffffa7ad != '\0') {
    DAT_ffffa7ad = DAT_ffffa7ad + -1;
  }
  if (DAT_ffffb5b8 < 500.0) {
    cVar1 = DAT_ffffa7ae;
    if (DAT_ffffb5b8 < 300.0) {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = '\x01';
    if (DAT_ffffa7ae == '\0') {
      DAT_ffffa7ad = FUN_000020ac(DAT_ffffaa10,&PTR_PTR_0006abc8);
    }
  }
  DAT_ffffa7ae = cVar1;
  if (DAT_ffffa7ad != '\0') {
    cVar1 = '\0';
  }
  DAT_ffffa7ac = cVar1;
  return;
}


