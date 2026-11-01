/* ROM address: 0x00020be4; body bytes: 334; decompiled */

uint FUN_00020be4(void)

{
  bool bVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = DAT_ffffaa10;
  fVar4 = DAT_ffffc12c;
  fVar5 = DAT_ffffb5b8;
  DAT_ffffb1e8 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006a3c4);
  DAT_ffffb1ec = (float)FUN_00002068(fVar5,&DAT_0006a3d8);
  if (fVar4 < DAT_ffffb1e8) {
    if (fVar4 < DAT_ffffb1e8 - 0.04) {
      DAT_ffffb229 = 0;
    }
  }
  else {
    DAT_ffffb229 = 1;
  }
  if (fVar4 <= DAT_ffffb1ec) {
    if (fVar4 <= DAT_ffffb1ec - 0.04) {
      DAT_ffffb22b = '\0';
    }
  }
  else {
    DAT_ffffb22b = '\x01';
  }
  if (fVar5 < 1000.0) {
    if (fVar5 < 800.0) {
      DAT_ffffb22a = 0;
    }
  }
  else {
    DAT_ffffb22a = 1;
  }
  if (fVar5 <= 5500.0) {
    if (fVar5 <= 5300.0) {
      DAT_ffffb22c = '\0';
    }
  }
  else {
    DAT_ffffb22c = '\x01';
  }
  uVar2 = (uint)DAT_ffffb229;
  if ((((uVar2 == 1) && (DAT_ffffb22b == '\0')) && (uVar2 = (uint)DAT_ffffb22a, uVar2 == 1)) &&
     (uVar2 = (uint)DAT_ffffb22c, uVar2 == 0)) {
    DAT_ffffb1c4 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffb1c4 = 0;
    bVar1 = false;
  }
  if (fVar3 < 100.0) {
    if (fVar3 < 97.0) {
      DAT_ffffb248 = 0;
    }
  }
  else {
    DAT_ffffb248 = 1;
  }
  if (bVar1) {
    uVar2 = (uint)DAT_ffffb1b4;
    if (uVar2 != 0) {
      DAT_ffffb1b4 = DAT_ffffb1b4 - 1;
    }
  }
  else if (DAT_ffffb248 == 0) {
    DAT_ffffb1b4 = 0x493e;
  }
  if ((DAT_ffffb1b4 == 0) && (uVar2 = (uint)DAT_ffffb248, uVar2 == 1)) {
    DAT_ffffb1c9 = 0;
  }
  else {
    DAT_ffffb1c9 = 1;
  }
  return uVar2;
}


