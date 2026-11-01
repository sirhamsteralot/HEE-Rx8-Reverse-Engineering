/* ROM address: 0x000498a0; body bytes: 4; decompiled */

uint thunk_FUN_000498ba(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = DAT_ffffae54;
  fVar4 = DAT_ffffaa14;
  fVar2 = rx8_absolute_difference(DAT_ffffae54,DAT_ffffaa14);
  uVar1 = 1;
  if ((DAT_ffffc656 == '\x01') || (uVar1 = (uint)DAT_ffffc64b, uVar1 == 1)) {
    DAT_ffffcd38 = 60.0;
  }
  else if ((3.0 < fVar2) || ((40.0 < fVar3 || (40.0 < fVar4)))) {
    fVar3 = (float)FUN_0003eb72(0x41a00000,&DAT_ffff8790);
    DAT_ffffcd38 = rx8_max_float(fVar3,20.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffcd38 = (fVar3 + fVar4) / 2.0;
  }
  DAT_ffffcd34 = DAT_ffffcd38;
  return uVar1;
}


