/* ROM address: 0x0004bca4; body bytes: 50; decompiled */

uint FUN_0004bca4(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffa41c == '\x01') ||
     ((uVar1 = (uint)DAT_ffffa42c, uVar1 == 1 && (uVar1 = (uint)DAT_ffffa428, uVar1 == 0)))) {
    DAT_ffffce5c = 0x80;
  }
  else {
    DAT_ffffce5c = 0;
  }
  return uVar1;
}


