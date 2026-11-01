/* ROM address: 0x0002de74; body bytes: 86; decompiled */

undefined1 * FUN_0002de74(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff868c,0);
  if ((((cVar2 == '\0') || (DAT_ffffaae0 == '\0')) || (DAT_ffffbdc8 == '\x01')) ||
     ((puVar1 = (undefined1 *)(uint)DAT_ffffbdb5, puVar1 == (undefined1 *)0x1 &&
      (DAT_ffffc008 < 22.5)))) {
    puVar1 = &DAT_ffffbd55;
    DAT_ffffbd55 = 1;
  }
  else {
    DAT_ffffbd55 = 0;
  }
  return puVar1;
}


