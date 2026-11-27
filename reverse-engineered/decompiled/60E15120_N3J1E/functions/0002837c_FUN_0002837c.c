/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_learned_table_correction_filter [medium]: Per rotor bank (DAT_ffffb660&1): if DAT_ffffb6c6==1, filters DAT_ffffba30 into DAT_ffffba34 / 0xffffba38 (rx8_first_order_filter k=0.125, eps 1e-5), else 0; DAT_ffffba3c = bank value, DAT_ffffba40 = max(0, DAT_ffffba3c). Called from 0x287aa.
 * RAM 0xffffba34 misfire_residual_filtered_bank0 (float): Filtered DAT_ffffba30 per rotor bank 0 (0x2837c, k=0.125) when DAT_ffffb6c6==1 (cell learned), else 0.
 * RAM 0xffffba38 misfire_residual_filtered_bank1 (float): Filtered DAT_ffffba30 per rotor bank 1 (0x2837c).
 * RAM 0xffffba40 misfire_excess_deviation (float): DAT_ffffba40 = max(0, DAT_ffffba3c): the excess deviation above the learned baseline; thresholded by 0x447e2 (RPM thresholds) and 0x4489c (load limits), armed via 0x27fb4/0x28022.
 */
/* ROM address: 0x0002837c; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028cc4 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_e2ram_learned_table_correction_filter(void)

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


