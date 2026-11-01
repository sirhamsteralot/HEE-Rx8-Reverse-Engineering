/* ROM address: 0x00047878; body bytes: 534; decompiled */

uint FUN_00047878(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  cVar7 = DAT_ffffccdf;
  cVar6 = DAT_ffffccd9;
  cVar5 = DAT_ffffccd8;
  bVar4 = DAT_ffffccd1;
  cVar3 = DAT_ffffb5aa;
  uVar2 = DAT_ffffadd6;
  uVar1 = DAT_ffffadd4;
  fVar9 = DAT_ffffc12c;
  fVar10 = DAT_ffffbc1c;
  fVar11 = DAT_ffffb5b8;
  DAT_ffffccb8 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006bda0);
  if (fVar11 < 3000.0) {
    if (fVar11 < 2800.0) {
      DAT_ffffccc2 = '\0';
    }
  }
  else {
    DAT_ffffccc2 = '\x01';
  }
  if (fVar11 < 1150.0) {
    if (fVar11 < 1150.0) {
      DAT_ffffccc3 = '\0';
    }
  }
  else {
    DAT_ffffccc3 = '\x01';
  }
  if (fVar10 < 80.0) {
    if (fVar10 < 76.0) {
      DAT_ffffccc4 = '\0';
    }
  }
  else {
    DAT_ffffccc4 = '\x01';
  }
  if (((cVar7 == '\0') || (((cVar3 == '\0' && (DAT_ffffccc4 == '\x01')) && (DAT_ffffccc3 == '\0'))))
     || ((DAT_ffffccc2 == '\0' && ((cVar3 == '\x01' || (DAT_ffffccc4 == '\0')))))) {
    DAT_ffffccb6 = '\0';
  }
  else {
    DAT_ffffccb6 = '\x01';
  }
  if (((2 < bVar4) && (bVar4 < 5)) &&
     (((cVar5 == '\0' && (((cVar6 == '\x01' && (0x2b84 < uVar1)) && (0x270 < DAT_ffffccbc)))) ||
      (((((cVar5 == '\x01' && (cVar6 == '\0')) && (0x5603 < uVar2)) && (0x270 < DAT_ffffccbe)) ||
       ((DAT_ffffccb8 <= fVar9 && (0x270 < DAT_ffffccc0)))))))) {
    DAT_ffffccb7 = 1;
  }
  uVar8 = 1;
  if ((DAT_ffffccb6 == '\x01') || (uVar8 = (uint)DAT_ffffccb7, uVar8 == 1)) {
    DAT_ffffccb1 = 1;
  }
  else {
    DAT_ffffccb1 = 0;
  }
  if (uVar1 < 0x2b85) {
    DAT_ffffccbc = 0;
  }
  else {
    uVar8 = FUN_00002460((int)(short)DAT_ffffccbc,1);
    DAT_ffffccbc = (ushort)uVar8;
  }
  if (uVar2 < 0x5604) {
    DAT_ffffccbe = 0;
  }
  else {
    uVar8 = FUN_00002460((int)(short)DAT_ffffccbe,1);
    DAT_ffffccbe = (ushort)uVar8;
  }
  if (fVar9 < DAT_ffffccb8) {
    DAT_ffffccc0 = 0;
  }
  else {
    uVar8 = FUN_00002460((int)(short)DAT_ffffccc0,1);
    DAT_ffffccc0 = (ushort)uVar8;
  }
  return uVar8;
}


