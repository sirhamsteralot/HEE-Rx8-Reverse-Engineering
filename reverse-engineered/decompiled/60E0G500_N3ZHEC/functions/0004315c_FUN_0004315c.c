/* ROM address: 0x0004315c; body bytes: 100; decompiled */

undefined1 * FUN_0004315c(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffa41c;
  if (((puVar1 == (undefined1 *)0x1) || (DAT_ffffae97 == '\0')) ||
     (puVar1 = &DAT_ffffaaf9, DAT_ffffaaf9 == '\0')) {
    DAT_ffffc9ac = 1.0;
    DAT_ffffc998 = 1.0;
  }
  else {
    DAT_ffffc9ac = ((DAT_ffffaae4 + DAT_ffffae64) - DAT_ffffae74) + DAT_ffffb140;
    DAT_ffffc998 = rx8_first_order_filter(DAT_ffffc9ac,DAT_ffffc998,0.03,1e-05);
    puVar1 = extraout_r0;
  }
  return puVar1;
}


