/* ROM address: 0x0003e72e; body bytes: 318; decompiled */

char FUN_0003e72e(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc6a0 = 0;
    DAT_ffffc6a1 = 0;
    DAT_ffffc6a2 = '\0';
    DAT_ffffc6a3 = '\0';
    DAT_ffffc6a4 = 0;
    DAT_ffffc69c = 0;
    DAT_ffffc69d = 0;
    cVar3 = '\x01';
  }
  else {
    uVar5 = (uint)DAT_ffffc69c;
    uVar4 = (uint)DAT_ffffc69d;
    uVar2 = DAT_fffff72c;
    bVar1 = (uVar2 & 0x400) == 0;
    if (DAT_ffffd1e9 == '\x01') {
      uVar5 = 0;
      uVar4 = 0;
    }
    if (DAT_ffffb320 == '\0') {
      if (bVar1) {
        cVar3 = FUN_000671a4(0x48);
        if (cVar3 == '\0') {
          DAT_ffffc6a2 = '\x01';
          uVar5 = 0;
        }
      }
      else if (DAT_ffffd1e9 == '\0') {
        if ((0x1f < (uVar5 & 0xff)) && (cVar3 = FUN_000671a4(0x48), cVar3 == '\0')) {
          DAT_ffffc6a0 = 1;
          DAT_ffffc6a2 = '\0';
          DAT_ffffc6a4 = 0;
        }
        uVar5 = FUN_00002478(uVar5,1);
      }
    }
    else if (bVar1) {
      if (DAT_ffffd1e9 == '\0') {
        if ((0x1f < (uVar4 & 0xff)) && (cVar3 = FUN_000671a4(0x49), cVar3 == '\0')) {
          DAT_ffffc6a1 = 1;
          DAT_ffffc6a3 = '\0';
          DAT_ffffc6a4 = 0;
        }
        uVar4 = FUN_00002478(uVar4,1);
      }
    }
    else {
      cVar3 = FUN_000671a4(0x49);
      if (cVar3 == '\0') {
        DAT_ffffc6a3 = '\x01';
        uVar4 = 0;
      }
    }
    DAT_ffffc69c = (char)uVar5;
    DAT_ffffc69d = (char)uVar4;
    cVar3 = DAT_ffffc6a2;
    if ((DAT_ffffc6a2 == '\x01') && (cVar3 = DAT_ffffc6a3, DAT_ffffc6a3 == '\x01')) {
      DAT_ffffc6a4 = 1;
      DAT_ffffc6a0 = 0;
      DAT_ffffc6a1 = 0;
    }
  }
  return cVar3;
}


