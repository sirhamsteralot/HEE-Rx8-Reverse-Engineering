/* ROM address: 0x00050250; body bytes: 146; decompiled */

uint FUN_00050250(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_ffffd03d == '\x01') {
    DAT_ffffd042 = 0;
    DAT_ffffd043 = 0;
    uVar1 = 1;
  }
  else if ((DAT_ffffd039 == '\x01') || (uVar1 = (uint)DAT_ffffcf78, uVar1 == 1)) {
    cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
    if ((cVar2 == '\x01') && (cVar2 = ref_getFaultStatus__(0x31), cVar2 == '\0')) {
      DAT_ffffd042 = 1;
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a0,0);
    }
    uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a2,0);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 1) {
      uVar1 = ref_getFaultStatus__(0x31);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        DAT_ffffd043 = 1;
        uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a2,0);
        return uVar1;
      }
    }
  }
  return uVar1;
}


