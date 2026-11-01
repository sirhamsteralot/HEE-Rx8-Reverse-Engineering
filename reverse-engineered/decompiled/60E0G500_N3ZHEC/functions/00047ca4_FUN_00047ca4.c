/* ROM address: 0x00047ca4; body bytes: 80; decompiled */

void FUN_00047ca4(void)

{
  float fVar1;
  
  if (DAT_ffffccf8 < 0x32) {
    DAT_ffffccc8 = 1.0;
  }
  else if (DAT_ffffccf8 == 0x32) {
    fVar1 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
    DAT_ffffccc8 = DAT_ffffb520 - fVar1;
  }
  else {
    DAT_ffffccc8 = rx8_min_float(11.0,DAT_ffffccc8 + 0.05);
  }
  return;
}


