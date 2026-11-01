/* ROM address: 0x0003b884; body bytes: 322; decompiled */

char FUN_0003b884(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5da = 0;
    DAT_ffffc5db = 0;
    DAT_ffffc5dc = '\0';
    DAT_ffffc5dd = '\0';
    DAT_ffffc5de = 0;
    DAT_ffffc5d8 = 0;
    DAT_ffffc5d9 = 0;
    cVar3 = '\x01';
  }
  else {
    uVar5 = (uint)DAT_ffffc5d8;
    uVar4 = (uint)DAT_ffffc5d9;
    uVar2 = DAT_fffff72c;
    bVar1 = (uVar2 & 1) == 0;
    if (DAT_ffffd1e9 == '\x01') {
      uVar5 = 0;
      uVar4 = 0;
    }
    if (DAT_ffffc230 == '\0') {
      if (bVar1) {
        cVar3 = FUN_000671a4(7);
        if (cVar3 == '\0') {
          DAT_ffffc5dc = '\x01';
          uVar5 = 0;
        }
      }
      else if (DAT_ffffd1e9 == '\0') {
        if ((0x1f < (uVar5 & 0xff)) && (cVar3 = FUN_000671a4(7), cVar3 == '\0')) {
          DAT_ffffc5da = 1;
          DAT_ffffc5dc = '\0';
          DAT_ffffc5de = 0;
        }
        uVar5 = FUN_00002478(uVar5,1);
      }
    }
    else if (bVar1) {
      if (DAT_ffffd1e9 == '\0') {
        if ((0x1f < (uVar4 & 0xff)) && (cVar3 = FUN_000671a4(8), cVar3 == '\0')) {
          DAT_ffffc5db = 1;
          DAT_ffffc5dd = '\0';
          DAT_ffffc5de = 0;
        }
        uVar4 = FUN_00002478(uVar4,1);
      }
    }
    else {
      cVar3 = FUN_000671a4(8);
      if (cVar3 == '\0') {
        DAT_ffffc5dd = '\x01';
        uVar4 = 0;
      }
    }
    DAT_ffffc5d8 = (char)uVar5;
    DAT_ffffc5d9 = (char)uVar4;
    cVar3 = DAT_ffffc5dc;
    if ((DAT_ffffc5dc == '\x01') && (cVar3 = DAT_ffffc5dd, DAT_ffffc5dd == '\x01')) {
      DAT_ffffc5de = 1;
      DAT_ffffc5da = 0;
      DAT_ffffc5db = 0;
    }
  }
  return cVar3;
}


