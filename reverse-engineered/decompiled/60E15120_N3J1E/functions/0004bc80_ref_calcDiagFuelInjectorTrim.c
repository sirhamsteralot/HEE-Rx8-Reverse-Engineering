/* ROM address: 0x0004bc80; body bytes: 154; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004ae38 (154 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calcDiagFuelInjectorTrim(void)

{
  if (engine_stopped_latch_ffffa41c == '\x01') {
    if ((((((DAT_ffffce48 == '\x01') && (inferred_coolant_temperature_ffffa98c < -40.0)) ||
          ((DAT_ffffce48 == '\x02' && (inferred_coolant_temperature_ffffa98c < -40.0)))) ||
         ((DAT_ffffce48 == '\x03' && (inferred_coolant_temperature_ffffa98c < -40.0)))) ||
        ((DAT_ffffce48 == '\x04' && (inferred_coolant_temperature_ffffa98c < -10.0)))) ||
       ((DAT_ffffce48 == '\x05' && (inferred_coolant_temperature_ffffa98c < -10.0)))) {
      DAT_ffffce53 = '\x01';
    }
    else {
      DAT_ffffce53 = '\0';
    }
  }
  DAT_ffffce32 = FUN_0005d210((int)DAT_ffffce53);
  return;
}


