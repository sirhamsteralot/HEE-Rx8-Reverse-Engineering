/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e3d8; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cbe4 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e3d8(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff9158);
  if (extraout_fr0 < snapshot_inferred_coolant_temperature_ffffa98c) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_ffff9158);
    return uVar1;
  }
  return uVar1;
}


