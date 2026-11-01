/* ROM address: 0x00036f4c; body bytes: 262; decompiled */

uint FUN_00036f4c(void)

{
  uint uVar1;
  
  if (DAT_ffffc2d8 != 'Z') {
    DAT_ffffc2d8 = '\0';
  }
  if (DAT_ffffc2d8 == 'Z') {
    if ((DAT_ffffc2e5 & 0xfc) != 0) {
      DAT_ffffc2e5 = 0;
    }
    if (((DAT_ffffc243 & 0xf) != 0) && (DAT_ffffc243 = 0, DAT_ffffc2e4 == 1)) {
      DAT_ffffc243 = 0x40;
    }
    if (5 < DAT_ffffc2e6) {
      DAT_ffffc2e6 = 0;
    }
    uVar1 = (uint)(char)DAT_ffffc2e5;
    if (((uVar1 & 2) == 0) && (uVar1 = (uint)DAT_ffffc242, uVar1 == 0x55)) {
      DAT_ffffc242 = 0x33;
      DAT_ffffc2a4 = 0;
    }
    if (2 < DAT_ffffc2f2) {
      DAT_ffffc2f2 = 2;
    }
  }
  else {
    DAT_ffffc2e5 = 0;
    DAT_ffffc2e6 = 0;
    DAT_ffffc243 = 0;
    uVar1 = (uint)DAT_ffffc2e4;
    if (uVar1 == 1) {
      uVar1 = 0x40;
      DAT_ffffc243 = 0x40;
    }
    DAT_ffffc242 = 0x33;
    DAT_ffffc244 = 8;
    DAT_ffffc2e9 = '\0';
    DAT_ffffc2e8 = 0;
    DAT_ffffc2ee = 0;
    DAT_ffffc2ef = 0;
    DAT_ffffc2f0 = 0;
    DAT_ffffc2f1 = 0;
    DAT_ffffc2f2 = 2;
  }
  if ((DAT_ffffc244 < 8) || (0x3f < DAT_ffffc244)) {
    DAT_ffffc244 = 8;
  }
  if (DAT_ffffc2e9 != '\0') {
    DAT_ffffc2a9 = 1;
    DAT_ffffc2e9 = -0x38;
  }
  return uVar1;
}


