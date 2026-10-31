/* ROM address: 0x0003583c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035f5c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003583c(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff8674,0);
  iVar1 = ATUII_TCNT0H_W;
  ref_updateMemoryAtAddress_32bit_ADDR_VAL(&DAT_ffff8674,iVar1 + iVar2);
  return;
}


