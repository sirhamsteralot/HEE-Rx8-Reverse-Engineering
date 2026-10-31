/* ROM address: 0x00017d70; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001896c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00017d70(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8058,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805a,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805c,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805e,0);
  }
  return uVar1;
}


