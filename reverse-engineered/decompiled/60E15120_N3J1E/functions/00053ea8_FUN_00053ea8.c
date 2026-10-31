/* ROM address: 0x00053ea8; body bytes: 96; decompiled */

uint FUN_00053ea8(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd1ab == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fdc,0);
  }
  else if ((DAT_ffffd1aa == '\x01') || (uVar1 = (uint)DAT_ffffd1a9, uVar1 == 1)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fdc,1);
  }
  DAT_ffffd1ab = cVar2;
  return uVar1;
}


