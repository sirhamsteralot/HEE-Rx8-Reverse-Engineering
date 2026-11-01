/* ROM address: 0x00033f6c; body bytes: 392; decompiled */

undefined4 * FUN_00033f6c(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *extraout_r0;
  undefined4 *extraout_r0_00;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float arg1;
  
  bVar2 = DAT_ffffbb54;
  cVar1 = DAT_ffffb5ac;
  puVar3 = (undefined4 *)&DAT_ffffb5a4;
  arg1 = 0.0;
  if (DAT_ffffb5a4 == '\0') {
    if (DAT_ffffa428 == '\x01') {
      DAT_ffffc0b4 = DAT_ffffbb34 / DAT_ffffa7bc;
    }
    fVar7 = DAT_ffffaa14;
    fVar8 = DAT_ffffbc1c;
    if (DAT_ffffa428 == '\0') {
      DAT_ffffc0b8 = 0.0;
      puVar3 = (undefined4 *)0x0;
    }
    else if (DAT_ffffb5ac == '\x01') {
      fVar6 = DAT_ffffa7bc;
      fVar4 = (float)FUN_00002068(DAT_ffffaa14,&DAT_0006b390);
      fVar5 = (float)FUN_00002068(DAT_ffffc0b4,&DAT_0006b3b8);
      puVar3 = &DAT_00034084;
      DAT_ffffc0b8 = (fVar6 / 1000.0) * (fVar6 / 1000.0) * fVar4 * fVar5;
    }
    else {
      fVar6 = (float)FUN_00002068(DAT_ffffaa14,&DAT_0006b3a4);
      DAT_ffffc0b8 = rx8_max_float(DAT_ffffc0b8 - fVar6,arg1);
      puVar3 = extraout_r0;
    }
    if ((bVar2 < 2) && (1 < DAT_ffffc0c2)) {
      DAT_ffffc0c0 = 0x32;
    }
    else if (DAT_ffffc0c0 != 0) {
      DAT_ffffc0c0 = DAT_ffffc0c0 + -1;
    }
    if ((cVar1 != '\0') && (0.0 < fVar8)) {
      if (((DAT_ffffc0c0 == 0) ||
          (((DAT_ffffaada != '\x01' || (DAT_ffffbb56 != '\x01')) || (fVar8 <= 3.0)))) ||
         ((10.0 <= fVar8 || (fVar7 <= 60.0)))) {
        arg1 = rx8_max_float(DAT_ffffc0bc - 0.0008,arg1);
        puVar3 = extraout_r0_00;
      }
      else {
        DAT_ffffc0bc = 0.03;
        puVar3 = (undefined4 *)0x1;
        arg1 = DAT_ffffc0bc;
      }
    }
    DAT_ffffc0bc = arg1;
    if (DAT_ffffb5ae == '\0') {
      DAT_ffffc0ac = DAT_ffffc0bc + DAT_ffffc0b8 * 0.0025;
    }
    else {
      DAT_ffffc0ac = DAT_ffffc0b8 * 0.0027;
    }
  }
  else {
    DAT_ffffc0ac = 0.0;
  }
  DAT_ffffc0c2 = bVar2;
  return puVar3;
}


