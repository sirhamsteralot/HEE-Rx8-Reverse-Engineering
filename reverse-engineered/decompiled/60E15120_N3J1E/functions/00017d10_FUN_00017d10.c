/* ROM address: 0x00017d10; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001890c (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00017d10(void)

{
  char cVar1;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8058,0);
  if ((((cVar1 != '\x01') &&
       (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805a,0), cVar1 != '\x01')) &&
      (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805c,0), cVar1 != '\x01')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805e,0), cVar1 != '\x01')) {
    DAT_ffffa914 = 0;
    return 0;
  }
  DAT_ffffa914 = 1;
  return 1;
}


