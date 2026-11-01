/* ROM address: 0x00026200; body bytes: 30; decompiled */

void FUN_00026200(void)

{
  DAT_ffffb604 = rx8_first_order_filter(DAT_ffffb600,DAT_ffffb604,0.5,1e-05);
  return;
}


