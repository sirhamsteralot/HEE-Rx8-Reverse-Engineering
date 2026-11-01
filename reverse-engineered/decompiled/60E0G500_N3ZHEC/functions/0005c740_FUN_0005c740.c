/* ROM address: 0x0005c740; body bytes: 98; decompiled */

uint FUN_0005c740(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa41c;
  if (uVar1 == 1) {
    if ((DAT_ffffd3a8 & 0x60) == 0) {
      if (DAT_ffffd350 == 0x17e0) {
        DAT_ffffd355 = 2;
      }
      DAT_ffffd357 = 0;
    }
    uVar1 = 0x198;
    if ((DAT_ffffd3a8 & 0x60) == 0) {
      if (DAT_ffffd350 == 0x17df) {
        DAT_ffffd355 = 2;
      }
      uVar1 = 0x19c;
      DAT_ffffd370 = 0;
    }
  }
  return uVar1;
}


