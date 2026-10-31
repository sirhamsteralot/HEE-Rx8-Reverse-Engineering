/* ROM address: 0x000552ac; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053400 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_000552ac(void)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fc4,0);
  bVar2 = cVar1 == '\0';
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd0,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 4;
  }
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fc0,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 8;
  }
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fc8,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 0x20;
  }
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fde,0);
  if (cVar1 == '\0') {
    bVar2 = bVar2 + 0x40;
  }
  return bVar2 & DAT_ffffd289;
}


