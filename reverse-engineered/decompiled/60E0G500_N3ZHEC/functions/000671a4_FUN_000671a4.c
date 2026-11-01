/* ROM address: 0x000671a4; body bytes: 70; decompiled */

bool FUN_000671a4(uint param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (param_1 & 0xffff) * 4;
  bVar3 = (*(uint *)(&DAT_0007e4dc + iVar2) & DAT_ffffd96c & 0xffff) != 0;
  if ((!bVar3) &&
     (uVar1 = FUN_000671fc(), (*(uint *)(&DAT_0007e4dc + iVar2) & uVar1 & 0xffff0000) != 0)) {
    bVar3 = true;
  }
  return bVar3;
}


