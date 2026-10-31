/* ROM address: 0x00047570; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000465fc (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00047570(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff875e,0);
  if (cVar2 == '\x01') {
    FUN_0005fd96();
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff875e,0);
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if ((cVar2 == '\x01') &&
     (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff875c,0), cVar2 == '\x01')) {
    DAT_ffffcca4 = 1;
  }
  if (DAT_ffffcca4 == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff875c,0);
    return uVar1;
  }
  return (uint)DAT_ffffcca4;
}


