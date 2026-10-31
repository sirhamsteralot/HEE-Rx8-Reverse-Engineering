/* ROM address: 0x000193c4; body bytes: 322; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00019508) */
/* WARNING: Removing unreachable block (ram,0x00019522) */
/* WARNING: Removing unreachable block (ram,0x00019510) */
/* WARNING: Removing unreachable block (ram,0x0001952e) */

undefined4 FUN_000193c4(void)

{
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  undefined4 extraout_r0_01;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float arg2;
  
  arg2 = 100.0;
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffa9ac,0x414b3333);
  fVar3 = 0.0;
  DAT_ffffa9b4 = rx8_clamp_float(fVar2 * arg2 - 0.0,0.0,arg2);
  fVar2 = (float)rx8_divide_with_zero_fallback(DAT_ffffa9b0,0x414b3333);
  DAT_ffffa9b8 = rx8_clamp_float(fVar2 * arg2 - 0.0,fVar3,arg2);
  if (DAT_ffffa9b4 < 50.0) {
    if (DAT_ffffa9b4 < 45.0) {
      DAT_ffffa9df = 0;
    }
  }
  else {
    DAT_ffffa9df = 1;
  }
  if (DAT_ffffcc9b == '\x01') {
    if (DAT_ffffcc9c == '\x01') {
      DAT_ffffa9bc = 15.0;
      uVar1 = 1;
    }
    else {
      DAT_ffffa9bc = rx8_min_float(13.5,DAT_ffffa9b8);
      uVar1 = extraout_r0;
    }
  }
  else if (DAT_ffffcc9c == '\x01') {
    DAT_ffffa9bc = rx8_min_float(13.5,DAT_ffffa9b4);
    uVar1 = extraout_r0_00;
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffa9b4,DAT_ffffbcf8);
    fVar2 = rx8_min_float(fVar2,DAT_ffffc028);
    if (DAT_ffffa914 == '\x01') {
      fVar3 = 13.5;
    }
    else {
      fVar3 = 100.0;
    }
    DAT_ffffa9bc = rx8_min_float(fVar2,fVar3);
    uVar1 = extraout_r0_01;
  }
  DAT_ffffa9c0 = DAT_ffffa9bc - DAT_ffffa9d4;
  DAT_ffffa9d4 = DAT_ffffa9d0;
  DAT_ffffa9d0 = DAT_ffffa9bc;
  return uVar1;
}


