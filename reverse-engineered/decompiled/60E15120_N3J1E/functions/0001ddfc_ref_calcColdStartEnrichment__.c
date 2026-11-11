/* [ADDITIONAL SOURCE REVIEW]
 * cold_start_enrichment [high]: Cranking: b0c4 = 0.0 (both coolant/IAT branches store 0.0 in this ROM); running: b0c4 = max(b0c4 - 0.0, 0.0). b0c4 feeds calc_fuel_volume_request (0x306e8) and closed_loop_fuel_trim (0x307e0). | promoted to high (data/labels/60E15120_N3J1E/fueling_labels.json/function_aliases)
 */
/* ROM address: 0x0001ddfc; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001e85c (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * cold_start_enrichment(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  
  if (engine_running_ffffa428 == '\0') {
    puVar1 = &inferred_coolant_temperature_ffffa98c;
    if ((inferred_coolant_temperature_ffffa98c < 0.0) || (intake_air_temperature_ffffaddc < 0.0)) {
      DAT_ffffb0c4 = 0.0;
    }
    else {
      DAT_ffffb0c4 = 0.0;
    }
  }
  else {
    DAT_ffffb0c4 = rx8_max_float(DAT_ffffb0c4 - 0.0,0.0);
    puVar1 = extraout_r0;
  }
  return puVar1;
}


