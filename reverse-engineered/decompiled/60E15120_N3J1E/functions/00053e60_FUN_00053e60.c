/* ROM address: 0x00053e60; body bytes: 56; decompiled */

uint FUN_00053e60(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fde,0);
    return uVar1;
  }
  if ((DAT_ffffd1a8 != '\x01') && (DAT_ffffd1a9 != 1)) {
    return (uint)DAT_ffffd1a9;
  }
  uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fde,1);
  return uVar1;
}


