/* ROM address: 0x00045aec; body bytes: 42; decompiled */

uint FUN_00045aec(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if ((uVar1 & 0xff) == 1) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8730,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8732,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


