/* ROM address: 0x00012546; body bytes: 164; decompiled */

undefined4 FUN_00012546(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  
  if (DAT_ffffb5b8 < DAT_ffffa7bc + 10000.0) {
    if (DAT_ffffb5b8 < (DAT_ffffa7bc + 10000.0) - 100.0) {
      DAT_ffffa66d = '\0';
    }
  }
  else {
    DAT_ffffa66d = '\x01';
  }
  fVar2 = 1.0;
  if ((DAT_ffffaada == '\x01') && (DAT_ffffa66d == '\0')) {
    DAT_ffffa660 = rx8_max_float(DAT_ffffa660 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa660 = rx8_min_float(DAT_ffffa660 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa65c = (DAT_ffffa5f0 * DAT_ffffa660 +
                  (DAT_ffffa5f8 + DAT_ffffa71c + DAT_ffffcb10) * (fVar2 - DAT_ffffa660) +
                 DAT_ffffa794) - DAT_ffffa78c;
  return uVar1;
}


