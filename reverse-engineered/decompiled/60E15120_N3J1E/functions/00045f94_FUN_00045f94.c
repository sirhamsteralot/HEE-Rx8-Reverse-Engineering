/* ROM address: 0x00045f94; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045020 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00045f94(void)

{
  uint uVar1;
  
  DAT_ffffcc12 = inferred_ram_ad18_ffffad18_ffffad18;
  DAT_ffffcc13 = stored_dtc_flag_bits_ffffb4ec;
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8738,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


