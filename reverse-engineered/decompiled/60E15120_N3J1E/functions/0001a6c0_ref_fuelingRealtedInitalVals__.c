/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000697e0: Lamda Sensor Barometric Pressure Compensation (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000697ec: Lambda Sensor Scaling (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001a6c0; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b170 (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_fuelingRealtedInitalVals__(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 1.0;
  if (engine_running_ffffa428 == '\0') {
    diag_afr_word_a_ffffaa6c = 1.0;
    DAT_ffffaa70 = 1.0;
    DAT_ffffaa74 = 1.0;
    DAT_ffffaa84 = 0x3f800000;
    DAT_ffffaa88 = 1.0;
    DAT_ffffaa8c = 0x3f800000;
    DAT_ffffaa90 = 0x3f800000;
    DAT_ffffaa96 = 0;
    DAT_ffffaa94 = 0;
    DAT_ffffaa95 = 0;
  }
  if ((DAT_ffffad0a == '\0') && (engine_running_ffffa428 == '\x01')) {
    fVar1 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_lamda_sensor_barometric_pressure_compensation_000697e0);
    fVar2 = (float)lookup_2d_descriptor_scaled(diag_afr_word_b_ffffaa7c,&tbl_lambda_sensor_scaling_000697ec);
    diag_afr_word_a_ffffaa6c = fVar3 + (fVar2 + -1.0) * fVar1;
    DAT_ffffaa70 = rx8_first_order_filter(diag_afr_word_a_ffffaa6c,DAT_ffffaa70,0.9375,1e-05);
    DAT_ffffaa74 = diag_afr_word_a_ffffaa6c;
    DAT_ffffaa88 = diag_afr_word_a_ffffaa6c;
  }
  return;
}


