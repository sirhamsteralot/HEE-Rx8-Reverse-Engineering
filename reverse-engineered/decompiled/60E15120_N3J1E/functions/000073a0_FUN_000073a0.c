/* [ADDITIONAL SOURCE REVIEW]
 * clt_sensor_scaling_fault [high]: Same pattern vs tbl_clt_sensor_scaling_0006977c (descriptor @0x6977c verified; pool word 0x7420) -> coolant_temperature_ffff9f70; range fault 0xffff9f74 (raw<0x9ff->2, >=0xfd00->1). Called only from task[13] 0x65b2.
 * RAM 0xffff9f74 clt_range_fault (uint8): 0 = in band, 1 = raw >= 0xfd00, 2 = raw < 0x9ff; set in clt_sensor_scaling_fault 0x73a0 (task[13]).
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006977c: CLT Sensor Scaling (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000073a0; body bytes: 104; decompiled */

undefined2 * clt_sensor_scaling_fault(void)

{
  undefined4 uVar1;
  
  DAT_ffff9f76 = rx8_blend_s32_u16_weight_over_256(DAT_ffff9f1c,DAT_ffff9f76,0x100);
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)(short)DAT_ffff9f76);
  coolant_temperature_ffff9f70 = lookup_2d_descriptor_scaled(uVar1,&tbl_clt_sensor_scaling_0006977c);
  if (DAT_ffff9f76 < 0xfd00) {
    if (DAT_ffff9f76 < 0x9ff) {
      clt_range_fault_ffff9f74 = 2;
    }
    else {
      clt_range_fault_ffff9f74 = 0;
    }
  }
  else {
    clt_range_fault_ffff9f74 = 1;
  }
  return &DAT_0006c152;
}


