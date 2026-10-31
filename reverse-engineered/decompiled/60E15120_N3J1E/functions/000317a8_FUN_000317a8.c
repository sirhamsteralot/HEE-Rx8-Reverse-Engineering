/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000317a8; body bytes: 282; decompiled */

uint FUN_000317a8(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if (DAT_ffffc6b4 == '\0') {
    fVar3 = intake_air_temperature_ffffaddc;
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
    DAT_ffffbf74 = fVar2 - snapshot_inferred_coolant_temperature_ffffa98c;
    if (((((DAT_ffffc4c2 < 0x169) || (((int)DAT_ffffcd0c & 0x80U) != 0)) &&
         ((20.0 < DAT_ffffbf74 ||
          (fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&DAT_ffff8710),
          350.0 < fVar2)))) && ((DAT_ffffbf74 <= 20.0 && (35.0 < DAT_ffffc644)))) ||
       ((snapshot_inferred_coolant_temperature_ffffa98c <= -10.0 || ((35.0 < snapshot_inferred_coolant_temperature_ffffa98c || (40.0 < fVar3)))))) {
      DAT_ffffbf72 = 0;
    }
    else {
      DAT_ffffbf72 = 1;
    }
  }
  else {
    fVar3 = intake_air_temperature_ffffaddc;
    DAT_ffffbf74 = rx8_absolute_difference(intake_air_temperature_ffffaddc,inferred_coolant_temperature_ffffa98c);
    if ((((5.5 < DAT_ffffbf74) || (snapshot_inferred_coolant_temperature_ffffa98c <= -10.0)) || (35.0 < snapshot_inferred_coolant_temperature_ffffa98c)) || (40.0 < fVar3)) {
      DAT_ffffbf72 = 0;
    }
    else {
      DAT_ffffbf72 = 1;
    }
  }
  uVar1 = (uint)DAT_ffffbf72;
  if (uVar1 == 1) {
    uVar1 = rx8_lookup_2d_raw_u16(snapshot_inferred_coolant_temperature_ffffa98c,&PTR_CAL_table_845_0006ad94);
    DAT_ffffbf70 = (undefined2)uVar1;
  }
  else {
    DAT_ffffbf70 = 0;
  }
  return uVar1;
}


