/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000490f8; body bytes: 4; decompiled */

uint thunk_FUN_00049112(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float fVar3;
  float snapshot_inferred_coolant_temperature_ffffa990;
  
  fVar3 = intake_air_temperature_ffffaddc;
  snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
  fVar2 = rx8_absolute_difference(intake_air_temperature_ffffaddc,inferred_coolant_temperature_ffffa990);
  uVar1 = 1;
  if ((DAT_ffffc5e6 == '\x01') || (uVar1 = (uint)DAT_ffffc5db, uVar1 == 1)) {
    DAT_ffffccf8 = 60.0;
  }
  else if ((3.0 < fVar2) || ((40.0 < fVar3 || (40.0 < snapshot_inferred_coolant_temperature_ffffa990)))) {
    fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41a00000,&DAT_ffff8768);
    DAT_ffffccf8 = rx8_max_float(fVar3,20.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffccf8 = (fVar3 + snapshot_inferred_coolant_temperature_ffffa990) / 2.0;
  }
  DAT_ffffccf4 = DAT_ffffccf8;
  return uVar1;
}


