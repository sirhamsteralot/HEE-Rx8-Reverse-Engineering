/* ROM address: 0x00049308; body bytes: 340; decompiled */

char FUN_00049308(void)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcd00 = 0;
    DAT_ffffcd01 = 0;
    DAT_ffffcd02 = 0;
    DAT_ffffcd03 = 0;
    sVar1 = -0x32fb;
    DAT_ffffcd04 = '\0';
  }
  else {
    bVar2 = false;
    bVar3 = false;
    if (DAT_ffffbdbc == '\x01') {
      uVar4 = ref_getFromGPIO_(2);
      if ((uVar4 & 2) == 0) {
        DAT_ffffcd00 = 0;
        DAT_ffffcd04 = '\x01';
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffcd01 = 0;
        }
      }
      else {
        if (DAT_ffffd1ad == '\0') {
          DAT_ffffcd00 = rx8_add_u8_saturate((int)(char)DAT_ffffcd00,1);
        }
        else {
          DAT_ffffcd00 = 0;
          DAT_ffffcd01 = 0;
        }
        if (0x1f < DAT_ffffcd00) {
          DAT_ffffcd04 = '\0';
          bVar2 = true;
        }
      }
    }
    else {
      uVar4 = ref_getFromGPIO_(2);
      if ((uVar4 & 2) == 0) {
        if (DAT_ffffd1ad == '\0') {
          DAT_ffffcd01 = rx8_add_u8_saturate((int)(char)DAT_ffffcd01,1);
        }
        else {
          DAT_ffffcd00 = 0;
          DAT_ffffcd01 = 0;
        }
        if (0x1f < DAT_ffffcd01) {
          DAT_ffffcd05 = '\0';
          bVar3 = true;
        }
      }
      else {
        DAT_ffffcd01 = 0;
        DAT_ffffcd05 = '\x01';
        if (DAT_ffffd1ad == '\x01') {
          DAT_ffffcd00 = 0;
        }
      }
    }
    if ((!bVar2) && (!bVar3)) {
      if (DAT_ffffcd04 != '\x01') {
        return DAT_ffffcd04;
      }
      if (DAT_ffffcd05 != '\x01') {
        return DAT_ffffcd05;
      }
      DAT_ffffcd02 = 0;
      DAT_ffffcd03 = 1;
      return '\x01';
    }
    DAT_ffffcd02 = 1;
    sVar1 = -0x32fd;
  }
  *(undefined1 *)(int)sVar1 = 0;
  return '\x01';
}


