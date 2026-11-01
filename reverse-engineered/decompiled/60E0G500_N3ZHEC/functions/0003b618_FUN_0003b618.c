/* ROM address: 0x0003b618; body bytes: 354; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003b65c) */

char FUN_0003b618(void)

{
  ushort uVar1;
  char cVar2;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc5d1 = 0;
    DAT_ffffc5d2 = 0;
    DAT_ffffc5d4 = '\0';
    DAT_ffffc5d5 = '\0';
    DAT_ffffc5d3 = 0;
    DAT_ffffc5ca = 0;
    DAT_ffffc5cb = 0;
    cVar2 = '\x01';
  }
  else {
    if (DAT_ffffa9e4 == '\0') {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 8) == 0) {
        cVar2 = FUN_000671a4(0x71);
        if (cVar2 == '\0') {
          DAT_ffffc5d4 = '\x01';
        }
        DAT_ffffc5ca = 0;
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5cb = 0;
        }
      }
      else {
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5ca = 0;
          DAT_ffffc5cb = 0;
        }
        else {
          DAT_ffffc5ca = FUN_00002478((int)(char)DAT_ffffc5ca,1);
        }
        if (0x20 < DAT_ffffc5ca) {
          cVar2 = FUN_000671a4(0x71);
          if (cVar2 == '\0') {
            DAT_ffffc5d1 = 1;
          }
          DAT_ffffc5d4 = '\0';
          DAT_ffffc5d3 = 0;
        }
      }
    }
    else {
      uVar1 = DAT_fffff72c;
      if ((uVar1 & 8) == 0) {
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5cb = 0;
          DAT_ffffc5ca = 0;
        }
        else {
          DAT_ffffc5cb = FUN_00002478((int)(char)DAT_ffffc5cb,1);
        }
        if (0x20 < DAT_ffffc5cb) {
          cVar2 = FUN_000671a4(0x72);
          if (cVar2 == '\0') {
            DAT_ffffc5d2 = 1;
          }
          DAT_ffffc5d5 = '\0';
          DAT_ffffc5d3 = 0;
        }
      }
      else {
        cVar2 = FUN_000671a4(0x72);
        if (cVar2 == '\0') {
          DAT_ffffc5d5 = '\x01';
        }
        DAT_ffffc5cb = 0;
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffc5ca = 0;
        }
      }
    }
    cVar2 = DAT_ffffc5d4;
    if ((DAT_ffffc5d4 == '\x01') && (cVar2 = DAT_ffffc5d5, DAT_ffffc5d5 == '\x01')) {
      DAT_ffffc5d3 = 1;
      DAT_ffffc5d1 = 0;
      DAT_ffffc5d2 = 0;
    }
  }
  return cVar2;
}


