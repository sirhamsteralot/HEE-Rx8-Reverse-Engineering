/* ROM address: 0x000238ca; body bytes: 58; decompiled */

undefined4 FUN_000238ca(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffb400 = rx8_first_order_filter(DAT_ffffb3fc,DAT_ffffb400,0.25,1e-05);
  uVar1 = extraout_r0;
  if (DAT_ffffb3fc <= 2.0) {
    uVar1 = 1;
  }
  DAT_ffffb404 = DAT_ffffb3fc <= 2.0;
  return uVar1;
}


