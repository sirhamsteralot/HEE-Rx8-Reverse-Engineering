/* ROM address: 0x00045fd6; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045062 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00045fd6(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = ref_getFaultStatus__(0x85);
  if ((((cVar1 == '\0') && (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8738,0), cVar1 == '\0'))
      && (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0), cVar1 == '\0')) &&
     (DAT_ffffbd48 == '\x01')) {
    DAT_ffffcc0c = 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    DAT_ffffcc0c = 0;
  }
  return uVar2;
}


