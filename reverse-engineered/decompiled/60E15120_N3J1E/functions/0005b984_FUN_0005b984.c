/* ROM address: 0x0005b984; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a174 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005b984(void)

{
  int iVar1;
  
  if ((0x8000007f < DAT_ffffd2f4) && (DAT_ffffd2f4 < 0x80000100)) {
    iVar1 = FUN_00037fd4();
    DAT_ffffd2f4 = iVar1 + DAT_ffffd2f4 + 0x80000000;
    DAT_ffffd2f8 = DAT_ffffd2fc + DAT_ffffd2f4;
  }
  return;
}


