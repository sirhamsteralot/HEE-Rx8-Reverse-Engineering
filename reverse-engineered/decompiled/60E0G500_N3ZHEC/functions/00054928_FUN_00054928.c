/* ROM address: 0x00054928; body bytes: 64; decompiled */

uint FUN_00054928(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd201;
  if (uVar1 == 1) {
    uVar1 = FUN_00055410();
  }
  else if ((DAT_ffffd1ed == '\0') && (uVar1 = (uint)DAT_ffffd1ec, uVar1 == 1)) {
    uVar1 = FUN_0005538c();
  }
  DAT_ffffd1ed = DAT_ffffd1ec;
  return uVar1;
}


