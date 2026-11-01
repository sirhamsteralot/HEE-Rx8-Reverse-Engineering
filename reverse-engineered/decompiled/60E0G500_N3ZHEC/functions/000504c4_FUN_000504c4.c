/* ROM address: 0x000504c4; body bytes: 298; decompiled */

char FUN_000504c4(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  
  cVar5 = DAT_ffffd201;
  cVar4 = FUN_00011f34();
  if (cVar5 == '\x01') {
    DAT_ffffd076 = 0;
    DAT_ffffd074 = 0;
    bVar1 = false;
    DAT_ffffd075 = 0;
  }
  else {
    if ((DAT_ffffd0bc == '\0') && (cVar4 == '\x01')) {
      DAT_ffffd076 = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffd076 = 0;
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_ffffd182 != '\x01') {
        DAT_ffffd075 = 1;
        DAT_ffffd074 = 0;
        bVar1 = false;
        goto LAB_00050578;
      }
      DAT_ffffd074 = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffd074 = 0;
      bVar1 = false;
    }
    DAT_ffffd075 = 0;
  }
LAB_00050578:
  if ((DAT_ffffd0c6 == '\x01') && (DAT_ffffd2a2 == '\0')) {
    DAT_ffffd077 = 1;
    bVar3 = true;
  }
  else {
    DAT_ffffd077 = 0;
    bVar3 = false;
  }
  if ((DAT_ffffd0c7 == '\x01') && (DAT_ffffd2ab == '\0')) {
    DAT_ffffd078 = '\x01';
  }
  else {
    DAT_ffffd078 = '\0';
  }
  if ((cVar5 == '\x01') || (DAT_ffffd078 == '\x01')) {
    DAT_ffffd079 = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffd079 = 0;
    bVar2 = false;
  }
  if ((bVar2) || (bVar3)) {
    DAT_ffffd07a = 1;
  }
  else {
    DAT_ffffd07a = 0;
  }
  cVar5 = '\x01';
  if ((bVar1) || (cVar5 = DAT_ffffd078, DAT_ffffd078 == '\x01')) {
    DAT_ffffd07b = 1;
  }
  else {
    DAT_ffffd07b = 0;
  }
  DAT_ffffd0bc = cVar4;
  DAT_ffffd0c6 = DAT_ffffd2a2;
  DAT_ffffd0c7 = DAT_ffffd2ab;
  return cVar5;
}


