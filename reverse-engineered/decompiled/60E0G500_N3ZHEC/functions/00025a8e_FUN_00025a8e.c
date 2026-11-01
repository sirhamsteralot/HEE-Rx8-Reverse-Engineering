/* ROM address: 0x00025a8e; body bytes: 132; decompiled */

undefined4 * FUN_00025a8e(void)

{
  char cVar1;
  undefined4 *extraout_r0;
  undefined4 *puVar2;
  float arg3;
  
  cVar1 = DAT_ffffa428;
  arg3 = 1e-05;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffb5c0 = DAT_ffffb5b8;
  }
  else {
    DAT_ffffb5c0 = rx8_first_order_filter(DAT_ffffb5b8,DAT_ffffb5c0,0.125,1e-05);
  }
  DAT_ffffb5bc = ((DAT_ffffb5b8 + DAT_ffffb5bc) - DAT_ffffb5d0) * 0.5;
  DAT_ffffb5d0 = DAT_ffffb5b8;
  if ((cVar1 == '\0') || (DAT_ffffa7bc + 200.0 <= DAT_ffffb5b8)) {
    puVar2 = &DAT_00025b78;
    DAT_ffffb5c4 = DAT_ffffb5b8;
  }
  else {
    DAT_ffffb5c4 = rx8_first_order_filter(DAT_ffffb5b8,DAT_ffffb5c4,0.031,arg3);
    puVar2 = extraout_r0;
  }
  return puVar2;
}


