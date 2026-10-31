/* ROM address: 0x00051474; body bytes: 84; decompiled */

char FUN_00051474(void)

{
  char cVar1;
  
  if ((((DAT_ffffd0f6 == '\x01') && (DAT_ffffd0f7 == '\0')) && (DAT_ffffd0f8 == '\x01')) &&
     (DAT_ffffd0f9 == '\0')) {
    cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c4,0x17);
    if (cVar1 != '\0') {
      DAT_ffffd0f1 = 1;
      return cVar1;
    }
  }
  DAT_ffffd0f1 = 0;
  return '\0';
}


