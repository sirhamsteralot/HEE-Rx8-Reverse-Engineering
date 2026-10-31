/* ROM address: 0x00006c4c; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006c4c (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00006c4c(void)

{
  uint uVar1;
  
  if (DAT_ffff9f2e == 0) {
    return 0;
  }
  uVar1 = (uint)DAT_ffff9f2e;
  if (uVar1 == 0xc) {
    DAT_ffff9f12 = ADDR23H_B;
    DAT_ffff9f10 = ADDR22H_B;
    DAT_ffff9f0e = ADDR21H_B;
    DAT_ffff9f0c = ADDR20H_B;
LAB_00006ca0:
    DAT_ffff9f0a = ADDR19H_B;
    DAT_ffff9f08 = ADDR18H_B;
    DAT_ffff9f06 = ADDR17H_B;
    DAT_ffff9f04 = ADDR16H_B;
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
  DAT_ffff9f02 = ADDR15H_B;
  DAT_ffff9f00 = ADDR14H_B;
  DAT_ffff9efe = ADDR13H_B;
LAB_00006cd2:
  DAT_ffff9efc = ADDR12H_B;
  DAT_ffff9f2d = 0;
  DAT_ffff9f2c = 0;
  return (int)DAT_ffff9efc;
}


