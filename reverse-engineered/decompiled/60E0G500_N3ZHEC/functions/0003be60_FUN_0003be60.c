/* ROM address: 0x0003be60; body bytes: 230; decompiled */

uint FUN_0003be60(void)

{
  char cVar2;
  uint uVar1;
  float fVar3;
  
  fVar3 = DAT_ffffb360;
  cVar2 = FUN_00002440(DAT_ffffb360,0x42c80000,0x3727c5ac);
  uVar1 = 1;
  if ((DAT_ffffd201 == '\x01') || (uVar1 = (uint)DAT_ffffd1e9, uVar1 == 1)) {
    DAT_ffffc5ed = '\0';
    DAT_ffffc5ef = '\0';
    DAT_ffffc5ee = '\0';
    DAT_ffffc5f0 = '\0';
  }
  else {
    if ((fVar3 == 0.0) && (DAT_ffffd1c8 == 0)) {
      uVar1 = (uint)DAT_ffffc5ed;
      if (DAT_ffffc5ed != -1) {
        uVar1 = uVar1 + 1;
        DAT_ffffc5ed = (char)uVar1;
      }
    }
    else {
      DAT_ffffc5ed = '\0';
    }
    if ((fVar3 == 0.0) && (uVar1 = (uint)DAT_ffffd1c8, uVar1 == 1)) {
      if (DAT_ffffc5ef != -1) {
        DAT_ffffc5ef = DAT_ffffc5ef + '\x01';
      }
    }
    else {
      DAT_ffffc5ef = '\0';
    }
    if ((cVar2 == '\0') && (uVar1 = (uint)DAT_ffffd1c8, uVar1 == 1)) {
      if (DAT_ffffc5ee != -1) {
        DAT_ffffc5ee = DAT_ffffc5ee + '\x01';
      }
    }
    else {
      DAT_ffffc5ee = '\0';
    }
    if ((cVar2 == '\0') && (DAT_ffffd1c8 == 0)) {
      if (DAT_ffffc5f0 != -1) {
        DAT_ffffc5f0 = DAT_ffffc5f0 + '\x01';
      }
    }
    else {
      DAT_ffffc5f0 = '\0';
    }
  }
  return uVar1;
}


