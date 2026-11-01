/* ROM address: 0x0002e22c; body bytes: 372; decompiled */

uint FUN_0002e22c(void)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  uint extraout_r0;
  undefined *puVar7;
  float extraout_fr0;
  undefined4 uVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  fVar9 = DAT_ffffc00c - DAT_ffffc008;
  DAT_ffffbd80 = DAT_ffffc008 - DAT_ffffc00c;
  uVar11 = DAT_ffffcf58;
  uVar1 = FUN_000020dc(DAT_ffffc008,DAT_ffffcf58,&DAT_0006adb8);
  uVar8 = 0;
  if (DAT_ffffbd59 == '\0') {
    DAT_ffffbd6c = 0.0;
    DAT_ffffbd84 = extraout_fr0;
    return uVar1;
  }
  if (DAT_ffffbdaa != 1) {
    DAT_ffffbd84 = extraout_fr0;
    return (uint)DAT_ffffbdaa;
  }
  uVar10 = 0x3727c5ac;
  DAT_ffffbd84 = extraout_fr0;
  cVar2 = FUN_00002440(uVar11,0x40000000,0x3727c5ac);
  cVar3 = FUN_00002440(uVar11,0x40400000,uVar10);
  cVar4 = FUN_00002440(uVar11,0x40800000,uVar10);
  cVar5 = FUN_00002440(uVar11,0x40a00000,uVar10);
  cVar6 = FUN_00002440(uVar11,0x40c00000,uVar10);
  if (cVar2 == '\0') {
    puVar7 = &DAT_0006ad40;
  }
  else if (cVar3 == '\0') {
    puVar7 = &DAT_0006ad4c;
  }
  else if (cVar4 == '\0') {
    puVar7 = &DAT_0006ad58;
  }
  else {
    if (cVar5 != '\0') {
      if (cVar6 == '\0') {
        puVar7 = &DAT_0006ad70;
      }
      else {
        puVar7 = &DAT_0006ad40;
      }
      DAT_ffffbd70 = (float)FUN_00002068(DAT_ffffbd80,puVar7);
      goto LAB_0002e370;
    }
    puVar7 = &DAT_0006ad64;
  }
  DAT_ffffbd70 = (float)FUN_00002068(puVar7);
LAB_0002e370:
  if ((100.0 <= fVar9) || (fVar9 < -100.0)) {
    fVar9 = DAT_ffffbd6c;
    if (DAT_ffffaa38 <= DAT_ffffbd64) {
      if (DAT_ffffbc33 != 1) {
        DAT_ffffbd6c = (float)uVar8;
        return (uint)DAT_ffffbc33;
      }
      if ((0xfd < DAT_ffffbc30) && (0xfd < DAT_ffffbc31)) {
        DAT_ffffbd6c = (float)uVar8;
        return (uint)DAT_ffffbc31;
      }
    }
  }
  else {
    fVar9 = DAT_ffffbd70 * DAT_ffffbd84 * 0.01;
  }
  DAT_ffffbd6c = rx8_clamp_float(fVar9,-100.0,100.0);
  return extraout_r0;
}


