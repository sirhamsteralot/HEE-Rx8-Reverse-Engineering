/* ROM address: 0x00018eb6; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019ab2 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_decrementTempForCatModel__(void)

{
  if (engine_running_ffffa428 == '\0') {
    inferred_coolant_temperature_catalyst_temp_model_ffffa998 = rx8_first_order_filter(inferred_coolant_temperature_ffffa98c,inferred_coolant_temperature_catalyst_temp_model_ffffa998,0.75,1e-05);
  }
  return;
}


