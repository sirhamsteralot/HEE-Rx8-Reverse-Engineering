/* ROM address: 0x000316e0; body bytes: 872; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00031a78) */

uint FUN_000316e0(void)

{
  char cVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar8 = DAT_ffffbf58;
  fVar3 = DAT_ffffbf50;
  fVar6 = DAT_ffffbf48;
  bVar2 = DAT_ffffbf3a;
  cVar1 = DAT_ffffbf38;
  if (DAT_ffffaa10 < 40.0) {
    DAT_ffffbf74 = 0.02;
  }
  else {
    DAT_ffffbf74 = 0.007;
  }
  if (DAT_ffffb5b8 < 6250.0) {
    if (DAT_ffffb5b8 < 6062.0) {
      DAT_ffffbf9e = '\0';
    }
  }
  else {
    DAT_ffffbf9e = '\x01';
  }
  fVar5 = DAT_ffffb5b8;
  fVar9 = DAT_ffffaa10;
  fVar7 = DAT_ffffbf34;
  fVar10 = DAT_ffffbf1c;
  DAT_ffffbf90 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b09c);
  if (fVar5 < DAT_ffffbf90) {
    if (fVar5 < DAT_ffffbf90 - 188.0) {
      DAT_ffffbf9f = '\0';
    }
  }
  else {
    DAT_ffffbf9f = '\x01';
  }
  DAT_ffffbf94 = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006b008);
  DAT_ffffbf70 = fVar7;
  if (60.0 <= DAT_ffffadbc) {
    DAT_ffffbf70 = DAT_ffffbf94 * fVar7;
  }
  if (fVar10 < DAT_ffffbf70) {
    if (fVar10 < DAT_ffffbf70 - DAT_ffffbf74) {
      DAT_ffffbfa0 = '\0';
    }
  }
  else {
    DAT_ffffbfa0 = '\x01';
  }
  if (fVar10 < fVar7) {
    if (fVar10 < fVar7 - DAT_ffffbf74) {
      DAT_ffffbfa1 = '\0';
    }
  }
  else {
    DAT_ffffbfa1 = '\x01';
  }
  if ((DAT_ffffbf9e == '\x01') || ((DAT_ffffbf9f == '\x01' && (DAT_ffffbfa0 == '\x01')))) {
    DAT_ffffbf39 = '\x01';
  }
  else {
    DAT_ffffbf39 = '\0';
  }
  if ((DAT_ffffbf9e == '\x01') || ((DAT_ffffbf9f == '\x01' && (DAT_ffffbfa1 == '\x01')))) {
    DAT_ffffbf38 = '\x01';
  }
  else {
    DAT_ffffbf38 = '\0';
  }
  if (DAT_ffffbf38 == '\0') {
    DAT_ffffbf64 = 0.0;
    DAT_ffffbf68 = 0.0;
    DAT_ffffbf5c = fVar10;
    DAT_ffffbf60 = 0.0;
  }
  else {
    fVar5 = (float)FUN_00002068(fVar5,&DAT_0006aff4);
    DAT_ffffbf64 = rx8_clamp_float(fVar5,0.0,1.0);
    DAT_ffffbf68 = DAT_ffffbf64 * fVar10;
    if (fVar3 <= DAT_ffffbf68) {
      if (DAT_ffffbf68 < fVar6) {
        fVar6 = DAT_ffffbf68;
      }
      DAT_ffffbf5c = fVar10 - fVar6;
      DAT_ffffbf60 = fVar6;
    }
    else {
      DAT_ffffbf5c = fVar10 - fVar3;
      DAT_ffffbf60 = fVar3;
    }
  }
  if ((DAT_ffffbf5c < fVar7) || ((DAT_ffffbf39 != '\0' && (DAT_ffffbf38 != '\x01')))) {
    if (DAT_ffffbf5c < fVar7 - 0.005) {
      DAT_ffffbf3a = 0;
    }
  }
  else {
    DAT_ffffbf3a = 1;
  }
  fVar7 = fVar7 + fVar8;
  if (DAT_ffffbf5c < fVar7) {
    if (DAT_ffffbf5c < fVar7 - 0.005) {
      DAT_ffffbf7c = 0;
    }
  }
  else {
    DAT_ffffbf7c = 1;
  }
  fVar8 = DAT_ffffbf44 + fVar8;
  if (DAT_ffffbf5c < fVar8) {
    if (DAT_ffffbf5c < fVar8 - 0.005) {
      DAT_ffffbf7d = 0;
    }
  }
  else {
    DAT_ffffbf7d = 1;
  }
  if (DAT_ffffbf38 == '\x01') {
    if (cVar1 == '\0') {
      DAT_ffffbf78 = FUN_000020ac(fVar9,&DAT_0006b01c);
    }
    else if (DAT_ffffbf78 < 2) {
      DAT_ffffbf78 = '\0';
    }
    else {
      DAT_ffffbf78 = DAT_ffffbf78 - 1;
    }
    DAT_ffffbf79 = '\0';
  }
  else {
    if (cVar1 == '\x01') {
      DAT_ffffbf79 = '\n';
    }
    else if (DAT_ffffbf79 < 2) {
      DAT_ffffbf79 = '\0';
    }
    else {
      DAT_ffffbf79 = DAT_ffffbf79 - 1;
    }
    DAT_ffffbf78 = '\0';
  }
  uVar4 = (uint)bVar2;
  if (DAT_ffffbf3a == 1) {
    if (uVar4 == 0) {
      uVar4 = FUN_000020ac(fVar9,&DAT_0006b028);
      DAT_ffffbf7a = (byte)uVar4;
    }
    else {
      uVar4 = 1;
      if (DAT_ffffbf7a < 2) {
        DAT_ffffbf7a = '\0';
      }
      else {
        DAT_ffffbf7a = DAT_ffffbf7a - 1;
      }
    }
    DAT_ffffbf7b = '\0';
  }
  else {
    if (uVar4 == 1) {
      uVar4 = FUN_000020ac(fVar9,&DAT_0006b034);
      DAT_ffffbf7b = (byte)uVar4;
    }
    else if (DAT_ffffbf7b < 2) {
      DAT_ffffbf7b = '\0';
    }
    else {
      DAT_ffffbf7b = DAT_ffffbf7b - 1;
    }
    DAT_ffffbf7a = '\0';
  }
  return uVar4;
}


