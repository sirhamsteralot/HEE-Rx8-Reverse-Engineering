/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a9a4: Primary Injector Weighted Engine Temp Multiplier (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a9c0: Secondary 1 Injector Weighted Engine Temp Multiplier (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a9dc: Secondary 2 Injector Weighted Engine Temp Multiplier (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * injector_temp_multiplier_lookup [high]: bde4/bde8/bdec = 3D weighted-engine-temp x load multipliers for primary / secondary-1 / secondary-2 injectors (tbls 0x6a9a4/0x6a9c0/0x6a9dc); consumed by calculate_fuel_amount_per_rotation (0x30948).
 */
/* ROM address: 0x0002fd3e; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000301f6 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void injector_temp_multiplier_lookup(void)

{
  DAT_ffffbde4 = lookup_3d_descriptor_scaled(inferred_weighted_engine_temperature_ffffbdf0,engine_load_ffffc0b4,&tbl_primary_injector_weighted_engine_temp_multiplier_0006a9a4);
  DAT_ffffbde8 = lookup_3d_descriptor_scaled(DAT_ffffbdf4,engine_load_ffffc0b4,&tbl_secondary_1_injector_weighted_engine_temp_multiplier_0006a9c0);
  DAT_ffffbdec = lookup_3d_descriptor_scaled(DAT_ffffbdf8,engine_load_ffffc0b4,&tbl_secondary_2_injector_weighted_engine_temp_multiplier_0006a9dc);
  return;
}


