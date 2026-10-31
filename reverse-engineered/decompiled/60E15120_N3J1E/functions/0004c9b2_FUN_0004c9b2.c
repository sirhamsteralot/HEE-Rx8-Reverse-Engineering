/* ROM address: 0x0004c9b2; body bytes: 146; decompiled */

undefined1 * FUN_0004c9b2(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffbfb9 == '\x01') {
    DAT_ffffcf66 = '\f';
  }
  else if (DAT_ffffcf66 != '\0') {
    DAT_ffffcf66 = DAT_ffffcf66 + -1;
  }
  puVar1 = (undefined1 *)(uint)DAT_ffffbced;
  if ((((((puVar1 == (undefined1 *)0x1) && (DAT_ffffbfb9 == '\0')) && (DAT_ffffbfb5 == '\0')) &&
       ((puVar1 = &DAT_ffffbfba, DAT_ffffbfba == '\0' && (DAT_ffffcf45 == '\0')))) &&
      ((DAT_ffffcf46 == '\0' && ((DAT_ffffcf42 == '\0' && (DAT_ffffcf43 == '\0')))))) &&
     (DAT_ffffcf66 == '\0')) {
    puVar1 = (undefined1 *)0x1;
    DAT_ffffcf44 = 1;
  }
  else {
    DAT_ffffcf44 = 0;
  }
  return puVar1;
}


