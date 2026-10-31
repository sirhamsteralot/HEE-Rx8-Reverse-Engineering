/* ROM address: 0x000504e0; body bytes: 194; decompiled */

uint FUN_000504e0(void)

{
  char cVar1;
  uint uVar2;
  
  if ((DAT_ffffd039 == '\x01') || (DAT_ffffcf78 == '\x01')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  if (DAT_ffffd03e == '\x01') {
    DAT_ffffd045 = 0;
  }
  else if (((uVar2 == 1) &&
           (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0), cVar1 == '\x01')) &&
          (cVar1 = ref_getFaultStatus__(0x2e), cVar1 == '\0')) {
    DAT_ffffd045 = 1;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a4,0);
  }
  if (DAT_ffffd03d == '\x01') {
    DAT_ffffd046 = 0;
    uVar2 = 1;
  }
  else if (uVar2 == 1) {
    uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      uVar2 = ref_getFaultStatus__(0x2e);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        DAT_ffffd046 = 1;
        uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a6,0);
        return uVar2;
      }
    }
  }
  return uVar2;
}


