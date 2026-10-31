/* ROM address: 0x000545dc; body bytes: 96; decompiled */

uint FUN_000545dc(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd1bf == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fe0,0);
  }
  else if ((DAT_ffffd1bc == '\x01') || (uVar1 = (uint)DAT_ffffd1bd, uVar1 == 1)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fe0,1);
  }
  DAT_ffffd1bf = cVar2;
  return uVar1;
}


