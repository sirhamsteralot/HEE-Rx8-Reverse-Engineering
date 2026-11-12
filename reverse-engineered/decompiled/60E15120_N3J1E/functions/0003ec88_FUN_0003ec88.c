/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003ec88; body bytes: 484; decompiled */

void FUN_0003ec88(void)

{
  char cVar1;
  char cVar2;
  float snapshot_mass_air_flow_ffffa9ec;
  float snapshot_DAT_ffffad20;
  float snapshot_inferred_ltft_bank1_ffffb0d0_ffffb0d0;
  float snapshot_inferred_lambda_actual_ffffadec_ffffadec;
  
  cVar2 = DAT_ffffd1c5;
  cVar1 = DAT_ffffb07d;
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  snapshot_inferred_ltft_bank1_ffffb0d0_ffffb0d0 = inferred_ltft_bank1_ffffb0d0_ffffb0d0;
  snapshot_inferred_lambda_actual_ffffadec_ffffadec = inferred_lambda_actual_ffffadec_ffffadec;
  if ((((0.4 <= DAT_ffffad20) || ((inferred_lambda_actual_ffffadec_ffffadec < 0.8 && (0x9b < DAT_ffffc6ce)))) ||
      ((1.2 <= inferred_lambda_actual_ffffadec_ffffadec && (0x9b < DAT_ffffc6d0)))) ||
     (((inferred_ltft_bank1_ffffb0d0_ffffb0d0 < -0.5 || (0.5 <= inferred_ltft_bank1_ffffb0d0_ffffb0d0)) || (DAT_ffffd1c5 == '\x01')))) {
    DAT_ffffc6c8 = 0;
  }
  else if (((0.8 <= inferred_lambda_actual_ffffadec_ffffadec) && (inferred_lambda_actual_ffffadec_ffffadec < 1.2)) &&
          ((DAT_ffffb07d == '\x01' &&
           ((10.0 <= mass_air_flow_ffffa9ec &&
            (DAT_ffffc6c8 = rx8_add_u16_saturate((int)(short)DAT_ffffc6c8,1),
            0xf423 < DAT_ffffc6c8)))))) {
    DAT_ffffc6c8 = 0xf424;
  }
  if (((snapshot_DAT_ffffad20 < 0.85) || ((snapshot_inferred_lambda_actual_ffffadec_ffffadec < 0.8 && (0x9b < DAT_ffffc6ce)))) ||
     (((1.2 <= snapshot_inferred_lambda_actual_ffffadec_ffffadec && (0x9b < DAT_ffffc6d0)) ||
      (((snapshot_inferred_ltft_bank1_ffffb0d0_ffffb0d0 < -0.5 || (0.5 <= snapshot_inferred_ltft_bank1_ffffb0d0_ffffb0d0)) || (cVar2 == '\x01')))))) {
    DAT_ffffc6ca = 0;
  }
  else if (((0.8 <= snapshot_inferred_lambda_actual_ffffadec_ffffadec) && (snapshot_inferred_lambda_actual_ffffadec_ffffadec < 1.2)) &&
          ((cVar1 == '\x01' &&
           ((10.0 <= snapshot_mass_air_flow_ffffa9ec &&
            (DAT_ffffc6ca = rx8_add_u16_saturate((int)(short)DAT_ffffc6ca,1),
            0xf423 < DAT_ffffc6ca)))))) {
    DAT_ffffc6ca = 0xf424;
  }
  if ((cVar2 != '\0') || (snapshot_DAT_ffffad20 < 1.2)) {
    DAT_ffffc6cc = 0;
  }
  else {
    DAT_ffffc6cc = rx8_add_u16_saturate((int)(short)DAT_ffffc6cc,1);
    if (0xf423 < DAT_ffffc6cc) {
      DAT_ffffc6cc = 0xf424;
    }
  }
  if (0.8 <= snapshot_inferred_lambda_actual_ffffadec_ffffadec) {
    DAT_ffffc6ce = 0;
  }
  else {
    DAT_ffffc6ce = rx8_add_u16_saturate((int)(short)DAT_ffffc6ce,1);
  }
  if (snapshot_inferred_lambda_actual_ffffadec_ffffadec < 1.2) {
    DAT_ffffc6d0 = 0;
  }
  else {
    DAT_ffffc6d0 = rx8_add_u16_saturate((int)(short)DAT_ffffc6d0,1);
  }
  return;
}


