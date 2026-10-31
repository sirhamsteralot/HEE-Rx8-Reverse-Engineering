/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006adb4: Engine Torque Max - Barometric Pressure Compensation (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00029768; body bytes: 228; decompiled */

undefined1 * FUN_00029768(void)

{
  char cVar2;
  char cVar3;
  undefined1 *puVar1;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  fVar4 = (float)lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&DAT_0006ada0);
  fVar5 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_engine_torque_max_barometric_pressure_compensation_0006adb4);
  fVar4 = fVar4 * fVar5;
  uVar6 = 0x3727c5ac;
  fVar5 = 0.0;
  cVar2 = rx8_is_outside_tolerance_band(fVar4,0,0x3727c5ac);
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffbb20,fVar5,uVar6);
  if (DAT_ffffbb24 == '\x01') {
    DAT_ffffbb19 = 0xff;
    puVar1 = (undefined1 *)0x1;
  }
  else if (engine_running_ffffa428 == '\0') {
    DAT_ffffbb19 = 0;
    puVar1 = (undefined1 *)0x0;
  }
  else {
    if ((DAT_ffffbbcb == '\0') && (DAT_ffffbbcc == '\0')) {
      puVar1 = (undefined1 *)(int)DAT_ffffbb18;
    }
    else {
      if ((cVar2 == '\0') || (cVar3 == '\0')) {
        DAT_ffffbb19 = 0xfe;
        return &DAT_ffffbbcb;
      }
      fVar4 = rx8_clamp_float((((DAT_ffffb2c0 + DAT_ffffbcb8 + DAT_ffffbcbc) * 100.0) / DAT_ffffbb20
                              ) / fVar4,fVar5,100.0);
      puVar1 = (undefined1 *)rx8_encode_u8_affine_saturate(fVar4,0x3ec99326,fVar5);
    }
    DAT_ffffbb19 = SUB41(puVar1,0);
  }
  return puVar1;
}


