/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00056428; body bytes: 100; decompiled */

undefined4 FUN_00056428(void)

{
  ushort uVar1;
  undefined4 uVar2;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_inferred_battery_voltage_ffffb590;
  
  uVar2 = 0;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_inferred_battery_voltage_ffffb590 = inferred_battery_voltage_ffffb590;
  uVar1 = FUN_00001008();
  if (uVar1 < 100) {
    if (((snapshot_inferred_battery_voltage_ffffb590 <= 8.0) || (16.5 <= snapshot_inferred_battery_voltage_ffffb590)) ||
       ((DAT_ffffc5e6 == '\0' && ((snapshot_inferred_coolant_temperature_ffffa98c <= -40.0 || (120.0 <= snapshot_inferred_coolant_temperature_ffffa98c)))))) {
      uVar2 = 0x22;
    }
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}


