/* ROM address: 0x0004bfb4; body bytes: 66; decompiled */

undefined1 * FUN_0004bfb4(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_ffffc530;
  if (((DAT_ffffce8e == '\0') &&
      (puVar1 = (undefined1 *)(uint)DAT_ffffc530, puVar1 == (undefined1 *)0x1)) &&
     (DAT_ffffce8d == '\0')) {
    puVar1 = (undefined1 *)(int)DAT_ffffcd4c;
    if (((uint)puVar1 & 0x80) == 0) {
      DAT_ffffce80 = DAT_ffffc532;
    }
    else {
      puVar1 = (undefined1 *)0xf;
      DAT_ffffce80 = 0xf;
    }
    DAT_ffffce8d = '\x01';
  }
  DAT_ffffce8e = DAT_ffffc530;
  return puVar1;
}


