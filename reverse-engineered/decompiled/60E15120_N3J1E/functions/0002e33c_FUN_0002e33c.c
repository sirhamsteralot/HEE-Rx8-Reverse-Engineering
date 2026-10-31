/* ROM address: 0x0002e33c; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002e8c0 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002e33c(void)

{
  char cVar1;
  
  if ((((((DAT_ffffcca1 != '\x01') && (DAT_ffffbcd8 != '\x01')) && (DAT_ffffbd58 != '\x01')) &&
       ((DAT_ffffb516 != '\x01' &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8738,0), cVar1 != '\x01')))) &&
      ((DAT_ffffbbb9 != '\x01' && ((DAT_ffffbbba != '\x01' && (DAT_ffffbbd0 != '\x01')))))) &&
     (DAT_ffffc616 != '\x01')) {
    DAT_ffffbd5c = 0;
    return 0;
  }
  DAT_ffffbd5c = 1;
  return 1;
}


