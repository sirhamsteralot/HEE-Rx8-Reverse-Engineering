/* ROM address: 0x000241a8; body bytes: 170; decompiled */

undefined4 FUN_000241a8(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  short sVar4;
  char cVar5;
  
  if (DAT_ffffa228 == '\0') {
    uVar1 = FUN_00002460((int)DAT_ffffb4a8,1);
    DAT_ffffb4a8 = (short)uVar1;
  }
  else {
    DAT_ffffb4a8 = 0;
    cVar5 = DAT_ffffa228 == '\x02';
    FUN_0000b958(&DAT_ffffb4e8,0x1c);
    DAT_ffffb4ad = DAT_ffffb4e8 != 0x5aa5;
    sVar4 = 0;
    if ((bool)DAT_ffffb4ad) {
      cVar5 = cVar5 + '\x01';
    }
    bVar3 = 0;
    iVar2 = 0;
    do {
      bVar3 = bVar3 + 1;
      sVar4 = sVar4 + *(short *)((int)&DAT_ffffb4e8 + iVar2);
      iVar2 = iVar2 + 2;
    } while (bVar3 < 0x1b);
    DAT_ffffb4ae = sVar4 != DAT_ffffb51e;
    if ((bool)DAT_ffffb4ae) {
      cVar5 = cVar5 + '\x01';
    }
    uVar1 = 0x36;
    if (cVar5 == '\0') {
      DAT_ffffb4aa = 0;
      uVar1 = FUN_0002431c();
      return uVar1;
    }
    DAT_ffffb4aa = 1;
  }
  return uVar1;
}


