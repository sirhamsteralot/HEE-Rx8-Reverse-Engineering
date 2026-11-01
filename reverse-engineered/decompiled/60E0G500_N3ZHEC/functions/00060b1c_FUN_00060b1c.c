/* ROM address: 0x00060b1c; body bytes: 58; decompiled */

uint FUN_00060b1c(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (DAT_ffffd1e9 == '\x01') {
    uVar1 = 3;
  }
  if ((DAT_ffff9ec8 & 1) == 0) {
    uVar1 = uVar1 | 4;
  }
  if (DAT_ffffd1d4 == '\x01') {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}


