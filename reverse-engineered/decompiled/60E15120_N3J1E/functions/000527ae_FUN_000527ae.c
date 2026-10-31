/* ROM address: 0x000527ae; body bytes: 136; decompiled */

char FUN_000527ae(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffd10e = 0;
  }
  else {
    cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86de,0);
    if (cVar1 != '\x01') {
      cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c8,0);
      if (cVar1 != '\x01') {
        cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ca,0);
        if (cVar1 != '\x01') {
          cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ce,0);
          if (cVar1 != '\x01') {
            cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d2,0);
            if (cVar1 != '\x01') {
              cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d6,0);
              if (cVar1 != '\x01') {
                cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d8,0);
                if (cVar1 != '\x01') {
                  return cVar1;
                }
              }
            }
          }
        }
      }
    }
    DAT_ffffd10e = 1;
  }
  return '\x01';
}


