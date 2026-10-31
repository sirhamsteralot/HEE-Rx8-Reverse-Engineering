/* ROM address: 0x0005381c; body bytes: 96; decompiled */

uint FUN_0005381c(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd195 == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc6,0);
  }
  else if ((DAT_ffffcacb == '\x01') || (uVar1 = (uint)DAT_ffffcaca, uVar1 == 1)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc6,1);
  }
  DAT_ffffd195 = cVar2;
  return uVar1;
}


