/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_adc_pair_correlation_fault_compute [high]: 4-byte body: word 0xa0dd = `bra 0xaee8` + delay-slot word 0x0009 (ROM-verified at 0x0000ad2a). Direct tail-jump to `adc_pair_correlation_fault_compute` 0x0000aee8; callers in callgraph: 0x00006592. Upstream name `thunk_FUN_0000aee8` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0000ad2a; body bytes: 4; decompiled */

uint jump_to_adc_pair_correlation_fault_compute(void)

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


