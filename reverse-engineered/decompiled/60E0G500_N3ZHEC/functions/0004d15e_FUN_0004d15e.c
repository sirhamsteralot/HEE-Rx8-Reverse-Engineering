/* ROM address: 0x0004d15e; body bytes: 146; decompiled */

undefined1 * FUN_0004d15e(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffc021 == '\x01') {
    DAT_ffffcfa2 = '\f';
  }
  else if (DAT_ffffcfa2 != '\0') {
    DAT_ffffcfa2 = DAT_ffffcfa2 + -1;
  }
  puVar1 = (undefined1 *)(uint)DAT_ffffbd59;
  if ((((((puVar1 == (undefined1 *)0x1) && (DAT_ffffc021 == '\0')) && (DAT_ffffc01d == '\0')) &&
       ((puVar1 = &DAT_ffffc022, DAT_ffffc022 == '\0' && (DAT_ffffcf81 == '\0')))) &&
      ((DAT_ffffcf82 == '\0' && ((DAT_ffffcf7e == '\0' && (DAT_ffffcf7f == '\0')))))) &&
     (DAT_ffffcfa2 == '\0')) {
    puVar1 = (undefined1 *)0x1;
    DAT_ffffcf80 = 1;
  }
  else {
    DAT_ffffcf80 = 0;
  }
  return puVar1;
}


