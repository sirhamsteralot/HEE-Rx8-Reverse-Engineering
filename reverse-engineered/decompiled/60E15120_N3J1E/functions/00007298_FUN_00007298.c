/* [ADDITIONAL SOURCE REVIEW]
 * iat_sensor_scaling_fault [high]: Blend DAT_ffff9f66 <- DAT_ffff9f1e (weight 0x100/256, 0x2510), affine decode 0x38a00000 (0x24c0), lookup_2d_descriptor_scaled vs tbl_iat_sensor_scaling_00069824 (descriptor bytes @0x69824 verified; pool word 0x731c) -> intake_air_temperature_ffff9f60; range fault 0xffff9f64 (raw<0x51e->2, >=0xf6c9->1).
 * RAM 0xffff9f64 iat_range_fault (uint8): 0 = in band, 1 = raw >= 0xf6c9, 2 = raw < 0x51e; set in iat_sensor_scaling_fault 0x7298 (task[13]).
 */
/* ROM address: 0x00007298; body bytes: 104; decompiled */

undefined2 * iat_sensor_scaling_fault(void)

{
  undefined4 uVar1;
  
  DAT_ffff9f66 = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f1e,DAT_ffff9f66,0x100);
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)(short)DAT_ffff9f66);
  intake_air_temperature_ffff9f60 = lookup_2d_descriptor_scaled(uVar1,&tbl_iat_sensor_scaling_00069824);
  if (DAT_ffff9f66 < 0xf6c9) {
    if (DAT_ffff9f66 < 0x51e) {
      iat_range_fault_ffff9f64 = 2;
    }
    else {
      iat_range_fault_ffff9f64 = 0;
    }
  }
  else {
    iat_range_fault_ffff9f64 = 1;
  }
  return &DAT_0006c146;
}


