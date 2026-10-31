/* ROM address: 0x00052ee4; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050e68 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00052ee4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ref_getKnownBooleanValue__();
  uVar2 = uVar1;
  if ((DAT_ffffd136 == '\0') && (uVar2 = uVar1 & 0xff, uVar2 == 1)) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86de,0);
    uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e0,0);
  }
  DAT_ffffd136 = (char)uVar1;
  return uVar2;
}


