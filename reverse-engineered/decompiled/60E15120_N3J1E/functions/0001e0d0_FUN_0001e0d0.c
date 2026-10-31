/* ROM address: 0x0001e0d0; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001eb30 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001e0d0(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  bVar1 = 0;
  puVar3 = &DAT_ffff80e4;
  puVar2 = &DAT_ffff80c4;
  do {
    ref_validateAddressCopy_float_ADDRESS__(puVar2);
    ref_validateAddressCopy_8bit_ADDRESS__(puVar3);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 2;
    puVar2 = puVar2 + 8;
  } while (bVar1 < 4);
  return;
}


