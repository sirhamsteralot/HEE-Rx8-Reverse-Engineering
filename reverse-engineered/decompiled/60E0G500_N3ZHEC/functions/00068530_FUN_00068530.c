/* ROM address: 0x00068530; body bytes: 44; decompiled */

void FUN_00068530(byte param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x46c;
  if (*(ushort *)(&DAT_ffffd99c + iVar2) < 0x464) {
    sVar1 = *(short *)(&DAT_ffffd99c + iVar2) + 1;
  }
  else {
    sVar1 = 0;
  }
  *(short *)(&DAT_ffffd998 + iVar2) = sVar1;
  return;
}


