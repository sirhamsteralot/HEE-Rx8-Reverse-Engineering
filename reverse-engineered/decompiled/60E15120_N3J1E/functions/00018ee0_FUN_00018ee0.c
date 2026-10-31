/* ROM address: 0x00018ee0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019adc (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_00018ee0(void)

{
  undefined2 *puVar1;
  
  if (0x7c < engine_running_timer_ffffa424) {
    puVar1 = (undefined2 *)ref_updateMemoryAtAddress_float_VAL_ADDR(inferred_coolant_temperature_ffffa98c,&DAT_ffff8060);
    return puVar1;
  }
  return &DAT_0006ee9c;
}


