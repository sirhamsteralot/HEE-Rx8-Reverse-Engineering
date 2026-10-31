/* ROM address: 0x0002cf48; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d5ec (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0002cf48(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8668,1);
    return uVar1;
  }
  return uVar1 & 0xff;
}


