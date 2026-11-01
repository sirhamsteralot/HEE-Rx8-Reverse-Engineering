/* ROM address: 0x00056ffa; body bytes: 58; decompiled */

uint FUN_00056ffa(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd228;
  if (uVar1 == 1) {
    uVar1 = diag22_find_and_dispatch_identifier();
    if (DAT_ffffd224 != -0x80) {
      DAT_ffffd224 = 0;
      DAT_ffffd228 = 0;
      DAT_ffffd226 = 0;
      uVar1 = FUN_000550ca(0x22,uVar1);
      return uVar1;
    }
  }
  return uVar1;
}


