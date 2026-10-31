/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aeb8: Table 3D - 74 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006aed4: Table 3D - 75 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00032ee4; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033200 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_coolantTempSubtractorsForCatModel(void)

{
  undefined1 *puVar1;
  undefined4 snapshot_DAT_ffffade0;
  float snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  
  puVar1 = &engine_running_ffffa428;
  if (engine_running_ffffa428 == '\0') {
    snapshot_DAT_ffffade0 = DAT_ffffade0;
    snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
    DAT_ffffc020 = lookup_3d_descriptor_scaled(inferred_coolant_temperature_catalyst_temp_model_ffffa998,DAT_ffffade0,&tbl_table_3d_74_0006aeb8);
    DAT_ffffc024 = (float)lookup_3d_descriptor_scaled(snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998,snapshot_DAT_ffffade0,&tbl_table_3d_75_0006aed4);
    puVar1 = (undefined1 *)(uint)DAT_ffffce33;
    if (((puVar1 == (undefined1 *)0x1) && (0.0 <= snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998)) && (snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 <= 26.6)) {
      DAT_ffffc024 = DAT_ffffc024 * 0.75;
    }
  }
  return puVar1;
}


