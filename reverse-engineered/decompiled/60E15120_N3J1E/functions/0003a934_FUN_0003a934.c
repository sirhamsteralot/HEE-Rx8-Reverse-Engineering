/* ROM address: 0x0003a934; body bytes: 322; decompiled */

char FUN_0003a934(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc56a = 0;
    DAT_ffffc56b = 0;
    DAT_ffffc56c = '\0';
    DAT_ffffc56d = '\0';
    DAT_ffffc56e = 0;
    DAT_ffffc568 = 0;
    DAT_ffffc569 = 0;
    cVar3 = '\x01';
  }
  else {
    uVar5 = (uint)DAT_ffffc568;
    uVar4 = (uint)DAT_ffffc569;
    uVar2 = PHDR_W;
    bVar1 = (uVar2 & 1) == 0;
    if (DAT_ffffd1ad == '\x01') {
      uVar5 = 0;
      uVar4 = 0;
    }
    if (vdi_command_ffffc1c0 == '\0') {
      if (bVar1) {
        cVar3 = ref_getFaultStatus__(7);
        if (cVar3 == '\0') {
          DAT_ffffc56c = '\x01';
          uVar5 = 0;
        }
      }
      else if (DAT_ffffd1ad == '\0') {
        if ((0x1f < (uVar5 & 0xff)) && (cVar3 = ref_getFaultStatus__(7), cVar3 == '\0')) {
          DAT_ffffc56a = 1;
          DAT_ffffc56c = '\0';
          DAT_ffffc56e = 0;
        }
        uVar5 = rx8_add_u8_saturate(uVar5,1);
      }
    }
    else if (bVar1) {
      if (DAT_ffffd1ad == '\0') {
        if ((0x1f < (uVar4 & 0xff)) && (cVar3 = ref_getFaultStatus__(8), cVar3 == '\0')) {
          DAT_ffffc56b = 1;
          DAT_ffffc56d = '\0';
          DAT_ffffc56e = 0;
        }
        uVar4 = rx8_add_u8_saturate(uVar4,1);
      }
    }
    else {
      cVar3 = ref_getFaultStatus__(8);
      if (cVar3 == '\0') {
        DAT_ffffc56d = '\x01';
        uVar4 = 0;
      }
    }
    DAT_ffffc568 = (char)uVar5;
    DAT_ffffc569 = (char)uVar4;
    cVar3 = DAT_ffffc56c;
    if ((DAT_ffffc56c == '\x01') && (cVar3 = DAT_ffffc56d, DAT_ffffc56d == '\x01')) {
      DAT_ffffc56e = 1;
      DAT_ffffc56a = 0;
      DAT_ffffc56b = 0;
    }
  }
  return cVar3;
}


