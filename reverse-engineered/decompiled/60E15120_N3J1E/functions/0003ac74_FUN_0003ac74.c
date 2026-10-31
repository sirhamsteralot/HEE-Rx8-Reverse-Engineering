/* ROM address: 0x0003ac74; body bytes: 324; decompiled */

char FUN_0003ac74(void)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc572 = 0;
    DAT_ffffc573 = 0;
    DAT_ffffc578 = 0;
    DAT_ffffc579 = 0;
    DAT_ffffc57a = '\0';
    DAT_ffffc57b = '\0';
    cVar2 = '\x01';
  }
  else {
    iVar4 = (int)(char)DAT_ffffc572;
    iVar3 = (int)(char)DAT_ffffc573;
    if (DAT_ffffd1ad == '\x01') {
      iVar4 = 0;
      iVar3 = 0;
    }
    uVar1 = PEDR_W;
    if ((uVar1 & 0x10) == 0) {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x10) == 0) {
        iVar3 = 0;
        DAT_ffffc57b = '\x01';
      }
      else if (DAT_ffffd1ad == '\0') {
        iVar3 = rx8_add_u8_saturate(iVar3,1);
      }
    }
    else {
      uVar1 = PHDR_W;
      if ((uVar1 & 0x10) == 0) {
        if (DAT_ffffd1ad == '\0') {
          iVar4 = rx8_add_u8_saturate(iVar4,1);
        }
      }
      else {
        iVar4 = 0;
        DAT_ffffc57a = '\x01';
      }
    }
    DAT_ffffc572 = (byte)iVar4;
    DAT_ffffc573 = (byte)iVar3;
    if (0x1f < DAT_ffffc572) {
      DAT_ffffc57a = '\0';
    }
    if (0x1f < DAT_ffffc573) {
      DAT_ffffc57b = '\0';
    }
    if ((DAT_ffffc572 < 0x20) && (DAT_ffffc573 < 0x20)) {
      cVar2 = DAT_ffffc57a;
      if ((DAT_ffffc57a == '\x01') && (cVar2 = DAT_ffffc57b, DAT_ffffc57b == '\x01')) {
        cVar2 = ref_getFaultStatus__(0x39);
        if (cVar2 == '\0') {
          DAT_ffffc579 = 1;
          DAT_ffffc578 = 0;
        }
      }
    }
    else {
      cVar2 = ref_getFaultStatus__(0x39);
      if (cVar2 == '\0') {
        DAT_ffffc578 = 1;
        DAT_ffffc579 = 0;
      }
    }
  }
  return cVar2;
}


