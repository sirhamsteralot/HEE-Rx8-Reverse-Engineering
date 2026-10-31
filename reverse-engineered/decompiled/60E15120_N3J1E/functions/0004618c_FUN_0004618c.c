/* ROM address: 0x0004618c; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045218 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004618c(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if ((uVar1 & 0xff) == 1) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff873c,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff873e,1);
    return uVar1;
  }
  return uVar1 & 0xff;
}


