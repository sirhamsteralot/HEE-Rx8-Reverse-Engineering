/* ROM address: 0x00046cc4; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00045d50 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00046cc4(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff874c,0);
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if (cVar2 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8748,0);
    uVar1 = 0;
  }
  else {
    cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff874a,0);
    if (cVar2 == '\x01') {
      uVar1 = rx8_add_u16_saturate(uVar1,1);
    }
  }
  ref_updateMemoryAtAddress_16bit_ADDR_VAL(&DAT_ffff874c,uVar1);
  return;
}


