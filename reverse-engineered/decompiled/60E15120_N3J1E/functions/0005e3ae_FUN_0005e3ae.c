/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e3ae; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cbba (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e3ae(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float snapshot_vehicle_speed_ffffbbb4;
  
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&inferred_sensor_block_ffff9150_ffff9150);
  if (extraout_fr0 < snapshot_vehicle_speed_ffffbbb4) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_vehicle_speed_ffffbbb4,&inferred_sensor_block_ffff9150_ffff9150);
    return uVar1;
  }
  return uVar1;
}


