/* ROM address: 0x000537d4; body bytes: 56; decompiled */

uint FUN_000537d4(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc4,0);
    return uVar1;
  }
  if ((DAT_ffffd194 != '\x01') && (DAT_ffffcaca != 1)) {
    return (uint)DAT_ffffcaca;
  }
  uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc4,1);
  return uVar1;
}


