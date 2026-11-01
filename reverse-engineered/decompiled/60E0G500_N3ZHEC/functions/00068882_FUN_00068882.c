/* ROM address: 0x00068882; body bytes: 66; decompiled */

uint FUN_00068882(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffde1d;
  if (uVar1 == 6) {
    uVar1 = FUN_00069110();
    return uVar1;
  }
  if (uVar1 == 10) {
    uVar1 = FUN_0006913a();
    return uVar1;
  }
  if (uVar1 == 0) {
    uVar1 = (uint)DAT_ffffde27;
    if (uVar1 == 0) {
      uVar1 = FUN_000690ce();
      return uVar1;
    }
    if (uVar1 == 3) {
      uVar1 = FUN_000691e8();
      return uVar1;
    }
  }
  return uVar1;
}


