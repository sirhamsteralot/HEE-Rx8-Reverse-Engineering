/* ROM address: 0x0002cfa6; body bytes: 356; decompiled */

uint FUN_0002cfa6(void)

{
  uint uVar1;
  
  if (DAT_ffffb5aa == '\x01') {
    DAT_ffffbca9 = 0;
  }
  else if ((DAT_ffffbca8 == 1) && (0xb < DAT_ffffbcb6)) {
    DAT_ffffbca9 = 1;
  }
  else if ((DAT_ffffbca8 == 2) && (0xb < DAT_ffffbcb8)) {
    DAT_ffffbca9 = 2;
  }
  else if ((DAT_ffffbca8 == 3) && (0xb < DAT_ffffbcba)) {
    DAT_ffffbca9 = 3;
  }
  else if ((DAT_ffffbca8 == 4) && (0xb < DAT_ffffbcbc)) {
    DAT_ffffbca9 = 4;
  }
  else if ((DAT_ffffbca8 == 5) && (0xb < DAT_ffffbcbe)) {
    DAT_ffffbca9 = 5;
  }
  else if ((DAT_ffffbca8 == 6) && (0xb < DAT_ffffbcc0)) {
    DAT_ffffbca9 = 6;
  }
  if (DAT_ffffbca8 == 1) {
    DAT_ffffbcb6 = FUN_00002460((int)(short)DAT_ffffbcb6,1);
  }
  else {
    DAT_ffffbcb6 = 0;
  }
  if (DAT_ffffbca8 == 2) {
    DAT_ffffbcb8 = FUN_00002460((int)(short)DAT_ffffbcb8,1);
  }
  else {
    DAT_ffffbcb8 = 0;
  }
  if (DAT_ffffbca8 == 3) {
    DAT_ffffbcba = FUN_00002460((int)(short)DAT_ffffbcba,1);
  }
  else {
    DAT_ffffbcba = 0;
  }
  if (DAT_ffffbca8 == 4) {
    DAT_ffffbcbc = FUN_00002460((int)(short)DAT_ffffbcbc,1);
  }
  else {
    DAT_ffffbcbc = 0;
  }
  if (DAT_ffffbca8 == 5) {
    DAT_ffffbcbe = FUN_00002460((int)(short)DAT_ffffbcbe,1);
  }
  else {
    DAT_ffffbcbe = 0;
  }
  uVar1 = (uint)DAT_ffffbca8;
  if (uVar1 == 6) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffbcc0,1);
    DAT_ffffbcc0 = (ushort)uVar1;
  }
  else {
    DAT_ffffbcc0 = 0;
  }
  return uVar1;
}


