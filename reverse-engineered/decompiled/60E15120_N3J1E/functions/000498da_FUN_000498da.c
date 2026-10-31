/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000498da; body bytes: 138; decompiled */

undefined4 FUN_000498da(void)

{
  char cVar1;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  cVar1 = ref_getFaultStatus__(0x1e);
  if ((((((cVar1 != '\0') || (DAT_ffffcd32 < 0x20)) || (DAT_ffffcd20 != '\x01')) ||
       ((snapshot_engine_speed_rpm_ffffb548 < 500.0 || (5000.0 <= snapshot_engine_speed_rpm_ffffb548)))) ||
      ((snapshot_inferred_coolant_temperature_ffffa98c < 70.0 || ((120.0 <= snapshot_inferred_coolant_temperature_ffffa98c || (DAT_ffffad24 != '\x01')))))) || (DAT_ffffd1c5 != '\0'))
  {
    DAT_ffffcd34 = 0;
  }
  else {
    DAT_ffffcd34 = 1;
  }
  return 0;
}


