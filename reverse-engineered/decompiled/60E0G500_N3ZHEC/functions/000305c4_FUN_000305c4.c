/* ROM address: 0x000305c4; body bytes: 44; decompiled */

void FUN_000305c4(void)

{
  DAT_ffffbe2c = rx8_first_order_filter(DAT_ffffb5b8 * DAT_ffffbf1c * 0.12,DAT_ffffbe2c,0.75,1e-05);
  return;
}


