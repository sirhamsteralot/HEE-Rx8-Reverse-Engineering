/* ROM address: 0x00028c6c; body bytes: 66; decompiled */

void FUN_00028c6c(void)

{
  if (DAT_ffffa41c == '\0') {
    if (DAT_ffffbac4 < 0x8000) {
      DAT_ffffbac4 = FUN_00002460((int)(short)DAT_ffffbac4,1);
    }
    else {
      DAT_ffffbac4 = 0x8000;
    }
    DAT_ffffbad4 = rx8_max_float(DAT_ffffb6ec - DAT_ffffb6f0,0.0);
  }
  return;
}


