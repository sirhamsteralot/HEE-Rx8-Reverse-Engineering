/* ROM address: 0x0005153c; body bytes: 388; decompiled */

char FUN_0005153c(void)

{
  char cVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  sVar2 = DAT_ffffd0de;
  fVar11 = 0.0;
  fVar10 = 100.0;
  fVar7 = (float)FUN_000024c0(0x42c80000,0,(int)DAT_ffffd0de);
  fVar8 = (float)FUN_000024c0(fVar10,fVar11,(int)DAT_ffffd0dc);
  fVar9 = (float)FUN_000024c0(fVar10,fVar11,(int)DAT_ffffd0e2);
  fVar7 = (fVar7 - fVar8) / 1000.0;
  cVar4 = FUN_00002440(fVar7,fVar11,0x3727c5ac);
  fVar8 = (fVar8 - fVar9) / 1000.0;
  cVar5 = FUN_00002440(fVar8,fVar11,0x3727c5ac);
  cVar3 = DAT_ffffd201;
  cVar1 = DAT_ffffcfb4;
  if ((DAT_ffffd10c == sVar2) || (DAT_ffffd0e7 != '\x01')) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((DAT_ffffd201 == '\x01') || ((DAT_ffffd110 == '\0' && (DAT_ffffcfb4 == '\x01')))) {
    FUN_0003ec20(fVar11,&DAT_ffff86d0);
    FUN_0003ec20(fVar11,&DAT_ffff86d8);
  }
  else if (cVar6 == '\x01') {
    if (cVar4 == '\0') {
      fVar7 = 0.35999998;
    }
    else {
      fVar7 = 0.35 / fVar7;
    }
    FUN_0003ec20(fVar7,&DAT_ffff86d0);
    if (cVar5 == '\0') {
      fVar8 = 0.35999998;
    }
    else {
      fVar8 = 0.35 / fVar8;
    }
    FUN_0003ec20(fVar8,&DAT_ffff86d8);
  }
  if (cVar3 == '\x01') {
    cVar6 = '\x01';
    DAT_ffffd0d0 = fVar11;
  }
  else if (cVar6 == '\x01') {
    fVar7 = (float)FUN_0003eb72(fVar11,&DAT_ffff86d0);
    fVar8 = (float)FUN_0003eb72(fVar11,&DAT_ffff86d8);
    cVar6 = FUN_00002440(fVar8,fVar11,0x3727c5ac);
    DAT_ffffd0d0 = fVar11;
    if (cVar6 != '\0') {
      DAT_ffffd0d0 = (fVar7 / fVar8) * fVar10;
    }
  }
  DAT_ffffd10c = sVar2;
  DAT_ffffd110 = cVar1;
  return cVar6;
}


