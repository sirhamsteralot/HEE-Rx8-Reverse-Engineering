/* ROM address: 0x000618ba; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000601aa (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000618ba(void)

{
  int iVar1;
  
  iVar1 = (int)DAT_ffff8784._0_2_;
  if (DAT_ffff8784._0_2_ != -1) {
    iVar1 = iVar1 + 1;
  }
  DAT_ffff8784 = rx8_pack_u16_with_complement(iVar1);
  return;
}


