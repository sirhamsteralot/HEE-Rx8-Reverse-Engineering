/* ROM address: 0x00013160; body bytes: 370; decompiled */

undefined4 * FUN_00013160(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  undefined4 *extraout_r0_00;
  undefined4 *extraout_r0_01;
  undefined4 *extraout_r0_02;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float arg1;
  float arg1_00;
  
  fVar7 = DAT_ffffa6b0;
  fVar6 = DAT_ffffa6ac;
  arg1 = DAT_ffffa6c0;
  arg1_00 = DAT_ffffa6bc;
  fVar3 = rx8_absolute_difference(DAT_ffffa6ac,DAT_ffffa6bc);
  fVar4 = rx8_absolute_difference(fVar7,arg1);
  fVar5 = fVar7 - arg1;
  fVar7 = arg1 - fVar7;
  if (DAT_ffffa6b9 == '\x01') {
    DAT_ffffa6cc = 5.0;
    DAT_ffffa6d0 = 5.0;
    pfVar2 = (float *)&DAT_0006f748;
    DAT_ffffa6d4 = 5.0;
  }
  else {
    if (DAT_ffffa6b7 != '\x01') {
      if (DAT_ffffa6b8 == '\x01') {
        DAT_ffffa6cc = 1.0;
        DAT_ffffa6d0 = 1.0;
        DAT_ffffa6d4 = 1.0;
        DAT_ffffa6d8 = 1.0;
        puVar1 = (undefined4 *)&UNK_00000001;
      }
      else {
        puVar1 = &DAT_0006f74c;
        DAT_ffffa6cc = 5.0;
        DAT_ffffa6d0 = 5.0;
        DAT_ffffa6d4 = 5.0;
        DAT_ffffa6d8 = 5.0;
      }
      goto LAB_00013238;
    }
    DAT_ffffa6cc = 1.0;
    DAT_ffffa6d0 = 1.0;
    pfVar2 = (float *)&DAT_0006f728;
    DAT_ffffa6d4 = 1.0;
  }
  puVar1 = (undefined4 *)&UNK_00000001;
  DAT_ffffa6d8 = *pfVar2;
LAB_00013238:
  if (DAT_ffffa428 == '\0') {
    DAT_ffffa6ac = 0.0;
    DAT_ffffa6b0 = 0.0;
  }
  else {
    puVar1 = (undefined4 *)&UNK_00000008;
    if (0.09999999 < fVar3) {
      if (arg1_00 - fVar6 <= 0.09999999) {
        puVar1 = (undefined4 *)&UNK_00000008;
        if (0.09999999 < fVar6 - arg1_00) {
          DAT_ffffa6ac = rx8_max_float(DAT_ffffa6ac - DAT_ffffa6d0,arg1_00);
          puVar1 = extraout_r0_00;
        }
      }
      else {
        DAT_ffffa6ac = rx8_min_float(DAT_ffffa6ac + DAT_ffffa6cc,arg1_00);
        puVar1 = extraout_r0;
      }
    }
    if (0.09999999 < fVar4) {
      if (fVar7 <= 0.09999999) {
        puVar1 = (undefined4 *)&UNK_00000004;
        if (0.09999999 < fVar5) {
          DAT_ffffa6b0 = rx8_max_float(DAT_ffffa6b0 - DAT_ffffa6d8,arg1);
          puVar1 = extraout_r0_02;
        }
      }
      else {
        DAT_ffffa6b0 = rx8_min_float(DAT_ffffa6b0 + DAT_ffffa6d4,arg1);
        puVar1 = extraout_r0_01;
      }
    }
  }
  return puVar1;
}


