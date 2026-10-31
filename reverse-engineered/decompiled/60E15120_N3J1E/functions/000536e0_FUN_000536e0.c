/* ROM address: 0x000536e0; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051fbc (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000536e0(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd191 == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc2,0);
  }
  else if ((DAT_ffffc542 == '\x01') || (uVar1 = (uint)DAT_ffffc543, uVar1 == 1)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc2,1);
  }
  DAT_ffffd191 = cVar2;
  return uVar1;
}


