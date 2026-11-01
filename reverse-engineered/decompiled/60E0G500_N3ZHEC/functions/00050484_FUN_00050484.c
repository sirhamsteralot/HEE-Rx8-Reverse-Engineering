/* ROM address: 0x00050484; body bytes: 64; decompiled */

uint FUN_00050484(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd07c;
  if ((((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfe6, 0x4e < uVar1)) &&
      (uVar1 = (uint)DAT_ffffd0bb, uVar1 != 0)) && (DAT_ffffd034 == '\0')) {
    DAT_ffffd083 = 1;
  }
  else {
    DAT_ffffd083 = 0;
  }
  DAT_ffffd0bb = DAT_ffffd034;
  return uVar1;
}


