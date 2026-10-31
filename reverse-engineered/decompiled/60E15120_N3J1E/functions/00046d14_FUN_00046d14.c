/* ROM address: 0x00046d14; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045da0 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00046d14(void)

{
  short sVar2;
  undefined4 uVar1;
  
  if (DAT_ffffa3f0 == '\0') {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff874a,0);
    DAT_ffffcc64 = 1;
  }
  else {
    sVar2 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff874c,0);
    if (sVar2 == 0) {
      sVar2 = -0x78b6;
    }
    else {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff874a,0);
      sVar2 = -0x78b8;
    }
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL((int)sVar2,1);
  }
  return uVar1;
}


