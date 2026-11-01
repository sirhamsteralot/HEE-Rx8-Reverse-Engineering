/* ROM address: 0x0006900c; body bytes: 92; decompiled */

void FUN_0006900c(void)

{
  byte bVar1;
  
  bVar1 = FUN_00069068();
  if (bVar1 == 1) {
    DAT_ffffde34 = 1;
    FUN_00068adc();
    return;
  }
  DAT_ffffde34 = 0;
  DAT_ffffde0c = DAT_ffffde0c | bVar1;
  DAT_ffffde0d = 0;
  DAT_ffffde0e = 0;
  DAT_ffffde0f = 0;
  DAT_ffffde10 = 0;
  DAT_ffffde11 = 0;
  DAT_ffffde12 = 0;
  DAT_ffffde13 = 0;
  DAT_ffffde27 = 3;
  FUN_0006936a(5,0x12);
  return;
}


