/* ROM address: 0x000540d2; body bytes: 178; decompiled */

undefined4 FUN_000540d2(void)

{
  char cVar1;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
  if ((((((cVar1 == '\0') &&
         (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0), cVar1 == '\0')) &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0), cVar1 == '\0')) &&
       ((cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d6,0), cVar1 == '\0' &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d8,0), cVar1 == '\0')))) &&
      ((cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c8,0), cVar1 == '\0' &&
       ((cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ca,0), cVar1 == '\0' &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ce,0), cVar1 == '\0')))))) &&
     ((cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86de,0), cVar1 == '\0' &&
      (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d2,0), cVar1 == '\0')))) {
    DAT_ffffd1b0 = 0;
    return 0;
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffd1b0 = 0;
    return 1;
  }
  DAT_ffffd1b0 = 1;
  return 1;
}


