/* ROM address: 0x0003413e; body bytes: 88; decompiled */

void FUN_0003413e(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffb5ac;
  if (DAT_ffffb5a4 == '\0') {
    if (DAT_ffffb5ac == '\0') {
      DAT_ffffc0b0 = 0.0;
    }
    else if (DAT_ffffc0c3 == '\0') {
      DAT_ffffc0b0 = 0.04;
    }
    else {
      DAT_ffffc0b0 = rx8_max_float(DAT_ffffc0b0 - 0.0008,0.0);
    }
    DAT_ffffc0c3 = cVar1;
  }
  else {
    DAT_ffffc0b0 = 0.0;
  }
  return;
}


