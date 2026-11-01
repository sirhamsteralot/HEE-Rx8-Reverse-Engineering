/* ROM address: 0x000393f4; body bytes: 150; decompiled */

uint FUN_000393f4(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  float arg1;
  
  fVar3 = DAT_ffffc560;
  if (DAT_ffffc573 == 1) {
    DAT_ffffc568 = FUN_00002460((int)DAT_ffffc568,1);
  }
  fVar2 = (float)FUN_0003ea74(DAT_ffffc564,0x41200000);
  arg1 = 0.0;
  DAT_ffffc560 = rx8_max_float(fVar2 + (DAT_ffffc538 - DAT_ffffaa10) * 87891.0,0.0);
  uVar1 = (uint)DAT_ffffc573;
  if (uVar1 == 1) {
    DAT_ffffc55c = rx8_max_float((DAT_ffffc55c + DAT_ffffc560) - fVar3,arg1);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


