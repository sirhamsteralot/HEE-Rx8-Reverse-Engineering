/* ROM address: 0x00022d26; body bytes: 58; decompiled */

undefined4 FUN_00022d26(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffb390 = rx8_first_order_filter(DAT_ffffb38c,DAT_ffffb390,0.25,1e-05);
  uVar1 = extraout_r0;
  if (DAT_ffffb38c <= 2.0) {
    uVar1 = 1;
  }
  DAT_ffffb394 = DAT_ffffb38c <= 2.0;
  return uVar1;
}


