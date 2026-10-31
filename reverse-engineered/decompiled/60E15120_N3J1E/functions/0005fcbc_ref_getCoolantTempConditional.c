/* ROM address: 0x0005fcbc; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e5c8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_getCoolantTempConditional(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0005fd30;
  if (inferred_coolant_temperature_ffffa98c < 71.0) {
    puVar1 = &DAT_0005fd34;
    if (inferred_coolant_temperature_ffffa98c < 66.0) {
      DAT_ffffd3bc = 0;
    }
  }
  else {
    DAT_ffffd3bc = 1;
  }
  return puVar1;
}


