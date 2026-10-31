/* ROM address: 0x00055278; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000533cc (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00055278(void)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = ref_faultSomething0x2();
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd8,0);
  if (cVar2 == '\x01') {
    uVar1 = uVar1 | 0x80;
  }
  return uVar1;
}


