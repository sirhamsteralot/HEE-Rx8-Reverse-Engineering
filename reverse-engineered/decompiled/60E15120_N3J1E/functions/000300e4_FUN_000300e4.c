/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbe7c candidate_cranking_coolant_factor (float): Cranking enrichment factor keyed on coolant (descriptor 0x6aab0) by 0x300e4; one of the five factors multiplied in 0x30228.
 */
/* ROM address: 0x000300e4; body bytes: 32; decompiled */

void FUN_000300e4(void)

{
  candidate_cranking_coolant_factor_ffffbe7c = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&PTR_DAT_0006aab0);
  DAT_ffffbea7 = engine_injectors_off_ffffa42c;
  DAT_ffffbea9 = engine_injectors_off_ffffa42c;
  return;
}


