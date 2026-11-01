/* ROM address: 0x00054c68; body bytes: 154; decompiled */

char FUN_00054c68(void)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  byte local_24;
  byte local_23;
  
  bVar1 = false;
  uVar4 = 0x80;
  sVar3 = 0;
  do {
    cVar2 = FUN_00038ed8(uVar4,&local_24,2);
    if (cVar2 == '\x01') {
      bVar1 = true;
    }
    uVar4 = uVar4 + 2;
    sVar3 = sVar3 + (ushort)local_24 * 0x100 + (ushort)local_23;
  } while ((uVar4 & 0xffff) < 0x100);
  if (!bVar1) {
    if ((sVar3 == 0) || (cVar2 = DAT_ffffd1f1, DAT_ffffd1f1 == '\x01')) {
      DAT_ffffd1f4 = 0;
    }
    else {
      DAT_ffffd1f4 = 1;
    }
  }
  return cVar2;
}


