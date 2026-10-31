/* ROM address: 0x000458e8; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00044974 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000458e8(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff872c,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


