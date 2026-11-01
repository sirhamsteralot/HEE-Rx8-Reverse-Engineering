/* ROM address: 0x00012452; body bytes: 164; decompiled */

undefined4 FUN_00012452(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 uVar1;
  float fVar2;
  
  if (DAT_ffffb5b8 < DAT_ffffa7bc + 10000.0) {
    if (DAT_ffffb5b8 < (DAT_ffffa7bc + 10000.0) - 100.0) {
      DAT_ffffa66c = '\0';
    }
  }
  else {
    DAT_ffffa66c = '\x01';
  }
  fVar2 = 1.0;
  if ((DAT_ffffaada == '\x01') && (DAT_ffffa66c == '\0')) {
    DAT_ffffa650 = rx8_max_float(DAT_ffffa650 - 0.05,0.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa650 = rx8_min_float(DAT_ffffa650 + 1.0,1.0);
    uVar1 = extraout_r0_00;
  }
  DAT_ffffa64c = (DAT_ffffa5ec * DAT_ffffa650 +
                  (DAT_ffffa5f4 + DAT_ffffa718 + DAT_ffffcb0c) * (fVar2 - DAT_ffffa650) +
                 DAT_ffffa790) - DAT_ffffa788;
  return uVar1;
}


