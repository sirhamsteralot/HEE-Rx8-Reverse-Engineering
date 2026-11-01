/* ROM address: 0x000277d8; body bytes: 64; decompiled */

void FUN_000277d8(void)

{
  float fVar1;
  
  if (DAT_ffffb72a != 0) {
    fVar1 = DAT_ffffb5b8;
    DAT_ffffb710 = rx8_absolute_difference(DAT_ffffb5b8,DAT_ffffb724);
    DAT_ffffb72a = 0;
    DAT_ffffb724 = fVar1;
  }
  DAT_ffffb72a = FUN_00002460((int)DAT_ffffb72a,1);
  return;
}


