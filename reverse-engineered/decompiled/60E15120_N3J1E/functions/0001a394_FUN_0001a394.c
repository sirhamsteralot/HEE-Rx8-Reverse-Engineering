/* ROM address: 0x0001a394; body bytes: 66; decompiled */

undefined4 FUN_0001a394(void)

{
  undefined4 extraout_r0;
  
  DAT_ffffaa40 = rx8_first_order_filter(inferred_throttle_position_ffffad44,DAT_ffffaa40,0.5,1e-05);
  if (DAT_ffffaa5c != '\0') {
    DAT_ffffaa5c = DAT_ffffaa5c + -1;
  }
  if (DAT_ffffaa5d != '\0') {
    DAT_ffffaa5d = DAT_ffffaa5d + -1;
  }
  return extraout_r0;
}


