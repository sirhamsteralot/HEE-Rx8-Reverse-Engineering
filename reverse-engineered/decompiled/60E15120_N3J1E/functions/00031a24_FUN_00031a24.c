/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ad6c: Table 2D - 194 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ad80: Table 2D - 195 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00031a24; body bytes: 332; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00031b8c) */
/* WARNING: Removing unreachable block (ram,0x00031abc) */

void FUN_00031a24(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float snapshot_intake_air_temperature_ffffaddc;
  float snapshot_engine_load_ffffc0b4;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar1 = engine_stopped_latch_ffffa41c;
  snapshot_intake_air_temperature_ffffaddc = intake_air_temperature_ffffaddc;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  fVar3 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_194_0006ad6c);
  fVar4 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_table_2d_195_0006ad80);
  DAT_ffffbf78 = fVar3 + fVar4;
  if (snapshot_engine_load_ffffc0b4 <= DAT_ffffbf78) {
    if (snapshot_engine_load_ffffc0b4 <= DAT_ffffbf78 - 0.05) {
      DAT_ffffbf7d = '\0';
    }
  }
  else {
    DAT_ffffbf7d = '\x01';
  }
  if ((DAT_ffffbf80 == '\x01') && (cVar1 == '\0')) {
    DAT_ffffbf7c = '\x06';
    DAT_ffffbf81 = '\x01';
  }
  else if (DAT_ffffbf7c != '\0') {
    DAT_ffffbf7c = DAT_ffffbf7c + -1;
  }
  if ((DAT_ffffd26e == '\x01') ||
     ((((((DAT_ffffc5e6 == '\0' && (DAT_ffffbf7d == '\0')) && (DAT_ffffbf70 != 0)) &&
        ((snapshot_inferred_coolant_temperature_ffffa98c <= 35.0 || (DAT_ffffaa81 == '\0')))) &&
       ((-15.0 <= snapshot_intake_air_temperature_ffffaddc && ((snapshot_intake_air_temperature_ffffaddc <= 40.0 && (cVar1 == '\0')))))) &&
      ((DAT_ffffbf81 == '\x01' && (DAT_ffffbf7c == '\0')))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  secondary_air_pump_request_ffffbf6c = FUN_0005cea0(uVar2);
  DAT_ffffbf80 = cVar1;
  return;
}


