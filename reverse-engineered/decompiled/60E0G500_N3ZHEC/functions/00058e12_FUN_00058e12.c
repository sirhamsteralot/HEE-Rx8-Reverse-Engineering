/* ROM address: 0x00058e12; body bytes: 64; decompiled */

uint FUN_00058e12(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffd26e;
  FUN_00058e00();
  uVar2 = (uint)DAT_ffffd201;
  if (uVar2 == 1) {
    uVar2 = FUN_00058e9e();
    return uVar2;
  }
  if ((bVar1 == 0) && (uVar2 = (uint)DAT_ffffd26e, uVar2 == 1)) {
    uVar2 = FUN_00058ea4();
    return uVar2;
  }
  return uVar2;
}


