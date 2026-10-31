/* ROM address: 0x0003d954; body bytes: 214; decompiled */

uint FUN_0003d954(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc62e = 0x27;
    uVar1 = 8;
    DAT_ffffc62f = '\b';
    DAT_ffffc635 = 0;
    DAT_ffffc636 = 0;
  }
  else if (ssv_diag_override_result_ffffb2b0 == '\0') {
    uVar1 = (uint)DAT_ffffc637;
    if (uVar1 == 1) {
      uVar1 = (uint)DAT_ffffc62e;
      if (uVar1 == 0) {
        uVar1 = ref_getFaultStatus__(0x58);
        uVar1 = uVar1 & 0xff;
        if (((uVar1 == 0) && (DAT_ffffc630 == '\0')) && (uVar1 = (uint)DAT_ffffc631, uVar1 == 0)) {
          DAT_ffffc635 = 1;
          DAT_ffffc636 = 0;
        }
      }
      else {
        DAT_ffffc62e = DAT_ffffc62e - 1;
      }
      DAT_ffffc62f = '\b';
    }
    else {
      DAT_ffffc62e = 0x27;
      if (DAT_ffffc62f == '\0') {
        uVar1 = ref_getFaultStatus__(0x58);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          DAT_ffffc636 = 1;
          DAT_ffffc635 = 0;
        }
      }
      else {
        DAT_ffffc62f = DAT_ffffc62f + -1;
      }
    }
  }
  else {
    DAT_ffffc62e = 0x27;
    uVar1 = 8;
    DAT_ffffc62f = '\b';
  }
  return uVar1;
}


