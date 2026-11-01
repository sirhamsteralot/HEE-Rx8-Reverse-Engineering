/* ROM address: 0x0003fb34; body bytes: 80; decompiled */

bool FUN_0003fb34(void)

{
  uint uVar1;
  
  uVar1 = FUN_000070ac(0);
  DAT_ffffc720 = (uVar1 & 1) == 0;
  uVar1 = FUN_000070ac(0);
  DAT_ffffc721 = (uVar1 & 2) == 0;
  return (bool)DAT_ffffc721;
}


