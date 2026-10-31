/* ROM address: 0x00046fae; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004603a (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00046fae(void)

{
  char cVar1;
  
  if (((DAT_ffffccc4 == '\x01') && (cVar1 = ref_getFaultStatus__(0x5e), cVar1 == '\0')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8758,0), cVar1 == '\0')) {
    DAT_ffffcc6c = 1;
    return 0;
  }
  DAT_ffffcc6c = 0;
  return 0;
}


