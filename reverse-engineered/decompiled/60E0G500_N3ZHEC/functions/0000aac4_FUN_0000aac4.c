/* ROM address: 0x0000aac4; body bytes: 126; decompiled */

void FUN_0000aac4(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((DAT_ffffa1c8 == '\x01') || (DAT_ffffa1c9 == '\x01')) {
    uVar1 = DAT_fffff72c;
    uVar2 = DAT_fffff72c;
    if ((uVar1 & 0x1000) == 0) {
      iVar3 = 2;
    }
    if ((uVar2 & 0x2000) == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  else {
    iVar3 = 3;
  }
  if (iVar3 == 0) {
    DAT_ffffa1bc = 0;
  }
  else if (iVar3 == 1) {
    DAT_ffffa1bc = 2;
  }
  else if (iVar3 == 2) {
    DAT_ffffa1bc = 1;
  }
  else if (iVar3 == 3) {
    DAT_ffffa1bc = 3;
  }
  FUN_0000a16e(0);
  return;
}


