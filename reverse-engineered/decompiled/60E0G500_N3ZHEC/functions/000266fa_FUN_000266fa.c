/* ROM address: 0x000266fa; body bytes: 110; decompiled */

uint FUN_000266fa(void)

{
  uint uVar1;
  
  if (DAT_ffffbc1c < 20.0) {
    if (DAT_ffffbc1c < 16.0) {
      DAT_ffffb6b9 = 1;
    }
  }
  else {
    DAT_ffffb6b9 = 0;
  }
  uVar1 = (uint)DAT_ffffaada;
  if ((((uVar1 != 1) || (uVar1 = (uint)DAT_ffffb6b9, uVar1 != 1)) || (DAT_ffffb6c8 < 10.0)) ||
     (uVar1 = (uint)DAT_ffffb67c, uVar1 != 0)) {
    DAT_ffffb684 = 0;
  }
  else {
    DAT_ffffb684 = 1;
  }
  return uVar1;
}


