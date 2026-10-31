/* ROM address: 0x0003e89e; body bytes: 120; decompiled */

void FUN_0003e89e(void)

{
  float fVar1;
  float fVar2;
  float arg1;
  
  if (engine_running_ffffa428 == '\0') {
    if (DAT_ffffc64e == '\x01') {
      DAT_ffffc640 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
    }
    else {
      arg1 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
      fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&DAT_ffff8708);
      fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
      DAT_ffffc640 = rx8_max_float(fVar1 - (fVar2 - arg1) * 10.0,arg1);
    }
  }
  else {
    DAT_ffffc640 = DAT_ffffc640 +
                   (DAT_ffffc66c - DAT_ffffc640) * DAT_ffffc658 * DAT_ffffc65c * DAT_ffffc674;
  }
  return;
}


