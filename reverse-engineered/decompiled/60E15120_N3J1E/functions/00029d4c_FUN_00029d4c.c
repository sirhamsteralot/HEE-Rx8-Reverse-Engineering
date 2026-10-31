/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a458: Throttle Pedal to Throttle Plate Request - Gear 1/2 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a474: Throttle Pedal to Throttle Plate Request - Gear Neutral (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a490: Throttle Pedal to Throttle Plate Request - Gear 5/6 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4ac: Throttle Pedal to Throttle Plate Request - Gear 3/4 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00029d4c; body bytes: 232; decompiled */

undefined4 FUN_00029d4c(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined *puVar3;
  float arg0;
  float arg1;
  
  if (DAT_ffffbaef == '\0') {
    DAT_ffffbb50 = engine_speed_rpm_ffffb548;
  }
  if (DAT_ffffb2cc == '\x01') {
    puVar3 = &tbl_throttle_pedal_to_throttle_plate_request_gear_1_2_0006a458;
  }
  else {
    if (DAT_ffffb2cd != '\x01') {
      if (DAT_ffffb2ce == '\x01') {
        puVar3 = &tbl_throttle_pedal_to_throttle_plate_request_gear_5_6_0006a490;
      }
      else {
        puVar3 = &tbl_throttle_pedal_to_throttle_plate_request_gear_3_4_0006a4ac;
      }
      arg0 = (float)lookup_3d_descriptor_scaled(DAT_ffffbb50,DAT_ffffa9bc,puVar3);
      goto LAB_00029df4;
    }
    puVar3 = &tbl_throttle_pedal_to_throttle_plate_request_gear_neutral_0006a474;
  }
  arg0 = (float)lookup_3d_descriptor_scaled(DAT_ffffbb50,puVar3);
LAB_00029df4:
  arg1 = 0.0;
  DAT_ffffbb4c = rx8_clamp_float(arg0,0.0,84.0);
  DAT_ffffbb44 = rx8_clamp_float(((DAT_ffffb2a4 + DAT_ffffbb4c) * 100.0) / 84.0,arg1,100.0);
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8744,0);
  if (((cVar2 != '\x01') &&
      (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8728,0), cVar2 != '\x01')) &&
     (DAT_ffffcc95 != '\x01')) {
    uVar1 = rx8_encode_u8_affine_saturate(DAT_ffffbb44,0x3f000000,arg1);
    DAT_ffffbb5a = (char)uVar1;
    return uVar1;
  }
  DAT_ffffbb5a = 0xff;
  return 1;
}


