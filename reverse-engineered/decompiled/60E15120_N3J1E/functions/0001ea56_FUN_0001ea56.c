/* ROM address: 0x0001ea56; body bytes: 66; decompiled */

void FUN_0001ea56(void)

{
  if (((inferred_coolant_temperature_catalyst_temp_model_ffffa998 < 80.0) && (0xabd < DAT_ffffb2f4)) ||
     ((80.0 <= inferred_coolant_temperature_catalyst_temp_model_ffffa998 && (0xabd < DAT_ffffb2f4)))) {
    DAT_ffffb0de = 1;
  }
  else {
    DAT_ffffb0de = 0;
  }
  return;
}


