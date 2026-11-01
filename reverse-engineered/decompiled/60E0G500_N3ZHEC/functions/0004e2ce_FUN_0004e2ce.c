/* ROM address: 0x0004e2ce; body bytes: 324; decompiled */

undefined4 * FUN_0004e2ce(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0007cc78;
  if (((DAT_ffffcf75 == '\0') && (puVar1 = (undefined4 *)&DAT_ffffcf76, DAT_ffffcf76 == '\0')) ||
     (300.0 <= DAT_ffffc008)) {
    DAT_ffffcf71 = '\0';
  }
  else if (DAT_ffffc008 < 300.0) {
    DAT_ffffcf71 = '\x01';
  }
  if ((((DAT_ffffcf77 == '\0') &&
       (puVar1 = (undefined4 *)(int)DAT_ffffcf78, puVar1 == (undefined4 *)0x0)) &&
      (puVar1 = (undefined4 *)&DAT_ffffcf71, DAT_ffffcf71 == '\0')) || (300.0 <= DAT_ffffc008)) {
    DAT_ffffcf72 = '\0';
  }
  else if (DAT_ffffc008 < 300.0) {
    DAT_ffffcf72 = '\x01';
  }
  if ((((DAT_ffffcf79 == '\0') &&
       (puVar1 = (undefined4 *)(int)DAT_ffffcf7a, puVar1 == (undefined4 *)0x0)) &&
      ((puVar1 = (undefined4 *)&DAT_ffffcf72, DAT_ffffcf72 == '\0' && (DAT_ffffcf71 == '\0')))) ||
     (300.0 <= DAT_ffffc008)) {
    DAT_ffffcf73 = '\0';
  }
  else if (DAT_ffffc008 < 300.0) {
    DAT_ffffcf73 = '\x01';
  }
  if (((((DAT_ffffcf7b == '\0') &&
        (puVar1 = (undefined4 *)(int)DAT_ffffcf7c, puVar1 == (undefined4 *)0x0)) &&
       (puVar1 = (undefined4 *)&DAT_ffffcf73, DAT_ffffcf73 == '\0')) &&
      ((DAT_ffffcf72 == '\0' && (DAT_ffffcf71 == '\0')))) || (300.0 <= DAT_ffffc008)) {
    DAT_ffffcf74 = 0;
  }
  else if (DAT_ffffc008 < 300.0) {
    DAT_ffffcf74 = 1;
  }
  return puVar1;
}


