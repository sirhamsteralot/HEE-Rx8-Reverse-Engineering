/* ROM address: 0x0000b23c; body bytes: 84; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000b25e) */
/* Unique exact-byte match to related 60E0FC00 function at 0000b23c (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b23c(void)

{
  byte bVar1;
  undefined4 local_10 [2];
  
  DAT_ffffa214 = 0;
  DAT_ffffa210 = 0;
  ref_setSR_PARAM(local_10,0xe0);
  bVar1 = ATUII_TSTR2_B;
  ATUII_TSTR2_B = bVar1 & 0x7f;
  ATUII_CYLR7D_W = 1;
  ATUII_TCNT7D_W = 1;
  ATUII_BFR7D_W = 1;
  ATUII_DTR7D_W = 1;
  ATUII_BFR7D_W = 0;
  bVar1 = ATUII_TSTR2_B;
  ATUII_TSTR2_B = bVar1 | 0x80;
  FUN_00002064(local_10[0]);
  return;
}


