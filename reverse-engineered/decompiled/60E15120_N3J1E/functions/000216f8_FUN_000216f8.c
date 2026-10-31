/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a218: Table 2D - 121 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a22c: Table 2D - 122 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a240: Table 2D - 123 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000216f8; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022064 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000216f8(void)

{
  float arg0;
  undefined4 snapshot_inferred_coolant_temperature_ffffa990;
  
  snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
  arg0 = (float)lookup_2d_descriptor_scaled(DAT_ffffa838,&tbl_table_2d_121_0006a218);
  DAT_ffffb2a8 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_123_0006a240);
  DAT_ffffb2ac = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_122_0006a22c);
  DAT_ffffb2a4 = rx8_clamp_float(arg0,DAT_ffffb2a8,DAT_ffffb2ac);
  return;
}


