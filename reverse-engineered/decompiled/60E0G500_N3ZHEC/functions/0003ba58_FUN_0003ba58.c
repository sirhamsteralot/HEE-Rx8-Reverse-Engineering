/* ROM address: 0x0003ba58; body bytes: 328; decompiled */

char FUN_0003ba58(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5e0 = 0;
    DAT_ffffc5e1 = 0;
    DAT_ffffc5e4 = 0;
    DAT_ffffc5e5 = 0;
    DAT_ffffc5e6 = '\0';
    DAT_ffffc5e7 = '\0';
    cVar2 = '\x01';
  }
  else {
    iVar4 = (int)(char)DAT_ffffc5e0;
    iVar3 = (int)(char)DAT_ffffc5e1;
    if (DAT_ffffd1e9 == '\x01') {
      iVar4 = 0;
      iVar3 = 0;
    }
    uVar1 = DAT_fffff754;
    if ((uVar1 & 0x800) == 0) {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x20) == 0) {
        iVar3 = 0;
        DAT_ffffc5e7 = '\x01';
      }
      else if (DAT_ffffd1e9 == '\0') {
        iVar3 = FUN_00002478(iVar3,1);
      }
    }
    else {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x20) == 0) {
        if (DAT_ffffd1e9 == '\0') {
          iVar4 = FUN_00002478(iVar4,1);
        }
      }
      else {
        iVar4 = 0;
        DAT_ffffc5e6 = '\x01';
      }
    }
    DAT_ffffc5e0 = (byte)iVar4;
    DAT_ffffc5e1 = (byte)iVar3;
    if (0x1f < DAT_ffffc5e0) {
      DAT_ffffc5e6 = '\0';
    }
    if (0x1f < DAT_ffffc5e1) {
      DAT_ffffc5e7 = '\0';
    }
    if ((DAT_ffffc5e0 < 0x20) && (DAT_ffffc5e1 < 0x20)) {
      cVar2 = DAT_ffffc5e6;
      if ((DAT_ffffc5e6 == '\x01') && (cVar2 = DAT_ffffc5e7, DAT_ffffc5e7 == '\x01')) {
        cVar2 = FUN_000671a4(0x38);
        if (cVar2 == '\0') {
          DAT_ffffc5e5 = 1;
          DAT_ffffc5e4 = 0;
        }
      }
    }
    else {
      cVar2 = FUN_000671a4(0x38);
      if (cVar2 == '\0') {
        DAT_ffffc5e4 = 1;
        DAT_ffffc5e5 = 0;
      }
    }
  }
  return cVar2;
}


