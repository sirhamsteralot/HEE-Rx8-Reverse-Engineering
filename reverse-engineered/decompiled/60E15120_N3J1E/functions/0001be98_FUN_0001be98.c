/* ROM address: 0x0001be98; body bytes: 180; decompiled */

undefined4 FUN_0001be98(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float extraout_fr0;
  
  if (engine_running_ffffa428 == '\0') {
    fVar2 = rx8_absolute_difference(inferred_coolant_temperature_ffffa98c,intake_air_temperature_ffffaddc);
    uVar1 = extraout_r0;
    if ((fVar2 < 7.5) && (intake_air_temperature_ffffaddc < 50.0)) {
      uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(intake_air_temperature_ffffaddc,&DAT_ffff80bc);
    }
  }
  else {
    fVar2 = intake_air_temperature_ffffaddc;
    fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(intake_air_temperature_ffff9f60,&DAT_ffff80bc);
    fVar2 = fVar2 - fVar3;
    uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(intake_air_temperature_ffff9f60,&DAT_ffff80bc);
    if (extraout_fr0 <= intake_air_temperature_ffffaddc) {
      if (50.0 <= fVar2) {
        fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(intake_air_temperature_ffff9f60,&DAT_ffff80bc);
        fVar2 = rx8_min_float(fVar2 + 15.0,intake_air_temperature_ffffaddc);
        uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff80bc);
      }
    }
    else {
      fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(intake_air_temperature_ffff9f60,&DAT_ffff80bc);
      fVar2 = rx8_first_order_filter(intake_air_temperature_ffffaddc,fVar2,0.25,1e-05);
      uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff80bc);
    }
  }
  return uVar1;
}


