/* ROM address: 0x0003b48c; body bytes: 354; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003b4d0) */

char FUN_0003b48c(void)

{
  ushort uVar1;
  char cVar2;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5cc = 0;
    DAT_ffffc5cd = 0;
    DAT_ffffc5cf = '\0';
    DAT_ffffc5d0 = '\0';
    DAT_ffffc5ce = 0;
    DAT_ffffc5c8 = 0;
    DAT_ffffc5c9 = 0;
    cVar2 = '\x01';
  }
  else {
    if (DAT_ffffbfd4 == '\0') {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x800) == 0) {
        cVar2 = FUN_000671a4(0x6f);
        if (cVar2 == '\0') {
          DAT_ffffc5cf = '\x01';
        }
        DAT_ffffc5c8 = 0;
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5c9 = 0;
        }
      }
      else {
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5c8 = 0;
          DAT_ffffc5c9 = 0;
        }
        else {
          DAT_ffffc5c8 = FUN_00002478((int)(char)DAT_ffffc5c8,1);
        }
        if (0x20 < DAT_ffffc5c8) {
          cVar2 = FUN_000671a4(0x6f);
          if (cVar2 == '\0') {
            DAT_ffffc5cc = 1;
          }
          DAT_ffffc5cf = '\0';
          DAT_ffffc5ce = 0;
        }
      }
    }
    else {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 0x800) == 0) {
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5c9 = 0;
          DAT_ffffc5c8 = 0;
        }
        else {
          DAT_ffffc5c9 = FUN_00002478((int)(char)DAT_ffffc5c9,1);
        }
        if (0x20 < DAT_ffffc5c9) {
          cVar2 = FUN_000671a4(0x70);
          if (cVar2 == '\0') {
            DAT_ffffc5cd = 1;
          }
          DAT_ffffc5d0 = '\0';
          DAT_ffffc5ce = 0;
        }
      }
      else {
        cVar2 = FUN_000671a4(0x70);
        if (cVar2 == '\0') {
          DAT_ffffc5d0 = '\x01';
        }
        DAT_ffffc5c9 = 0;
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5c8 = 0;
        }
      }
    }
    cVar2 = DAT_ffffc5cf;
    if ((DAT_ffffc5cf == '\x01') && (cVar2 = DAT_ffffc5d0, DAT_ffffc5d0 == '\x01')) {
      DAT_ffffc5ce = 1;
      DAT_ffffc5cc = 0;
      DAT_ffffc5cd = 0;
    }
  }
  return cVar2;
}


