/* ROM address: 0x0002e17a; body bytes: 62; decompiled */

undefined1 FUN_0002e17a(void)

{
  undefined1 uVar1;
  
  if (DAT_ffffbd58 == '\0') {
    uVar1 = 0;
    DAT_ffffbd59 = 0;
  }
  else if ((DAT_ffffc01c == '\x01') || (DAT_ffffc01d == '\x01')) {
    uVar1 = 1;
    DAT_ffffbd59 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


