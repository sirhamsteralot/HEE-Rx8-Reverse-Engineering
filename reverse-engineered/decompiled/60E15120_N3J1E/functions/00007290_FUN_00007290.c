/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069824: IAT Sensor Scaling (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00007290; body bytes: 8; decompiled */

undefined2 * FUN_00007290(void)

{
  undefined4 uVar1;
  
  DAT_ffff9f66 = DAT_ffff9f1e;
  DAT_ffff9f66 = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f1e,DAT_ffff9f1e,0x100);
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


