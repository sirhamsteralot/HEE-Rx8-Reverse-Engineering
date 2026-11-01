/* ROM address: 0x00059564; body bytes: 150; decompiled */

uint FUN_00059564(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = DAT_ffffd27b;
  bVar3 = DAT_ffffd27a;
  cVar2 = DAT_ffffd279;
  cVar1 = DAT_ffffd278;
  FUN_00059542();
  if (DAT_ffffd201 == '\x01') {
    FUN_00059640();
    uVar5 = FUN_000596d4();
    return uVar5;
  }
  if (((cVar1 == '\0') && (DAT_ffffd278 == '\x01')) || ((cVar2 == '\0' && (DAT_ffffd279 == '\x01')))
     ) {
    FUN_00059646();
  }
  uVar5 = (uint)(char)bVar3;
  if (((uVar5 != 0) || (uVar5 = (uint)DAT_ffffd27a, uVar5 != 1)) &&
     ((bVar4 != 0 || (uVar5 = (uint)DAT_ffffd27b, uVar5 != 1)))) {
    return uVar5;
  }
  uVar5 = FUN_00059714();
  return uVar5;
}


