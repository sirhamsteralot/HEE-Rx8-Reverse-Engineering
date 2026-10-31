/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a518: Table 2D - 331 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000231f0; body bytes: 436; decompiled */

undefined4 FUN_000231f0(void)

{
  char cVar1;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  float fVar2;
  float arg1;
  float arg0;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  cVar1 = engine_stopped_latch_ffffa41c;
  if (engine_speed_rpm_ffffb548 < 500.0) {
    if (engine_speed_rpm_ffffb548 < 300.0) {
      DAT_ffffb435 = '\0';
    }
  }
  else {
    DAT_ffffb435 = '\x01';
  }
  if (((DAT_ffffce32 == '\x01') && (DAT_ffffb436 == '\x01')) && (engine_stopped_latch_ffffa41c == '\0')) {
    DAT_ffffb420 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_ffffa98c,&PTR_PTR_0006a518);
  }
  else if (DAT_ffffb420 != 0) {
    DAT_ffffb420 = DAT_ffffb420 + -1;
  }
  if (((DAT_ffffb435 == '\x01') || (DAT_ffffce32 == '\0')) ||
     ((engine_running_ffffa428 == '\x01' || (DAT_ffffb420 == 0)))) {
    DAT_ffffb423 = '\0';
  }
  else if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffb423 = '\x01';
  }
  arg1 = 0.0;
  if (DAT_ffffccbb == '\x01') {
    arg0 = DAT_ffffb404 + fVar2;
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
  }
  else if (DAT_ffffccbc == '\x01') {
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
    arg0 = DAT_ffffb3f8;
  }
  else if (DAT_ffffccbd == '\x01') {
    arg0 = DAT_ffffcc88 + fVar2;
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
  }
  else {
    arg0 = DAT_ffffb410 + fVar2;
    if (DAT_ffffccac == '\x01') {
      arg1 = 0.0;
      fVar2 = fVar2 + 5.0;
    }
    else {
      if (DAT_ffffcca2 != '\x01') {
        if (DAT_ffffb423 == '\x01') {
          DAT_ffffb40c = 99.0;
          DAT_ffffb436 = cVar1;
          return 1;
        }
        fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
        DAT_ffffb40c = rx8_clamp_float(arg0,arg1,fVar2);
        DAT_ffffb436 = cVar1;
        return extraout_r0_00;
      }
      fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
      arg0 = DAT_ffffcca8;
    }
  }
  DAT_ffffb40c = rx8_clamp_float(arg0,arg1,fVar2);
  DAT_ffffb436 = cVar1;
  return extraout_r0;
}


