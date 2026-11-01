/* ROM address: 0x00018ea4; body bytes: 84; decompiled */

undefined4 * FUN_00018ea4(void)

{
  undefined4 *puVar1;
  
  if (((0.00390625 <= DAT_ffffa9cc) && (puVar1 = &DAT_00018f60, DAT_ffffa9b8 < 0.00390625)) ||
     ((puVar1 = &DAT_00018f60, DAT_ffffa9bc == 0 &&
      ((puVar1 = (undefined4 *)0x0, DAT_ffffa9d0 != 0 &&
       (puVar1 = (undefined4 *)(int)DAT_ffffa9be, puVar1 == (undefined4 *)0x0)))))) {
    DAT_ffffa9be = 0x1f;
  }
  else if (DAT_ffffa9be != 0) {
    DAT_ffffa9be = DAT_ffffa9be + -1;
  }
  DAT_ffffa9cc = DAT_ffffa9b8;
  return puVar1;
}


