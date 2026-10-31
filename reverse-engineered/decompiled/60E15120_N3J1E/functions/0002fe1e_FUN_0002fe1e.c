/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aa0c: Injector Manifold Vacuum Multiplier (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002fe1e; body bytes: 48; decompiled */

void FUN_0002fe1e(void)

{
  DAT_ffffbe0c = lookup_2d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe04,&tbl_injector_manifold_vacuum_multiplier_0006aa0c);
  DAT_ffffbe10 = lookup_2d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe08,&DAT_0006aa20);
  DAT_ffffbe14 = lookup_2d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe08,&DAT_0006aa34);
  return;
}


