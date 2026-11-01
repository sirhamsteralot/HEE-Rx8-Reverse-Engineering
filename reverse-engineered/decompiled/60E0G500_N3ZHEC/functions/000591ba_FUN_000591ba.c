/* ROM address: 0x000591ba; body bytes: 92; decompiled */

uint FUN_000591ba(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_ffffd274;
  bVar1 = DAT_ffffd273;
  FUN_000591a8();
  if (DAT_ffffd201 == '\x01') {
    uVar3 = FUN_0005921c();
    return uVar3;
  }
  uVar3 = (uint)(char)bVar1;
  if (((uVar3 != 0) || (uVar3 = (uint)DAT_ffffd273, uVar3 != 1)) &&
     ((bVar2 != 0 || (uVar3 = (uint)DAT_ffffd274, uVar3 != 1)))) {
    return uVar3;
  }
  uVar3 = FUN_00059260();
  return uVar3;
}


