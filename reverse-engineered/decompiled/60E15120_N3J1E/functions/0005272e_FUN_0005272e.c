/* ROM address: 0x0005272e; body bytes: 128; decompiled */

void FUN_0005272e(void)

{
  char cVar1;
  
  if (DAT_ffffd03d == '\x01') {
    DAT_ffffd119 = 0;
    DAT_ffffd11a = 0;
  }
  else if ((DAT_ffffd039 == '\x01') || (DAT_ffffcf78 == '\x01')) {
    cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86de,0);
    if ((cVar1 == '\x01') && (cVar1 = ref_getFaultStatus__(0x7a), cVar1 == '\0')) {
      DAT_ffffd119 = 1;
    }
    cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e0,0);
    if ((cVar1 == '\x01') && (cVar1 = ref_getFaultStatus__(0x7a), cVar1 == '\0')) {
      DAT_ffffd11a = 1;
    }
  }
  FUN_00052ee4();
  return;
}


