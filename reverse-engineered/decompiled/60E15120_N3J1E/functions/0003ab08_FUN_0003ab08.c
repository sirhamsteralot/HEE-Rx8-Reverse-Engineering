/* ROM address: 0x0003ab08; body bytes: 328; decompiled */

char FUN_0003ab08(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc570 = 0;
    DAT_ffffc571 = 0;
    DAT_ffffc574 = 0;
    DAT_ffffc575 = 0;
    DAT_ffffc576 = '\0';
    DAT_ffffc577 = '\0';
    cVar2 = '\x01';
  }
  else {
    iVar4 = (int)(char)DAT_ffffc570;
    iVar3 = (int)(char)DAT_ffffc571;
    if (DAT_ffffd1ad == '\x01') {
      iVar4 = 0;
      iVar3 = 0;
    }
    uVar1 = PEDR_W;
    if ((uVar1 & 0x800) == 0) {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x20) == 0) {
        iVar3 = 0;
        DAT_ffffc577 = '\x01';
      }
      else if (DAT_ffffd1ad == '\0') {
        iVar3 = rx8_add_u8_saturate(iVar3,1);
      }
    }
    else {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x20) == 0) {
        if (DAT_ffffd1ad == '\0') {
          iVar4 = rx8_add_u8_saturate(iVar4,1);
        }
      }
      else {
        iVar4 = 0;
        DAT_ffffc576 = '\x01';
      }
    }
    DAT_ffffc570 = (byte)iVar4;
    DAT_ffffc571 = (byte)iVar3;
    if (0x1f < DAT_ffffc570) {
      DAT_ffffc576 = '\0';
    }
    if (0x1f < DAT_ffffc571) {
      DAT_ffffc577 = '\0';
    }
    if ((DAT_ffffc570 < 0x20) && (DAT_ffffc571 < 0x20)) {
      cVar2 = DAT_ffffc576;
      if ((DAT_ffffc576 == '\x01') && (cVar2 = DAT_ffffc577, DAT_ffffc577 == '\x01')) {
        cVar2 = ref_getFaultStatus__(0x38);
        if (cVar2 == '\0') {
          DAT_ffffc575 = 1;
          DAT_ffffc574 = 0;
        }
      }
    }
    else {
      cVar2 = ref_getFaultStatus__(0x38);
      if (cVar2 == '\0') {
        DAT_ffffc574 = 1;
        DAT_ffffc575 = 0;
      }
    }
  }
  return cVar2;
}


