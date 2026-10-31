/* ROM address: 0x00004f00; body bytes: 214; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004f00 (214 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004f00(void)

{
  byte bVar1;
  undefined4 local_c [2];
  
  ATUII_TSTR1_B = 0xff;
  ATUII_TSTR2_B = 0xff;
  ATUII_TSTR3_B = 1;
  ATUII_PSCR1_B = 4;
  ATUII_PSCR2_B = 4;
  ATUII_PSCR3_B = 4;
  ATUII_PSCR4_B = 4;
  ATUII_ITVRR1_B = 0;
  ATUII_ITVRR2A_B = 0;
  ATUII_ITVRR2B_B = 0;
  ATUII_TRGMDR_B = 0x80;
  ATUII_TMDR_B = 0;
  ATUII_TCR3_B = 4;
  ATUII_TCR4_W = 4;
  ATUII_TCR5_W = 4;
  ref_setSR_PARAM(local_c,0xe0);
  bVar1 = ATUII_TIOR3A_B;
  ATUII_TIOR3A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR3B_B;
  ATUII_TIOR3B_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR4A_B;
  ATUII_TIOR4A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR4B_B;
  ATUII_TIOR4B_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR5A_B;
  ATUII_TIOR5A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR5B_B;
  ATUII_TIOR5B_B = bVar1 & 0x77;
  FUN_00002064(local_c[0]);
  ATUII_TCR6A_B = 0x44;
  ATUII_TCR6B_B = 0x44;
  ATUII_PMDR6_B = 0;
  ATUII_TCR7A_B = 0x44;
  ATUII_TCR7B_B = 0x41;
  ATUII_TCR8_B = 0x44;
  ATUII_RLDENR_B = 0;
  ref_setSR_PARAM(local_c,0xe0);
  bVar1 = ATUII_TCR9A_B;
  ATUII_TCR9A_B = bVar1 & 0xbb;
  bVar1 = ATUII_TCR9B_B;
  ATUII_TCR9B_B = bVar1 & 0xbb;
  FUN_00002064(local_c[0]);
  ATUII_TCR11_B = 1;
  return;
}


