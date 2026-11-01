/* ROM address: 0x0004458c; body bytes: 106; decompiled */

uint FUN_0004458c(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  
  uVar1 = (uint)DAT_ffffcab4;
  if ((uVar1 == 1) && (uVar1 = 1, 1 < DAT_ffffcaaf)) {
    fVar2 = rx8_clamp_float((DAT_ffffaa10 - -30.0) * 0.01,0.0,1.0);
    fVar3 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006bbdc);
    fVar3 = rx8_min_float(DAT_ffffca18,fVar3);
    DAT_ffffca10 = fVar3 * fVar2;
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffca10 = 0.0;
  }
  DAT_ffffca14 = DAT_ffffca10;
  return uVar1;
}


