/* ROM address: 0x0003d7de; body bytes: 318; decompiled */

char FUN_0003d7de(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc630 = 0;
    DAT_ffffc631 = 0;
    DAT_ffffc632 = '\0';
    DAT_ffffc633 = '\0';
    DAT_ffffc634 = 0;
    DAT_ffffc62c = 0;
    DAT_ffffc62d = 0;
    cVar3 = '\x01';
  }
  else {
    uVar5 = (uint)DAT_ffffc62c;
    uVar4 = (uint)DAT_ffffc62d;
    uVar2 = PHDR_W;
    bVar1 = (uVar2 & 0x400) == 0;
    if (DAT_ffffd1ad == '\x01') {
      uVar5 = 0;
      uVar4 = 0;
    }
    if (ssv_diag_override_result_ffffb2b0 == '\0') {
      if (bVar1) {
        cVar3 = ref_getFaultStatus__(0x48);
        if (cVar3 == '\0') {
          DAT_ffffc632 = '\x01';
          uVar5 = 0;
        }
      }
      else if (DAT_ffffd1ad == '\0') {
        if ((0x1f < (uVar5 & 0xff)) && (cVar3 = ref_getFaultStatus__(0x48), cVar3 == '\0')) {
          DAT_ffffc630 = 1;
          DAT_ffffc632 = '\0';
          DAT_ffffc634 = 0;
        }
        uVar5 = rx8_add_u8_saturate(uVar5,1);
      }
    }
    else if (bVar1) {
      if (DAT_ffffd1ad == '\0') {
        if ((0x1f < (uVar4 & 0xff)) && (cVar3 = ref_getFaultStatus__(0x49), cVar3 == '\0')) {
          DAT_ffffc631 = 1;
          DAT_ffffc633 = '\0';
          DAT_ffffc634 = 0;
        }
        uVar4 = rx8_add_u8_saturate(uVar4,1);
      }
    }
    else {
      cVar3 = ref_getFaultStatus__(0x49);
      if (cVar3 == '\0') {
        DAT_ffffc633 = '\x01';
        uVar4 = 0;
      }
    }
    DAT_ffffc62c = (char)uVar5;
    DAT_ffffc62d = (char)uVar4;
    cVar3 = DAT_ffffc632;
    if ((DAT_ffffc632 == '\x01') && (cVar3 = DAT_ffffc633, DAT_ffffc633 == '\x01')) {
      DAT_ffffc634 = 1;
      DAT_ffffc630 = 0;
      DAT_ffffc631 = 0;
    }
  }
  return cVar3;
}


