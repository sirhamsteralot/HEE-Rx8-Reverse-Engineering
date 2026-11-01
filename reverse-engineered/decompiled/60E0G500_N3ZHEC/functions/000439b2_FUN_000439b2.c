/* ROM address: 0x000439b2; body bytes: 102; decompiled */

undefined4 * FUN_000439b2(void)

{
  undefined4 *puVar1;
  
  if (((DAT_ffffb5a4 != '\x01') || (puVar1 = (undefined4 *)0x1, DAT_ffffb5aa != '\0')) &&
     ((puVar1 = &DAT_ffffc008, DAT_ffffc008 <= 15.0 ||
      ((DAT_ffffcab0 == '\0' || (puVar1 = (undefined4 *)&DAT_ffffad90, DAT_ffffad90 != '\0')))))) {
    if ((DAT_ffffb5a4 != '\0') ||
       (puVar1 = (undefined4 *)(uint)DAT_ffffcabc, puVar1 != (undefined4 *)0x1)) {
      DAT_ffffcab7 = 0;
      return puVar1;
    }
    puVar1 = (undefined4 *)0x1;
  }
  DAT_ffffcab7 = 1;
  return puVar1;
}


