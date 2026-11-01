/* ROM address: 0x00006c4c; body bytes: 144; decompiled */

uint FUN_00006c4c(void)

{
  uint uVar1;
  
  if (DAT_ffff9f2e == 0) {
    return 0;
  }
  uVar1 = (uint)DAT_ffff9f2e;
  if (uVar1 == 0xc) {
    DAT_ffff9f12 = DAT_fffff836;
    DAT_ffff9f10 = DAT_fffff834;
    DAT_ffff9f0e = DAT_fffff832;
    DAT_ffff9f0c = DAT_fffff830;
LAB_00006ca0:
    DAT_ffff9f0a = DAT_fffff82e;
    DAT_ffff9f08 = DAT_fffff82c;
    DAT_ffff9f06 = DAT_fffff82a;
    DAT_ffff9f04 = DAT_fffff828;
  }
  else {
    if (uVar1 == 8) goto LAB_00006ca0;
    if (uVar1 != 4) {
      if (uVar1 != 1) {
        DAT_ffff9f2c = 0;
        DAT_ffff9f2d = 0;
        return uVar1;
      }
      goto LAB_00006cd2;
    }
  }
  DAT_ffff9f02 = DAT_fffff826;
  DAT_ffff9f00 = DAT_fffff824;
  DAT_ffff9efe = DAT_fffff822;
LAB_00006cd2:
  DAT_ffff9efc = DAT_fffff820;
  DAT_ffff9f2d = 0;
  DAT_ffff9f2c = 0;
  return (int)DAT_ffff9efc;
}


