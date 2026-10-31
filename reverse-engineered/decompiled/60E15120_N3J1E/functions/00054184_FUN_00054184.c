/* ROM address: 0x00054184; body bytes: 64; decompiled */

uint FUN_00054184(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd1c5;
  if (uVar1 == 1) {
    uVar1 = FUN_00054c6c();
  }
  else if ((DAT_ffffd1b1 == '\0') && (uVar1 = (uint)DAT_ffffd1b0, uVar1 == 1)) {
    uVar1 = FUN_00054be8();
  }
  DAT_ffffd1b1 = DAT_ffffd1b0;
  return uVar1;
}


