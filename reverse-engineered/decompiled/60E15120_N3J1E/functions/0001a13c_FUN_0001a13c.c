/* [MATH AND UNITS REVIEW]
 * Multiplication by engine_speed_rpm/60 changes a per-revolution quantity into per-second. Remaining factor 0.04*x+0.26 has unresolved units, so the output is not assigned a complete physical unit.
 */
/* ROM address: 0x0001a13c; body bytes: 36; decompiled */

void FUN_0001a13c(void)

{
  DAT_ffffaa28 = ((inferred_ram_ad48_ffffad48_ffffad48 * 0.04 - -0.26) * engine_speed_rpm_ffffb548) / 60.0;
  return;
}


