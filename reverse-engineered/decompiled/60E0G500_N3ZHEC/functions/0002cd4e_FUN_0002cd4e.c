/* ROM address: 0x0002cd4e; body bytes: 382; decompiled */

uint FUN_0002cd4e(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  if (DAT_ffffb5a4 == 1) {
    if (DAT_ffffbc1c < 0.0) {
      if (DAT_ffffbc1c < -2.0) {
        DAT_ffffbcc2 = '\0';
      }
    }
    else {
      DAT_ffffbcc2 = '\x01';
    }
    if (((DAT_ffffbcaa == '\x01') && (1 < DAT_ffffbcb0)) || (DAT_ffffbcc2 == '\0')) {
      DAT_ffffbcad = 1;
    }
    else if ((DAT_ffffbcaa == '\0') && (DAT_ffffbcc2 == '\x01')) {
      DAT_ffffbcad = 0;
    }
    if (DAT_ffffbcab == '\x01') {
      if (1 < DAT_ffffbcb2) {
        DAT_ffffbcae = 1;
      }
    }
    else {
      DAT_ffffbcae = 0;
    }
    if (DAT_ffffbcac == 1) {
      if (1 < DAT_ffffbcb4) {
        DAT_ffffbcaf = 1;
      }
    }
    else {
      DAT_ffffbcaf = 0;
    }
    if (DAT_ffffbcaa == '\x01') {
      DAT_ffffbcb0 = FUN_00002460((int)(short)DAT_ffffbcb0,1);
    }
    else {
      DAT_ffffbcb0 = 0;
    }
    if (DAT_ffffbcab == '\x01') {
      DAT_ffffbcb2 = FUN_00002460((int)(short)DAT_ffffbcb2,1);
    }
    else {
      DAT_ffffbcb2 = 0;
    }
    if (DAT_ffffbcac == 1) {
      uVar1 = FUN_00002460((int)(short)DAT_ffffbcb4,1);
      DAT_ffffbcb4 = (ushort)uVar1;
    }
    else {
      DAT_ffffbcb4 = 0;
      uVar1 = (uint)DAT_ffffbcac;
    }
  }
  else {
    DAT_ffffbcad = 0;
    uVar2 = (uint)DAT_ffffbb55;
    DAT_ffffbcae = 0;
    uVar1 = (uint)DAT_ffffb5a4;
    DAT_ffffbcaf = uVar3;
    if (uVar2 != 0) {
      uVar1 = uVar2;
      if (uVar2 == 1) {
        DAT_ffffbcad = 1;
      }
      else if ((uVar2 == 2) || (uVar2 == 3)) {
        DAT_ffffbcae = 1;
      }
      else if (uVar2 == 4) {
        DAT_ffffbcaf = 1;
      }
      else if (((uVar2 != 5) && (uVar2 != 6)) && (uVar2 == 7)) {
        DAT_ffffbcad = 1;
      }
    }
  }
  return uVar1;
}


