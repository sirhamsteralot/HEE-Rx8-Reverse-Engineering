/* [ADDITIONAL SOURCE REVIEW]
 * candidate_cranking_throttle_factor [high]: Returns immediately while 0xffffa428 != 0 (pool 0x3042c). With coolant 0xffffa98c (pool 0x3042e) below f32 0x77f6c = 150.0 (pool 0x30458, fcmp/gt at 0x303bc) the factor 0xffffbe68 (pool 0x30434) is the scaled lookup of throttle position 0xffffad44 (pool 0x30436) against descriptor 0x6ab00 (pool 0x3045c, scale f32 0x6ab0c = 1/128: 128 -> 1.0, 0 -> 0.0); at 150 degC and above it is 1.0 unless the neighbour flags 0xffffc5e6 (pool 0x30430) or 0xffffb423 (pool 0x30432) are set.
 * RAM 0xffffbe68 candidate_cranking_throttle_factor (float): Throttle-position factor of the cranking pulse: 1.0 below 21.02 % and 0.0 above 22.52 % (descriptor 0x6ab00, data 128/0 with scale 1/128), 1.0 for hot coolant unless the neighbour flags are set (0x303a8).
 */
/* ROM address: 0x000303a8; body bytes: 74; decompiled */

void candidate_cranking_throttle_factor(void)

{
  if (engine_running_ffffa428 == '\0') {
    if (((inferred_coolant_temperature_ffffa98c < 150.0) || (DAT_ffffc5e6 != '\0')) || (DAT_ffffb423 != '\0')) {
      candidate_cranking_throttle_factor_ffffbe68 = lookup_2d_descriptor_scaled(inferred_throttle_position_ffffad44,&DAT_0006ab00);
    }
    else {
      candidate_cranking_throttle_factor_ffffbe68 = 0x3f800000;
    }
  }
  return;
}


