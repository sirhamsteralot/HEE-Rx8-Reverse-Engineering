/* ROM address: 0x00021138; body bytes: 294; decompiled */

void FUN_00021138(void)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = 100.0;
  DAT_ffffb24c = (DAT_ffffb35c * DAT_ffffaa88) / 100.0;
  fVar4 = DAT_ffffaa88;
  fVar6 = DAT_ffffbe68;
  DAT_ffffb2aa = FUN_000020c4(DAT_ffffb5b8,&DAT_0006a59c);
  if ((&DAT_ffffb24c)[DAT_ffffb2aa] < DAT_ffffb294) {
    DAT_ffffb2a4 = 0.78;
  }
  else {
    DAT_ffffb2a4 = 0.4;
  }
  DAT_ffffb294 = rx8_first_order_filter
                           ((&DAT_ffffb24c)[DAT_ffffb2aa],DAT_ffffb294,DAT_ffffb2a4,1e-05);
  fVar4 = (float)FUN_0003ea74(DAT_ffffb294,fVar4);
  DAT_ffffb29c = fVar4 * fVar5;
  if (fVar6 < 2.6) {
    DAT_ffffb2ae = 0;
  }
  else {
    DAT_ffffb2ae = FUN_00002460((int)DAT_ffffb2ae,1);
  }
  if (-2.6 <= fVar6) {
    DAT_ffffb2b0 = 0;
  }
  else {
    DAT_ffffb2b0 = FUN_00002460((int)DAT_ffffb2b0,1);
  }
  cVar2 = '\x0f';
  uVar1 = 0xe;
  puVar3 = &DAT_ffffb28c;
  do {
    cVar2 = cVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = (&DAT_ffffb24c)[uVar1 & 0xff];
    uVar1 = uVar1 + 0xff;
  } while (cVar2 != '\0');
  return;
}


