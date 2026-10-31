/* ROM address: 0x00053994; body bytes: 134; decompiled */

uint FUN_00053994(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd19d == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fca,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fcc,0);
  }
  else {
    if ((DAT_ffffc703 == '\x01') || (DAT_ffffc702 == '\x01')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fca,1);
    }
    if ((DAT_ffffcd15 == '\x01') || (uVar1 = (uint)DAT_ffffcd14, uVar1 == 1)) {
      uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fcc,1);
    }
  }
  DAT_ffffd19d = cVar2;
  return uVar1;
}


