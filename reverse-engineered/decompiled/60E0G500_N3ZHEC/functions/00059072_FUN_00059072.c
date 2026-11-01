/* ROM address: 0x00059072; body bytes: 92; decompiled */

uint FUN_00059072(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_ffffd272;
  bVar1 = DAT_ffffd271;
  FUN_00059060();
  if (DAT_ffffd201 == '\x01') {
    uVar3 = FUN_000590d4();
    return uVar3;
  }
  uVar3 = (uint)(char)bVar1;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd271, uVar3 != 1)) &&
     ((bVar2 != 0 || (uVar3 = (uint)DAT_ffffd272, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00059118();
  return uVar3;
}


