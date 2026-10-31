/* ROM address: 0x00053c88; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051d9c (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00053c88(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd8,0);
  if (((cVar1 == '\0') && (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8660,0), cVar1 == '\0'))
     || (DAT_ffffd1c5 == '\x01')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fda,uVar2);
  return;
}


