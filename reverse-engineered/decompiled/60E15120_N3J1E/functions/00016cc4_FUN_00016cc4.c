/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ade0: Load Based Oil Injection Temperature Correction (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006adf4: First Start Oil Injection Timer (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ae00: Oil Metering By Load (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ae14: Oil Metering By Throttle (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016cc4; body bytes: 468; decompiled */

void FUN_00016cc4(void)

{
  uint uVar1;
  ushort uVar3;
  uint uVar2;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  
  fVar6 = inferred_coolant_temperature_ffffa98c;
  uVar7 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  DAT_ffffa8dc = rx8_lookup_3d_raw_u8(engine_speed_rpm_ffffb548,engine_load_ffffc0b4,&tbl_oil_metering_by_load_0006ae00);
  DAT_ffffa8d8 = (float)lookup_2d_descriptor_scaled(fVar6,&tbl_load_based_oil_injection_temperature_correction_0006ade0);
  uVar1 = rx8_lookup_2d_raw_u8(fVar6,&DAT_0006add4);
  DAT_ffffa8de = rx8_lookup_2d_raw_u8(inferred_barometric_pressure_ffffad14,&PTR_PTR_0006adc8);
  DAT_ffffa8df = rx8_lookup_3d_raw_u8(engine_speed_rpm_ffffb548,inferred_throttle_position_ffffad44,&tbl_oil_metering_by_throttle_0006ae14);
  uVar3 = rx8_lookup_2d_raw_u16(uVar7,&tbl_first_start_oil_injection_timer_0006adf4);
  uVar7 = 0;
  fVar8 = 1.0;
  fVar4 = (float)rx8_decode_u8_affine(0x3f800000,0,(int)(char)DAT_ffffa8dc);
  fVar5 = (float)rx8_decode_u8_affine(fVar8,0xc2480000,(int)DAT_ffffa8de);
  fVar5 = fVar5 + DAT_ffffa8d8 * fVar4;
  if (0.5 <= fVar5) {
    fVar5 = fVar5 + -0.5;
  }
  uVar2 = rx8_encode_u8_affine_saturate(fVar5,fVar8,uVar7);
  if (fVar6 <= 30.0) {
    if (fVar6 <= 27.0) {
      DAT_ffffa8e1 = '\x01';
    }
  }
  else {
    DAT_ffffa8e1 = '\0';
  }
  if ((DAT_ffffce33 == '\x01') && (DAT_ffffa8e1 == '\x01')) {
    fVar6 = (float)rx8_decode_u8_affine(fVar8,uVar7,uVar1);
    uVar1 = rx8_encode_u8_affine_saturate(fVar6 * 1.0,fVar8,uVar7);
  }
  if (DAT_ffffa422 < uVar3) {
    DAT_ffffa8e0 = 0x1e;
  }
  else {
    DAT_ffffa8e0 = 0;
  }
  if ((uVar2 & 0xff) < (uVar1 & 0xff)) {
    uVar2 = uVar1;
  }
  if ((uVar2 & 0xff) < (uint)DAT_ffffa8df) {
    uVar2 = (int)(char)DAT_ffffa8df;
  }
  if ((uVar2 & 0xff) < (uint)DAT_ffffa8e0) {
    uVar2 = (int)(char)DAT_ffffa8e0;
  }
  if (0x3c < (uVar2 & 0xff)) {
    uVar2 = 0x3c;
  }
  fVar6 = (float)rx8_decode_u8_affine(fVar8,uVar7,(int)DAT_ffffa8dd);
  fVar4 = (float)rx8_decode_u8_affine(fVar8,uVar7,uVar2);
  fVar6 = rx8_absolute_difference(fVar4,fVar6);
  if (DAT_ffffa914 == '\x01') {
    uVar2 = 7;
  }
  else if (engine_running_flag_ffffaa68 == '\0') {
    uVar2 = 0;
  }
  else if (DAT_ffffa8ec == '\x01') {
    uVar2 = 0x3c;
  }
  else if ((fVar6 <= fVar8) && (9 < DAT_ffffa8dc)) {
    uVar2 = (uint)DAT_ffffa8dd;
  }
  DAT_ffffa8dd = ref_diagMeteringPumpPositionControl(uVar2);
  return;
}


