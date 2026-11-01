/* ROM address: 0x000589b2; body bytes: 72; decompiled */

uint FUN_000589b2(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffd26c;
  FUN_000589a0();
  uVar2 = (uint)DAT_ffffd201;
  if (uVar2 == 1) {
    FUN_00058a00();
    uVar2 = FUN_00058a84();
    return uVar2;
  }
  if ((bVar1 == 0) && (uVar2 = (uint)DAT_ffffd26c, uVar2 == 1)) {
    FUN_00058a06();
    uVar2 = FUN_00058ac0();
    return uVar2;
  }
  return uVar2;
}


