/* ROM address: 0x0003534c; body bytes: 546; decompiled */

undefined ** FUN_0003534c(void)

{
  char cVar1;
  undefined **ppuVar2;
  undefined **extraout_r0;
  float extraout_fr0;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float arg0;
  
  cVar1 = DAT_ffffa428;
  DAT_ffffc1c4 = DAT_ffffc12c - DAT_ffffc1f8;
  fVar4 = DAT_ffffc128;
  uVar5 = DAT_ffffb5b8;
  arg0 = DAT_ffffc12c;
  DAT_ffffc1c0 = rx8_absolute_difference(DAT_ffffc12c,DAT_ffffc1f8);
  DAT_ffffc1dc = arg0 - DAT_ffffc1fc;
  DAT_ffffc200 = (float)FUN_00002068(uVar5,&DAT_0006b614);
  ppuVar2 = (undefined **)FUN_00002068(uVar5,&DAT_0006b628);
  fVar6 = 0.0;
  if ((cVar1 == '\0') ||
     ((ppuVar2 = (undefined **)&DAT_ffffc200, DAT_ffffc200 <= DAT_ffffc1dc &&
      (DAT_ffffc1dc < extraout_fr0)))) {
    DAT_ffffc1c8 = 0.0;
  }
  else {
    DAT_ffffc1c8 = DAT_ffffc1dc;
  }
  DAT_ffffc1e0 = arg0;
  if (10.0 <= DAT_ffffc1c0) {
    DAT_ffffc1e0 = fVar4;
  }
  fVar3 = fVar4;
  DAT_ffffc204 = extraout_fr0;
  if (((cVar1 != '\0') &&
      (ppuVar2 = (undefined **)&DAT_00079fd2, fVar4 = arg0, fVar3 = arg0, DAT_ffffc1d8 < 0xfe)) &&
     (ppuVar2 = &PTR_DAT_00079fd4, DAT_ffffa426 != 0)) {
    if (((0.0 < DAT_ffffc1cc) && (DAT_ffffc1c4 < -10.0)) ||
       ((DAT_ffffc1cc <= 0.0 && (10.0 <= DAT_ffffc1c4)))) {
      DAT_ffffc1e4 = DAT_ffffc1f8;
      DAT_ffffc1f0 = DAT_ffffc1f8;
      fVar4 = DAT_ffffc1e4;
      fVar3 = DAT_ffffc1f0;
    }
    else {
      fVar4 = 1e-05;
      DAT_ffffc1e4 = rx8_first_order_filter(arg0,DAT_ffffc1e4,DAT_ffffc1e8,1e-05);
      fVar3 = rx8_first_order_filter(arg0,DAT_ffffc1f0,DAT_ffffc1f4,fVar4);
      ppuVar2 = extraout_r0;
      fVar4 = DAT_ffffc1e4;
    }
  }
  DAT_ffffc1f0 = fVar3;
  DAT_ffffc1e4 = fVar4;
  DAT_ffffc1d0 = DAT_ffffc1e0 - DAT_ffffc1e4;
  DAT_ffffc1ec = DAT_ffffc1e0 - DAT_ffffc1f0;
  DAT_ffffc1cc = fVar6;
  if ((cVar1 != '\0') && ((DAT_ffffc1d0 < -0.032227 || (0.032227 <= DAT_ffffc1d0)))) {
    DAT_ffffc1cc = DAT_ffffc1d0;
  }
  DAT_ffffc1d4 = fVar6;
  if ((cVar1 != '\0') && ((DAT_ffffc1ec < -0.032227 || (0.032227 <= DAT_ffffc1ec)))) {
    DAT_ffffc1d4 = DAT_ffffc1ec;
  }
  if (DAT_ffffc1c0 < 0.077148) {
    if (DAT_ffffc1ec < 0.0) {
      DAT_ffffc1f4 = 0.02;
    }
    else {
      DAT_ffffc1f4 = 0.008;
    }
  }
  else if (DAT_ffffc1ec < 0.0) {
    DAT_ffffc1f4 = 0.02;
  }
  else {
    DAT_ffffc1f4 = 0.008;
  }
  DAT_ffffc1e8 = 0.02;
  DAT_ffffc1fc = DAT_ffffc1f8;
  DAT_ffffc1f8 = arg0;
  return ppuVar2;
}


