/* ROM address: 0x00058b4a; body bytes: 88; decompiled */

uint FUN_00058b4a(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffd26d;
  FUN_00058b38();
  uVar2 = (uint)DAT_ffffd201;
  if (uVar2 == 1) {
    FUN_00058ba8();
    FUN_00058c4c();
    FUN_00058cba();
    uVar2 = FUN_00058d66();
    return uVar2;
  }
  if ((bVar1 == 0) && (uVar2 = (uint)DAT_ffffd26d, uVar2 == 1)) {
    FUN_00058be4();
    FUN_00058c52();
    FUN_00058cc0();
    uVar2 = FUN_00058d6c();
    return uVar2;
  }
  return uVar2;
}


