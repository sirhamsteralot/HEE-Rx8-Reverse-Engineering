/* ROM address: 0x0001e088; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001eae8 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001e088(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  bVar1 = 0;
  puVar3 = &DAT_ffff80e4;
  puVar2 = &DAT_ffff80c4;
  uVar4 = 0;
  do {
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,puVar2);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(puVar3,0);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 2;
    puVar2 = puVar2 + 8;
  } while (bVar1 < 4);
  return;
}


