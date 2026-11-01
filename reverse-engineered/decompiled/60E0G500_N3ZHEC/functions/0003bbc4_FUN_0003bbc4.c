/* ROM address: 0x0003bbc4; body bytes: 324; decompiled */

char FUN_0003bbc4(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5e2 = 0;
    DAT_ffffc5e3 = 0;
    DAT_ffffc5e8 = 0;
    DAT_ffffc5e9 = 0;
    DAT_ffffc5ea = '\0';
    DAT_ffffc5eb = '\0';
    cVar2 = '\x01';
  }
  else {
    iVar4 = (int)(char)DAT_ffffc5e2;
    iVar3 = (int)(char)DAT_ffffc5e3;
    if (DAT_ffffd1e9 == '\x01') {
      iVar4 = 0;
      iVar3 = 0;
    }
    uVar1 = DAT_fffff754;
    if ((uVar1 & 0x10) == 0) {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x10) == 0) {
        iVar3 = 0;
        DAT_ffffc5eb = '\x01';
      }
      else if (DAT_ffffd1e9 == '\0') {
        iVar3 = FUN_00002478(iVar3,1);
      }
    }
    else {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x10) == 0) {
        if (DAT_ffffd1e9 == '\0') {
          iVar4 = FUN_00002478(iVar4,1);
        }
      }
      else {
        iVar4 = 0;
        DAT_ffffc5ea = '\x01';
      }
    }
    DAT_ffffc5e2 = (byte)iVar4;
    DAT_ffffc5e3 = (byte)iVar3;
    if (0x1f < DAT_ffffc5e2) {
      DAT_ffffc5ea = '\0';
    }
    if (0x1f < DAT_ffffc5e3) {
      DAT_ffffc5eb = '\0';
    }
    if ((DAT_ffffc5e2 < 0x20) && (DAT_ffffc5e3 < 0x20)) {
      cVar2 = DAT_ffffc5ea;
      if ((DAT_ffffc5ea == '\x01') && (cVar2 = DAT_ffffc5eb, DAT_ffffc5eb == '\x01')) {
        cVar2 = FUN_000671a4(0x39);
        if (cVar2 == '\0') {
          DAT_ffffc5e9 = 1;
          DAT_ffffc5e8 = 0;
        }
      }
    }
    else {
      cVar2 = FUN_000671a4(0x39);
      if (cVar2 == '\0') {
        DAT_ffffc5e8 = 1;
        DAT_ffffc5e9 = 0;
      }
    }
  }
  return cVar2;
}


