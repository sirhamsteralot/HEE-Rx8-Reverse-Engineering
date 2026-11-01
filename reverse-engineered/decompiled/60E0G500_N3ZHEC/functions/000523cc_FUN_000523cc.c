/* ROM address: 0x000523cc; body bytes: 86; decompiled */

undefined1 * FUN_000523cc(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff86ec,0x17);
  puVar1 = (undefined1 *)0x0;
  if ((cVar2 == '\0') ||
     ((((DAT_ffffd12e == '\x01' && (DAT_ffffcfe6 == 0x88)) && (DAT_ffffd130 == '\0')) &&
      (puVar1 = &DAT_ffffd131, DAT_ffffd131 == '\0')))) {
    DAT_ffffd12f = 1;
  }
  else {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffd12f = 0;
  }
  return puVar1;
}


