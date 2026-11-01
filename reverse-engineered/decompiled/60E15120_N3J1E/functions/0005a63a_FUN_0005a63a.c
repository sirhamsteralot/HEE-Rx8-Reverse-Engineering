/* ROM address: 0x0005a63a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058df2 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005a63a(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_ffff9110;
  do {
    uVar1 = ref_validateAddressCopy_32bit_ADDRESS__(puVar2);
    puVar2 = puVar2 + 8;
  } while (puVar2 < &inferred_sensor_block_ffff9150_ffff9150);
  return uVar1;
}


