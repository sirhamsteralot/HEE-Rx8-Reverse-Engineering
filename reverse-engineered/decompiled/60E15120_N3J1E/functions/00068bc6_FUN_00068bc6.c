/* ROM address: 0x00068bc6; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000674b6 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068bc6(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = ATUII_TCNT0H_W;
  (&DAT_ffffde04)[param_1 & 0xff] = param_2 * 4000 + iVar1;
  (&DAT_ffffddfc)[param_1 & 0xff] = 1;
  return;
}


