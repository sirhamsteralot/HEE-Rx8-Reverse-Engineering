/* ROM address: 0x0003a53c; body bytes: 354; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003a580) */

char FUN_0003a53c(void)

{
  ushort uVar1;
  char cVar2;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc55c = 0;
    DAT_ffffc55d = 0;
    DAT_ffffc55f = '\0';
    DAT_ffffc560 = '\0';
    DAT_ffffc55e = 0;
    DAT_ffffc558 = 0;
    DAT_ffffc559 = 0;
    cVar2 = '\x01';
  }
  else {
    if (secondary_air_pump_request_ffffbf6c == '\0') {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x800) == 0) {
        cVar2 = ref_getFaultStatus__(0x6f);
        if (cVar2 == '\0') {
          DAT_ffffc55f = '\x01';
        }
        DAT_ffffc558 = 0;
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc559 = 0;
        }
      }
      else {
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc558 = 0;
          DAT_ffffc559 = 0;
        }
        else {
          DAT_ffffc558 = rx8_add_u8_saturate((int)(char)DAT_ffffc558,1);
        }
        if (0x20 < DAT_ffffc558) {
          cVar2 = ref_getFaultStatus__(0x6f);
          if (cVar2 == '\0') {
            DAT_ffffc55c = 1;
          }
          DAT_ffffc55f = '\0';
          DAT_ffffc55e = 0;
        }
      }
    }
    else {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x800) == 0) {
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc559 = 0;
          DAT_ffffc558 = 0;
        }
        else {
          DAT_ffffc559 = rx8_add_u8_saturate((int)(char)DAT_ffffc559,1);
        }
        if (0x20 < DAT_ffffc559) {
          cVar2 = ref_getFaultStatus__(0x70);
          if (cVar2 == '\0') {
            DAT_ffffc55d = 1;
          }
          DAT_ffffc560 = '\0';
          DAT_ffffc55e = 0;
        }
      }
      else {
        cVar2 = ref_getFaultStatus__(0x70);
        if (cVar2 == '\0') {
          DAT_ffffc560 = '\x01';
        }
        DAT_ffffc559 = 0;
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc558 = 0;
        }
      }
    }
    cVar2 = DAT_ffffc55f;
    if ((DAT_ffffc55f == '\x01') && (cVar2 = DAT_ffffc560, DAT_ffffc560 == '\x01')) {
      DAT_ffffc55e = 1;
      DAT_ffffc55c = 0;
      DAT_ffffc55d = 0;
    }
  }
  return cVar2;
}


