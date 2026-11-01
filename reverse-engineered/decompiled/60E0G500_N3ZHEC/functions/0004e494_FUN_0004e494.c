/* ROM address: 0x0004e494; body bytes: 94; decompiled */

void FUN_0004e494(void)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  
  DAT_ffffcef0 = DAT_ffffcf68;
  cVar2 = '\v';
  pfVar5 = (float *)&DAT_ffffcef0;
  puVar1 = &DAT_ffffcf18;
  puVar4 = &DAT_ffffcf20;
  do {
    cVar2 = cVar2 + -1;
    puVar4 = puVar4 + -1;
    *puVar4 = *puVar1;
    puVar1 = puVar1 + -1;
  } while (cVar2 != '\0');
  if (DAT_ffffa402 == '\x01') {
    DAT_ffffcef0 = 0;
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
  DAT_ffffcf20 = fVar6 / 12.0;
  return;
}


