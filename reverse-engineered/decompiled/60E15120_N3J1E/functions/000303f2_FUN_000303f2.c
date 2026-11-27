/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbe80 candidate_cranking_baro_factor (float): Altitude factor keyed on barometric pressure 0xffffad14 (descriptor 0x6ab14) by 0x303f2, 1.0 when the lookup is skipped; one of the five factors multiplied in 0x30228.
 */
/* ROM address: 0x000303f2; body bytes: 50; decompiled */

void FUN_000303f2(void)

{
  if (engine_running_ffffa428 == '\0') {
    if (DAT_ffffc590 == '\0') {
      candidate_cranking_baro_factor_ffffbe80 = lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&DAT_0006ab14);
    }
    else {
      candidate_cranking_baro_factor_ffffbe80 = 0x3f800000;
    }
  }
  return;
}


