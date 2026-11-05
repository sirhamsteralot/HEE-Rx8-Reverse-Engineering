/* ROM address: 0x0004dce8; body bytes: 94; decompiled */

void FUN_0004dce8(void)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  
  DAT_ffffceb4 = DAT_ffffcf2c;
  cVar2 = '\v';
  pfVar5 = (float *)&DAT_ffffceb4;
  puVar1 = &DAT_ffffcedc;
  puVar4 = &cruise_speed_error_mean12_ffffcee4;
  do {
    cVar2 = cVar2 + -1;
    puVar4 = puVar4 + -1;
    *puVar4 = *puVar1;
    puVar1 = puVar1 + -1;
  } while (cVar2 != '\0');
  if (DAT_ffffa402 == '\x01') {
    DAT_ffffceb4 = 0;
  }
  else {
  }
  bVar3 = 0;
  fVar6 = 0.0;
  do {
    bVar3 = bVar3 + 1;
    fVar7 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    fVar6 = fVar7 + fVar6;
  } while (bVar3 < 0xc);
  cruise_speed_error_mean12_ffffcee4 = fVar6 / 12.0;
  return;
}


