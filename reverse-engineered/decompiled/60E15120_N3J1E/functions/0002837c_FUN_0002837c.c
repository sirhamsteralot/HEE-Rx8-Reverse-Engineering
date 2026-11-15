/* ROM address: 0x0002837c; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028cc4 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002837c(void)

{
  float *pfVar1;
  float arg0;
  
  arg0 = 0.0;
  if ((sector_parity_bank_ffffb660 & 1) == 0) {
    pfVar1 = &misfire_residual_filtered_bank0_ffffba34;
    if (DAT_ffffb6c6 == '\x01') {
      misfire_residual_filtered_bank0_ffffba34 = rx8_first_order_filter(misfire_residual_ffffba30,misfire_residual_filtered_bank0_ffffba34,0.125,1e-05);
    }
    else {
      misfire_residual_filtered_bank0_ffffba34 = 0.0;
    }
  }
  else {
    pfVar1 = &misfire_residual_filtered_bank1_ffffba38;
    if (DAT_ffffb6c6 == '\x01') {
      misfire_residual_filtered_bank1_ffffba38 = rx8_first_order_filter(misfire_residual_ffffba30,misfire_residual_filtered_bank1_ffffba38,0.125,1e-05);
    }
    else {
      misfire_residual_filtered_bank1_ffffba38 = 0.0;
    }
  }
  DAT_ffffba3c = *pfVar1;
  misfire_excess_deviation_ffffba40 = rx8_max_float(arg0,DAT_ffffba3c);
  return;
}


