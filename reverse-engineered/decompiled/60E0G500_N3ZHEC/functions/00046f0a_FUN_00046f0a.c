/* ROM address: 0x00046f0a; body bytes: 132; decompiled */

uint FUN_00046f0a(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float arg1;
  
  arg1 = DAT_ffffc12c;
  fVar4 = rx8_min_float(DAT_ffffcc7c,DAT_ffffc12c);
  fVar5 = rx8_max_float(DAT_ffffcc80,arg1);
  bVar1 = fVar5 - fVar4 < 2.0;
  DAT_ffffcc7c = arg1;
  DAT_ffffcc80 = arg1;
  if (bVar1) {
    DAT_ffffcc7c = fVar4;
    DAT_ffffcc80 = fVar5;
  }
  uVar3 = (uint)bVar1;
  uVar2 = (uint)DAT_ffffcc88;
  if ((DAT_ffffcc88 == 1) && (uVar2 = uVar3, uVar3 == 1)) {
    DAT_ffffcc89 = 1;
    uVar2 = FUN_00002460((int)DAT_ffffcc8e,1);
    DAT_ffffcc8e = (short)uVar2;
  }
  else {
    DAT_ffffcc89 = 0;
    DAT_ffffcc8e = 0;
  }
  return uVar2;
}


