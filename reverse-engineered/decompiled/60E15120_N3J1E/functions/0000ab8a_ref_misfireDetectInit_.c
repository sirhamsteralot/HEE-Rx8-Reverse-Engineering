/* ROM address: 0x0000ab8a; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ab8a (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_misfireDetectInit_(void)

{
  FUN_0000ac02();
  DAT_ffffa1cc = 0x3f800000;
  DAT_ffffa1d0 = 0;
  adc_pair_ratio_filtered_ffffa1d4 = 0x46800000;
  adc_pair_ratio_raw_ffffa1d8 = 0x46800000;
  adc_pair_range_fault_ffffa1dc = 0;
  adc_pair_correlation_fault_ffffa1dd = 0;
  adc_pair_second_sample_ready_ffffa202 = 0;
  DAT_ffffa203 = 0;
  DAT_ffffa204 = 0;
  DAT_ffffa1f8 = 0x8f5c;
  DAT_ffffa1e0 = 0;
  DAT_ffffa1f4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8030);
  DAT_ffffa208 = 0;
  DAT_ffffa206 = 0;
  DAT_ffffa207 = 0xff;
  return;
}


