/* ROM address: 0x00013bd4; body bytes: 102; decompiled */

undefined4 FUN_00013bd4(float param_1)

{
  undefined4 extraout_r0;
  undefined **ppuVar1;
  float arg1;
  
  if (((DAT_ffffb5a4 == '\x01') && (4 < DAT_ffffbca9)) ||
     ((DAT_ffffb5a4 == '\0' && ((DAT_ffffbb55 < 6 && (DAT_ffffbb55 != 0)))))) {
    ppuVar1 = (undefined **)&DAT_0006b3e0;
  }
  else {
    ppuVar1 = &PTR_LAB_0006b3cc;
  }
  arg1 = (float)FUN_00002068(DAT_ffffb5b8,ppuVar1);
  rx8_clamp_float(param_1,arg1,0.0);
  return extraout_r0;
}


