/* ROM address: 0x00065ae8; body bytes: 122; decompiled */

uint FUN_00065ae8(ushort *param_1)

{
  char cVar1;
  byte bVar3;
  uint uVar2;
  undefined1 auStack_18 [20];
  
  cVar1 = (&DAT_ffff8d7c)[(uint)*param_1 * 2];
  bVar3 = FUN_00065d40((int)*(char *)(param_1 + 3));
  if ((cVar1 == ' ') && ((bVar3 == 0x60 || (bVar3 == 0x70)))) {
    uVar2 = FUN_00067fca((int)(short)*param_1,auStack_18);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = FUN_00067ed6(auStack_18);
    }
  }
  else {
    uVar2 = (uint)bVar3;
    if ((uVar2 == 0) || ((uVar2 == 0x50 || (uVar2 == 0xc1)))) {
      uVar2 = FUN_00067f04();
    }
  }
  return uVar2;
}


