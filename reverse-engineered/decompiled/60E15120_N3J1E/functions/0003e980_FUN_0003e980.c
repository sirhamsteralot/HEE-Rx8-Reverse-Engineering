/* ROM address: 0x0003e980; body bytes: 150; decompiled */

undefined4 * FUN_0003e980(void)

{
  undefined4 *extraout_r0;
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float arg1;
  
  if (engine_running_ffffa428 == '\0') {
    if (DAT_ffffc69d == '\x01') {
      DAT_ffffc644 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
      puVar1 = (undefined4 *)((int)&vector_Poweron_Reset + 1);
    }
    else {
      arg1 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
      fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&DAT_ffff8710);
      fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
      DAT_ffffc644 = rx8_max_float(fVar2 - (fVar3 - arg1) * 10.0,arg1);
      puVar1 = extraout_r0;
    }
  }
  else {
    puVar1 = (undefined4 *)&DAT_ffffc69c;
    if (DAT_ffffc69c == '\0') {
      if (DAT_ffffc5e6 == '\x01') {
        DAT_ffffc644 = 1000.0;
        puVar1 = (undefined4 *)((int)&vector_Poweron_Reset + 1);
      }
      else {
        puVar1 = &DAT_ffffc684;
        DAT_ffffc644 = DAT_ffffc644 +
                       (DAT_ffffc684 - DAT_ffffc644) * DAT_ffffc678 * DAT_ffffc67c * DAT_ffffc68c;
      }
    }
  }
  return puVar1;
}


