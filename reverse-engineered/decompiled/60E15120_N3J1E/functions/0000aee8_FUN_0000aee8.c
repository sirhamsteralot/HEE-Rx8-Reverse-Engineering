/* [ADDITIONAL SOURCE REVIEW]
 * adc_pair_correlation_fault_compute [high]: Gated by 0xffffa202; samples written by 0xb0a6/0xb1da (from ADC EOC bank1 0x6b60): 0xffffa1fa/a1fc = word @0xfffff836 (ADDR23H/AN23), 0xffffa1fe/a200 = word @0xfffff816 (ADDR11H/AN11; add -0x20 from the 0xfffff836 pool word, ROM-verified). Computes |dV|*5/65536 -> 0xffffa1f0, inter-channel delta/200 -> 0xffffa1e4/a1e8, ratio-16.25 -> 0xffffa1d8 (raw), filtered 0.25 -> 0xffffa1d4; range fault 0xffffa1dc (raw<0x5c29->2, >0xc28f->1), correlation fault 0xffffa1dd (+/-0.005 V). Consumed by 0x1ac00 (copies a1d4 -> 0xffffaa78, lambda band logic) and 0x22630 (duty lookups + closed loop vs 30.0).
 * RAM 0xffffa202 adc_pair_second_sample_ready (uint8): Set to 1 by 0xb1da once both channels sampled; gates the compute in 0xaee8.
 * RAM 0xffffa1d8 adc_pair_ratio_raw (float): |dAN23|*5/65536 / |d(AN23-AN11)/200| - 16.25; consumed by 0x1ac00 and 0x22630.
 * RAM 0xffffa1d4 adc_pair_ratio_filtered (float): first_order_filter(a1d8, a1d4, 0.25); copied to 0xffffaa78 by 0x1ac00.
 * RAM 0xffffa1dc adc_pair_range_fault (uint8): 2 = AN23 raw < 0x5c29, 1 = > 0xc28f, 0 = in band.
 * RAM 0xffffa1dd adc_pair_correlation_fault (uint8): 2 = inter-channel delta < -0.005, 1 = > +0.005, 0 = ok.
 */
/* ROM address: 0x0000aee8; body bytes: 356; decompiled */

uint adc_pair_correlation_fault_compute(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (uint)adc_pair_second_sample_ready_ffffa202;
  if (uVar1 == 1) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
    DAT_ffffa1f0 = ((float)adc_an23_sample_a_ffffa1fa - (float)adc_an23_sample_b_ffffa1fc) * 7.6293945e-05;
    if (DAT_ffffa1f0 < 0.0) {
      DAT_ffffa1f0 = -DAT_ffffa1f0;
    }
    DAT_ffffa1e4 = (((float)adc_an23_sample_a_ffffa1fa - (float)adc_an11_sample_a_ffffa1fe) * 7.6293945e-05) / 200.0;
    DAT_ffffa1e8 = (((float)adc_an23_sample_b_ffffa1fc - (float)adc_an11_sample_b_ffffa200) * 7.6293945e-05) / 200.0;
    DAT_ffffa1ec = DAT_ffffa1e4 - DAT_ffffa1e8;
    if (DAT_ffffa1ec < 0.0) {
      DAT_ffffa1ec = -DAT_ffffa1ec;
    }
    if (DAT_ffffa1ec == 0.0) {
      adc_pair_ratio_raw_ffffa1d8 = 16383.75;
    }
    else {
      adc_pair_ratio_raw_ffffa1d8 = DAT_ffffa1f0 / DAT_ffffa1ec - 16.25;
    }
    if (DAT_ffffa203 == '\0') {
      DAT_ffffa203 = '\x01';
      adc_pair_ratio_filtered_ffffa1d4 = adc_pair_ratio_raw_ffffa1d8;
    }
    else {
      adc_pair_ratio_filtered_ffffa1d4 = rx8_first_order_filter(adc_pair_ratio_raw_ffffa1d8,adc_pair_ratio_filtered_ffffa1d4,0.25,0.0);
    }
    if (adc_an23_sample_a_ffffa1fa < 0xc28f) {
      if (adc_an23_sample_a_ffffa1fa < 0x5c29) {
        adc_pair_range_fault_ffffa1dc = 2;
      }
      else {
        adc_pair_range_fault_ffffa1dc = 0;
      }
    }
    else {
      adc_pair_range_fault_ffffa1dc = 1;
    }
    if (DAT_ffffa1e4 < 0.005) {
      if (-0.005 <= DAT_ffffa1e4) {
        adc_pair_correlation_fault_ffffa1dd = 0;
      }
      else {
        adc_pair_correlation_fault_ffffa1dd = 2;
      }
    }
    else {
      adc_pair_correlation_fault_ffffa1dd = 1;
    }
    uVar1 = ref_setSR(uVar2);
  }
  return uVar1;
}


