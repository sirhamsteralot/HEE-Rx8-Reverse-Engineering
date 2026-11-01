/* ROM address: 0x00058f34; body bytes: 92; decompiled */

uint FUN_00058f34(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_ffffd270;
  bVar1 = DAT_ffffd26f;
  FUN_00058f22();
  if (DAT_ffffd201 == '\x01') {
    uVar3 = FUN_00058f96();
    return uVar3;
  }
  uVar3 = (uint)(char)bVar1;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd26f, uVar3 != 1)) &&
     ((bVar2 != 0 || (uVar3 = (uint)DAT_ffffd270, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00058fd0();
  return uVar3;
}


