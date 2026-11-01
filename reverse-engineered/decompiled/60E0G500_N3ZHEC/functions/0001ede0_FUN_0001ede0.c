/* ROM address: 0x0001ede0; body bytes: 604; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001ef18) */

uint FUN_0001ede0(void)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  char cVar4;
  char cVar6;
  char cVar7;
  char cVar8;
  uint uVar5;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  cVar4 = DAT_ffffae97;
  fVar3 = DAT_ffffae74;
  bVar2 = DAT_ffffaada;
  fVar1 = DAT_ffffaa10;
  fVar10 = DAT_ffffc1c0;
  fVar11 = DAT_ffffaa88;
  fVar12 = DAT_ffffc12c;
  fVar13 = DAT_ffffb5b8;
  cVar6 = FUN_00002440(DAT_ffffc074,0,0x3727c5ac);
  cVar7 = FUN_00002440(DAT_ffffc084,0,0x3727c5ac);
  cVar8 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  DAT_ffffb15c = FUN_000020c4(fVar13,&DAT_0006a290);
  fVar9 = (float)FUN_00002068(fVar13,&DAT_0006a27c);
  DAT_ffffb154 = (float)FUN_00002068(fVar12,&DAT_0006a29c);
  DAT_ffffb158 = (float)FUN_00002068(fVar12,&DAT_0006a2b0);
  if (fVar11 < 0.8) {
    if (fVar11 < 0.19999999) {
      DAT_ffffb170 = '\0';
    }
  }
  else {
    DAT_ffffb170 = '\x01';
  }
  if (fVar11 < 200.0) {
    if (fVar11 < 199.4) {
      DAT_ffffb174 = '\0';
    }
  }
  else {
    DAT_ffffb174 = '\x01';
  }
  if ((((((((cVar4 != '\x01') || (DAT_ffffb15e < DAT_ffffb15c)) || (60.0 <= DAT_ffffae54)) ||
         ((cVar6 != '\0' || (cVar7 != '\0')))) ||
        ((fVar1 < 82.0 || ((105.0 <= fVar1 || (DAT_ffffb170 != '\x01')))))) ||
       ((DAT_ffffb174 != '\0' ||
        (((fVar13 < DAT_ffffb154 || (DAT_ffffb158 <= fVar13)) || (0.4 < fVar12)))))) ||
      ((((300.0 <= fVar13 && (fVar12 < fVar9)) ||
        ((0.004 <= fVar10 || ((DAT_ffffb164 < 0x7d || (cVar8 != '\0')))))) || (fVar3 < 0.99)))) ||
     ((1.05 <= fVar3 || ((bVar2 != 0 && ((bVar2 != 1 || (DAT_ffffb162 < 0x9c)))))))) {
    DAT_ffffb14a = 0;
  }
  else {
    DAT_ffffb14a = 1;
  }
  if (cVar4 == '\x01') {
    DAT_ffffb15e = FUN_00002460((int)(short)DAT_ffffb15e,1);
  }
  else {
    DAT_ffffb15e = 0;
  }
  uVar5 = (uint)bVar2;
  if (uVar5 == 1) {
    uVar5 = FUN_00002460((int)(short)DAT_ffffb162,1);
    DAT_ffffb162 = (ushort)uVar5;
  }
  else {
    DAT_ffffb162 = 0;
  }
  if (0.004 <= fVar10) {
    DAT_ffffb164 = 0;
  }
  else {
    uVar5 = FUN_00002460((int)(short)DAT_ffffb164,1);
    DAT_ffffb164 = (ushort)uVar5;
  }
  return uVar5;
}


