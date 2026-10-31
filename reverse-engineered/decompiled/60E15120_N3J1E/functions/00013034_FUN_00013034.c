/* [ADDITIONAL SOURCE REVIEW]
 * knock_rough_correction_targets [high]: a6bc/a6c0 rough-knock correction targets from RX8Defs 'Ignition 4..17' descriptors 0x69630-0x6974c.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069630: Ignition 4 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069644: Ignition 5 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069658: Ignition 6 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006966c: Ignition 7 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069680: Ignition 8 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069694: Ignition 9 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000696a8: Ignition 10 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000696bc: Ignition 11 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000696d0: Ignition 12 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000696e4: Ignition 13 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000696f8: Ignition 14 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069714: Ignition 15 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069730: Ignition 16 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006974c: Ignition 17 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00013034; body bytes: 340; decompiled */

uint knock_rough_correction_targets(void)

{
  char cVar1;
  uint uVar2;
  float *pfVar3;
  undefined *puVar4;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float extraout_fr0;
  undefined4 snapshot_inferred_barometric_pressure_ffffad14;
  undefined4 snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  undefined4 snapshot_engine_load_ffffc0b4;
  undefined4 snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar1 = engine_running_ffffa428;
  pcVar5 = lookup_2d_descriptor_scaled;
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  snapshot_inferred_barometric_pressure_ffffad14 = inferred_barometric_pressure_ffffad14;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if ((DAT_ffffa6df == '\0') && (engine_running_ffffa428 == '\x01')) {
    snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
    DAT_ffffa6c4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_ignition_12_000696d0);
    DAT_ffffa6c8 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_ignition_13_000696e4);
  }
  else {
    if (DAT_ffffaa62 == '\x01') {
      pfVar3 = (float *)&DAT_0006ebc0;
    }
    else {
      pfVar3 = (float *)&DAT_0006ebc8;
    }
    fVar6 = *pfVar3 + DAT_ffffa6c8;
    DAT_ffffa6c4 = rx8_min_float(DAT_ffffa6c4 + 0.0,0.0);
    DAT_ffffa6c8 = rx8_min_float(fVar6,0.0);
  }
  if (DAT_ffffa6b9 == '\x01') {
    pcVar5 = lookup_3d_descriptor_scaled;
    fVar6 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,snapshot_engine_load_ffffc0b4,&tbl_ignition_14_000696f8);
    fVar7 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,snapshot_engine_load_ffffc0b4,&tbl_ignition_15_00069714);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,snapshot_engine_load_ffffc0b4,&tbl_ignition_16_00069730);
    puVar4 = &tbl_ignition_17_0006974c;
  }
  else if (DAT_ffffa6b7 == '\x01') {
    fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_ignition_4_00069630);
    fVar7 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_ignition_5_00069644);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_ignition_6_00069658);
    puVar4 = &tbl_ignition_7_0006966c;
  }
  else {
    if (DAT_ffffa6b8 != 1) {
      DAT_ffffa6bc = DAT_ffffa6c4;
      DAT_ffffa6c0 = DAT_ffffa6c8;
      DAT_ffffa6df = cVar1;
      return (uint)DAT_ffffa6b8;
    }
    fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_ignition_8_00069680);
    fVar7 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_barometric_pressure_ffffad14,&tbl_ignition_9_00069694);
    DAT_ffffa6bc = fVar6 + fVar7;
    fVar6 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_ignition_10_000696a8);
    puVar4 = &tbl_ignition_11_000696bc;
  }
  uVar2 = (*pcVar5)(snapshot_inferred_barometric_pressure_ffffad14,puVar4);
  DAT_ffffa6c0 = fVar6 + extraout_fr0;
  DAT_ffffa6df = cVar1;
  return uVar2;
}


