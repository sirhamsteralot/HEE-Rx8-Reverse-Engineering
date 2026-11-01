/* ROM address: 0x00049ab0; body bytes: 340; decompiled */

char FUN_00049ab0(void)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcd40 = 0;
    DAT_ffffcd41 = 0;
    DAT_ffffcd42 = 0;
    DAT_ffffcd43 = 0;
    sVar1 = -0x32bb;
    DAT_ffffcd44 = '\0';
  }
  else {
    bVar2 = false;
    bVar3 = false;
    if (DAT_ffffbe28 == '\x01') {
      uVar4 = FUN_000070ac(2);
      if ((uVar4 & 2) == 0) {
        DAT_ffffcd40 = 0;
        DAT_ffffcd44 = '\x01';
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffcd41 = 0;
        }
      }
      else {
        if (DAT_ffffd1e9 == '\0') {
          DAT_ffffcd40 = FUN_00002478((int)(char)DAT_ffffcd40,1);
        }
        else {
          DAT_ffffcd40 = 0;
          DAT_ffffcd41 = 0;
        }
        if (0x1f < DAT_ffffcd40) {
          DAT_ffffcd44 = '\0';
          bVar2 = true;
        }
      }
    }
    else {
      uVar4 = FUN_000070ac(2);
      if ((uVar4 & 2) == 0) {
        if (DAT_ffffd1e9 == '\0') {
          DAT_ffffcd41 = FUN_00002478((int)(char)DAT_ffffcd41,1);
        }
        else {
          DAT_ffffcd40 = 0;
          DAT_ffffcd41 = 0;
        }
        if (0x1f < DAT_ffffcd41) {
          DAT_ffffcd45 = '\0';
          bVar3 = true;
        }
      }
      else {
        DAT_ffffcd41 = 0;
        DAT_ffffcd45 = '\x01';
        if (DAT_ffffd1e9 == '\x01') {
          DAT_ffffcd40 = 0;
        }
      }
    }
    if ((!bVar2) && (!bVar3)) {
      if (DAT_ffffcd44 != '\x01') {
        return DAT_ffffcd44;
      }
      if (DAT_ffffcd45 != '\x01') {
        return DAT_ffffcd45;
      }
      DAT_ffffcd42 = 0;
      DAT_ffffcd43 = 1;
      return '\x01';
    }
    DAT_ffffcd42 = 1;
    sVar1 = -0x32bd;
  }
  *(undefined1 *)(int)sVar1 = 0;
  return '\x01';
}


