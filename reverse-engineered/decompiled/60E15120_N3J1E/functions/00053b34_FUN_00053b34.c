/* ROM address: 0x00053b34; body bytes: 212; decompiled */

uint FUN_00053b34(void)

{
  uint uVar1;
  char cVar2;
  
  if (DAT_ffffd1c5 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd2,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd4,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd0,0);
    return uVar1;
  }
  if (DAT_ffffd045 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd2,0);
  }
  else if (DAT_ffffd046 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd2,1);
  }
  if (DAT_ffffd0f4 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd4,0);
  }
  else if (DAT_ffffd0f5 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd4,1);
  }
  cVar2 = FUN_0005f9f0(0x2c,0);
  if (((cVar2 != '\x01') && (cVar2 = FUN_0005f9f0(0x2d,0), cVar2 != '\x01')) &&
     (cVar2 = FUN_0005f9f0(0x30,0), cVar2 != '\x01')) {
    uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd2,0);
    if ((uVar1 & 0xff) != 1) {
      return uVar1 & 0xff;
    }
    uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd4,0);
    if ((uVar1 & 0xff) != 1) {
      return uVar1 & 0xff;
    }
  }
  uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd0,1);
  return uVar1;
}


