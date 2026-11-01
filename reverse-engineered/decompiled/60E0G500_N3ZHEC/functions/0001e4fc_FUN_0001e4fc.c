/* ROM address: 0x0001e4fc; body bytes: 70; decompiled */

undefined4 FUN_0001e4fc(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffb0f0 = rx8_first_order_filter(DAT_ffffad98,DAT_ffffb0f0,0.25,1e-05);
  uVar1 = extraout_r0;
  if (DAT_ffffb0f0 < DAT_ffffb0e8) {
    if (DAT_ffffb0f0 < DAT_ffffb0e8 - 0.0) {
      uVar1 = 0;
      DAT_ffffb0ec = 0;
    }
  }
  else {
    DAT_ffffb0ec = 1;
  }
  return uVar1;
}


