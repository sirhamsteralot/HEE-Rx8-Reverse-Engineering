/* ROM address: 0x0003a6c8; body bytes: 354; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003a70c) */

char FUN_0003a6c8(void)

{
  ushort uVar1;
  char cVar2;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc561 = 0;
    DAT_ffffc562 = 0;
    DAT_ffffc564 = '\0';
    DAT_ffffc565 = '\0';
    DAT_ffffc563 = 0;
    DAT_ffffc55a = 0;
    DAT_ffffc55b = 0;
    cVar2 = '\x01';
  }
  else {
    if (secondary_air_request_final_ffffa960 == '\0') {
      uVar1 = PHDR_W;
      if ((uVar1 & 8) == 0) {
        cVar2 = ref_getFaultStatus__(0x71);
        if (cVar2 == '\0') {
          DAT_ffffc564 = '\x01';
        }
        DAT_ffffc55a = 0;
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc55b = 0;
        }
      }
      else {
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc55a = 0;
          DAT_ffffc55b = 0;
        }
        else {
          DAT_ffffc55a = rx8_add_u8_saturate((int)(char)DAT_ffffc55a,1);
        }
        if (0x20 < DAT_ffffc55a) {
          cVar2 = ref_getFaultStatus__(0x71);
          if (cVar2 == '\0') {
            DAT_ffffc561 = 1;
          }
          DAT_ffffc564 = '\0';
          DAT_ffffc563 = 0;
        }
      }
    }
    else {
      uVar1 = PHDR_W;
      if ((uVar1 & 8) == 0) {
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc55b = 0;
          DAT_ffffc55a = 0;
        }
        else {
          DAT_ffffc55b = rx8_add_u8_saturate((int)(char)DAT_ffffc55b,1);
        }
        if (0x20 < DAT_ffffc55b) {
          cVar2 = ref_getFaultStatus__(0x72);
          if (cVar2 == '\0') {
            DAT_ffffc562 = 1;
          }
          DAT_ffffc565 = '\0';
          DAT_ffffc563 = 0;
        }
      }
      else {
        cVar2 = ref_getFaultStatus__(0x72);
        if (cVar2 == '\0') {
          DAT_ffffc565 = '\x01';
        }
        DAT_ffffc55b = 0;
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffc55a = 0;
        }
      }
    }
    cVar2 = DAT_ffffc564;
    if ((DAT_ffffc564 == '\x01') && (cVar2 = DAT_ffffc565, DAT_ffffc565 == '\x01')) {
      DAT_ffffc563 = 1;
      DAT_ffffc561 = 0;
      DAT_ffffc562 = 0;
    }
  }
  return cVar2;
}


