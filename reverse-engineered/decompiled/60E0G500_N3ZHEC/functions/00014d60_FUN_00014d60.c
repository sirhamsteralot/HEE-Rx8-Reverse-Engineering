/* ROM address: 0x00014d60; body bytes: 456; decompiled */

undefined4 FUN_00014d60(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined4 extraout_r0;
  undefined4 uVar4;
  undefined4 extraout_r0_00;
  undefined **ppuVar5;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar6;
  float fVar7;
  
  cVar3 = DAT_ffffbdd5;
  cVar2 = DAT_ffffb5ac;
  cVar1 = DAT_ffffa8b8;
  if (DAT_ffffbc1c < 10.0) {
    if (DAT_ffffbc1c < 9.0) {
      DAT_ffffa83b = '\0';
    }
  }
  else {
    DAT_ffffa83b = '\x01';
  }
  if ((DAT_ffffa41c == '\x01') ||
     ((DAT_ffffa7b8 < 0.0 &&
      (((DAT_ffffbdd5 == '\0' && (DAT_ffffa838 == '\x01')) ||
       ((DAT_ffffb5ac == '\0' && (DAT_ffffa839 == '\x01')))))))) {
    uVar4 = 1;
    DAT_ffffa7b8 = 0.0;
  }
  else if (DAT_ffffa7c4 == '\0') {
    if ((DAT_ffffa8b8 == '\x01') && (DAT_ffffa836 == '\0')) {
      uVar4 = 1;
      DAT_ffffa7b8 = DAT_ffffa8b4 + DAT_ffffa7b8;
    }
    else {
      DAT_ffffa7b8 = rx8_max_float(0.02,DAT_ffffa7d0 + 0.0);
      uVar4 = extraout_r0;
    }
  }
  else {
    fVar7 = DAT_ffffa848;
    if (((DAT_ffffa7c6 == '\0') && (DAT_ffffb5aa == '\0')) && (DAT_ffffa83b == '\x01')) {
      uVar4 = DAT_ffffaa14;
      DAT_ffffa7f4 = (float)FUN_00002068(DAT_ffffaa14,&PTR_DAT_000699dc);
      uVar4 = FUN_00002068(uVar4,&PTR_DAT_000699f0);
      DAT_ffffa7f8 = extraout_fr0;
    }
    else {
      uVar4 = DAT_ffffaa14;
      if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
        DAT_ffffa7f4 = (float)FUN_00002068(DAT_ffffaa14,&PTR_DAT_00069a04);
        ppuVar5 = &PTR_DAT_00069a18;
      }
      else {
        DAT_ffffa7f4 = (float)FUN_00002068(DAT_ffffaa14,&PTR_DAT_000699b4);
        ppuVar5 = &PTR_DAT_000699c8;
      }
      uVar4 = FUN_00002068(uVar4,ppuVar5);
      DAT_ffffa7f8 = extraout_fr0_00;
    }
    if (DAT_ffffa7c5 == '\0') {
      DAT_ffffa7d4 = DAT_ffffb5c0 - DAT_ffffa7bc;
      DAT_ffffa808 = (float)FUN_00002068(DAT_ffffa7d4,&DAT_00069a2c);
      fVar6 = rx8_clamp_float(DAT_ffffa7b8 + DAT_ffffa808,DAT_ffffa7f4,DAT_ffffa7f8);
      uVar4 = extraout_r0_00;
      if (fVar6 <= DAT_ffffa7b8) {
        if (DAT_ffffa850 < fVar7) {
          DAT_ffffa7b8 = fVar6;
        }
      }
      else if (fVar7 < DAT_ffffa84c) {
        DAT_ffffa7b8 = fVar6;
      }
    }
  }
  DAT_ffffa836 = cVar1;
  DAT_ffffa838 = cVar3;
  DAT_ffffa839 = cVar2;
  return uVar4;
}


