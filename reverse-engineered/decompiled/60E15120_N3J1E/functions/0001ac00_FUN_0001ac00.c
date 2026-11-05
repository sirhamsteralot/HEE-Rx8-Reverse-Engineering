/* ROM address: 0x0001ac00; body bytes: 238; decompiled */

char FUN_0001ac00(void)

{
  DAT_ffffaa78 = adc_pair_ratio_filtered_ffffa1d4;
  if (50.0 < adc_pair_ratio_filtered_ffffa1d4) {
    if (55.0 < adc_pair_ratio_filtered_ffffa1d4) {
      DAT_ffffaa81 = 0;
    }
  }
  else {
    DAT_ffffaa81 = 1;
  }
  if (50.0 <= adc_pair_ratio_filtered_ffffa1d4) {
    if (55.0 <= adc_pair_ratio_filtered_ffffa1d4) {
      DAT_ffffad0b = '\x01';
    }
  }
  else {
    DAT_ffffad0b = '\0';
  }
  if (((DAT_ffffacf8 - 0.0146 <= DAT_ffffacf4) && (DAT_ffffaa70 < lambda_target_ffffadfc - 0.0146)) ||
     ((DAT_ffffacf4 < DAT_ffffacf8 + 0.0146 && (lambda_target_ffffadfc + 0.0146 <= DAT_ffffaa70)))) {
    DAT_ffffad0c = '\x01';
  }
  if ((((DAT_ffffad0b == '\0') && (0.9899999 <= lambda_target_ffffadfc)) && (lambda_target_ffffadfc < 1.01)) &&
     ((DAT_ffffad0c == '\x01' && (engine_running_ffffa428 == '\x01')))) {
    lambda_in_target_band_ffffaa80 = 1;
  }
  if (((DAT_ffffad0b == '\x01') || (lambda_target_ffffadfc < 0.9899999)) || (1.01 <= lambda_target_ffffadfc)) {
    lambda_in_target_band_ffffaa80 = 0;
  }
  DAT_ffffacf4 = DAT_ffffaa70;
  DAT_ffffacf8 = lambda_target_ffffadfc;
  return DAT_ffffad0b;
}


