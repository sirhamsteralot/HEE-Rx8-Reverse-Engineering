/* ROM address: 0x00046e08; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045e94 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00046e08(void)

{
  undefined4 uVar1;
  char cVar4;
  uint uVar2;
  short sVar3;
  
  uVar1 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff8754,0);
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if (cVar4 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8750,0);
    uVar1 = 0;
  }
  else {
    cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8752,0);
    if (cVar4 == '\x01') {
      uVar1 = rx8_add_u16_saturate(uVar1,1);
    }
  }
  ref_updateMemoryAtAddress_16bit_ADDR_VAL(&DAT_ffff8754,uVar1);
  FUN_0000d2f6(0);
  uVar2 = FUN_0000d3b8();
  uVar2 = uVar2 & 0xff;
  if (uVar2 == 1) {
    sVar3 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff8754,0);
    if (sVar3 == 0) {
      sVar3 = -0x78ae;
    }
    else {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8752,0);
      sVar3 = -0x78b0;
    }
    uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL((int)sVar3,1);
  }
  else if (uVar2 == 0) {
    uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8752,0);
    DAT_ffffcc68 = 1;
  }
  return uVar2;
}


