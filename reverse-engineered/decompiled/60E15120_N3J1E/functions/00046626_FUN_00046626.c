/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00046626; body bytes: 274; decompiled */

uint FUN_00046626(void)

{
  uint uVar1;
  float snapshot_DAT_ffffade0;
  float snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  
  if (inferred_barometric_pressure_ffffad14 < 72.2) {
    if (inferred_barometric_pressure_ffffad14 < 70.7) {
      DAT_ffffcc58 = 0;
    }
  }
  else {
    DAT_ffffcc58 = 1;
  }
  if (intake_air_temperature_ffffaddc < -10.0) {
    if (intake_air_temperature_ffffaddc < -10.0) {
      DAT_ffffcc59 = 0;
    }
  }
  else {
    DAT_ffffcc59 = 1;
  }
  snapshot_DAT_ffffade0 = DAT_ffffade0;
  snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  uVar1 = ref_getFaultStatus__(0x3c);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    uVar1 = ref_getFaultStatus__(0x3d);
    uVar1 = uVar1 & 0xff;
    if (((uVar1 == 0) &&
        ((((130.0 <= snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 && (130.0 <= snapshot_DAT_ffffade0)) || (snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 < 130.0)) || (snapshot_DAT_ffffade0 < 130.0)))) &&
       ((((uVar1 = (uint)DAT_ffffcc58, uVar1 == 1 && (uVar1 = (uint)DAT_ffffcc59, uVar1 == 1)) &&
         (uVar1 = (uint)DAT_ffffa7b4, uVar1 == 1)) &&
        ((vehicle_speed_ffffbbb4 == 0.0 && (uVar1 = (uint)DAT_ffffd1c5, uVar1 == 0)))))) {
      DAT_ffffcc48 = 1;
      return 0;
    }
  }
  DAT_ffffcc48 = 0;
  return uVar1;
}


