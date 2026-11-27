/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006adb4: Engine Torque Max - Barometric Pressure Compensation (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * dsc_desired_torque_calc [medium]: 0xffffbbe0 = 0xffffbca0 - ((bb20 * decode(bbc9))/100 - bcb8 - bcbc); filter 0xffffbbf8 = first_order_filter(decode(bbc9), bbf8, 0.25, 0.19685039) -> 0xffffbbf7 = encode_u8_affine_saturate(bbf8); 0xffffbbc9 = -2 when engine stopped, 0xfe = 0xfe when validity/fault flags. Called from 0x2a2ae via pool 0x2a470.
 */
/* ROM address: 0x0002b496; body bytes: 440; decompiled */

void candidate_dsc_desired_torque_calc(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  float arg1;
  
  cVar4 = DAT_ffffbb24;
  cVar3 = engine_running_ffffa428;
  cVar2 = can_error_latch_ffffa40a;
  cVar1 = DAT_ffffa401;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffbbc9 = -2;
  }
  if ((((DAT_ffffbbec == 0) || (DAT_ffffbb24 == '\x01')) || (engine_running_ffffa428 == '\0')) ||
     ((can_error_latch_ffffa40a == '\x01' || (DAT_ffffa401 == '\x01')))) {
    DAT_ffffbbca = 0xfe;
  }
  arg1 = 0.0;
  uVar7 = 0x3ec99326;
  fVar5 = (float)rx8_decode_u8_affine(0x3ec99326,0,(int)DAT_ffffbbc9);
  DAT_ffffbbe0 = DAT_ffffbca0 - (((DAT_ffffbb20 * fVar5) / 100.0 - DAT_ffffbcb8) - DAT_ffffbcbc);
  fVar8 = DAT_ffffbca0;
  DAT_ffffbbf8 = rx8_first_order_filter(fVar5,DAT_ffffbbf8,0.25,0.19685039);
  DAT_ffffbbf7 = rx8_encode_u8_affine_saturate(DAT_ffffbbf8,uVar7,arg1);
  if (((DAT_ffffbbea == 0) || (cVar4 != '\0')) || ((cVar2 != '\0' || (cVar1 != '\0')))) {
    fVar5 = inferred_desired_torque_ffffbbd4 + 0.5;
  }
  else if ((DAT_ffffbbc9 == -2) || (cVar3 != '\x01')) {
    fVar5 = 512.0;
    DAT_ffffbbe4 = arg1;
  }
  else {
    fVar6 = (float)rx8_decode_u8_affine(uVar7,arg1,(int)DAT_ffffbbf7);
    fVar6 = rx8_absolute_difference(fVar5,fVar6);
    fVar8 = fVar8 - DAT_ffffbbe0;
    fVar5 = arg1;
    if (fVar6 < 100.0) {
      fVar8 = (fVar8 - DAT_ffffbbe0 * 0.1) - (DAT_ffffbbe0 + DAT_ffffbbe4) * 0.001;
      fVar5 = DAT_ffffbbe0 + DAT_ffffbbe4;
    }
    DAT_ffffbbe4 = fVar5;
    fVar6 = (float)lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&DAT_0006ada0);
    fVar5 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_engine_torque_max_barometric_pressure_compensation_0006adb4);
    fVar5 = fVar8 * fVar6 * fVar5;
  }
  inferred_desired_torque_ffffbbd4 = rx8_clamp_float(fVar5,arg1,512.0);
  return;
}


