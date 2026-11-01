/* ROM address: 0x000592f6; body bytes: 92; decompiled */

uint FUN_000592f6(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_ffffd276;
  bVar1 = DAT_ffffd275;
  FUN_000592e4();
  if (DAT_ffffd201 == '\x01') {
    uVar3 = FUN_00059358();
    return uVar3;
  }
  uVar3 = (uint)(char)bVar1;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd275, uVar3 != 1)) &&
     ((bVar2 != 0 || (uVar3 = (uint)DAT_ffffd276, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00059398();
  return uVar3;
}


