/* ROM address: 0x00009440; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009440 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00009440(byte param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  sVar1 = *(short *)(&PTR_ATUII_TCNT2B_W_0000d828)[uVar2 * 6];
  *(short *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar2 * 6] = sVar1 + 0x7fff;
  *(short *)(&PTR_ATUII_GR2A_W_0000d824)[uVar2 * 6] = sVar1 + -1;
  FUN_0000a8a4((&PTR_ATUII_DCNT8I_W_0000d81c)[uVar2 * 6]);
  (&DAT_ffffa0dd)[(uint)param_1 * 8] = 1;
  (&DAT_ffffa0de)[(uint)param_1 * 8] = 0;
  return;
}


