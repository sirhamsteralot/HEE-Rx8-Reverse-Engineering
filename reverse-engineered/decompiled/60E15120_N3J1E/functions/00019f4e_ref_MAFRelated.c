/* [ADDITIONAL SOURCE REVIEW]
 * maf_voltage_and_fault_counters [medium]: aa2c = rx8_decode_u16_affine(0x38a00000, 0, raw 9eea) (MAF voltage); aa35/aa36 saturating fault counters (raw >= 0xf852 / < 0x7ae); when faulted: a9e4 = aa2c, a9e8 = 9f78 (MAF scaled latched).
 * RAM 0xffffaa2c maf_voltage (float): aa2c = rx8_decode_u16_affine(0x38a00000, 0, raw 9eea): MAF voltage; latched into a9e4 on fault.
 * RAM 0xffffaa35 maf_high_fault_counter (uint8): Saturating counter incremented while raw >= 0xf852.
 * RAM 0xffffaa36 maf_low_fault_counter (uint8): Saturating counter incremented while raw < 0x7ae; cleared otherwise.
 * RAM 0xffffa9e4 maf_voltage_latched (float): a9e4 = aa2c when MAF faulted (>2 on either counter or raw in 0x7ae..0xf852 window).
 * RAM 0xffffa9e8 maf_scaled_latched (float): a9e8 = 9f78 (maf_scaled) on fault; becomes mass_air_flow a9ec via 0x19f40.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00019f4e; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001acae (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * maf_voltage_and_fault_counters(void)

{
  ushort snapshot_maf_adc_raw_ffff9eea;
  undefined4 *puVar2;
  undefined4 extraout_fr0;
  
  snapshot_maf_adc_raw_ffff9eea = maf_adc_raw_ffff9eea;
  puVar2 = (undefined4 *)
           rx8_decode_u16_affine(0x38a00000,0,(int)(short)maf_adc_raw_ffff9eea);
  maf_voltage_ffffaa2c = extraout_fr0;
  if (snapshot_maf_adc_raw_ffff9eea < 0xf852) {
    maf_high_fault_counter_ffffaa35 = 0;
  }
  else {
    puVar2 = (undefined4 *)rx8_add_u8_saturate((int)(char)maf_high_fault_counter_ffffaa35,1);
    maf_high_fault_counter_ffffaa35 = (byte)puVar2;
  }
  if (snapshot_maf_adc_raw_ffff9eea < 0x7ae) {
    puVar2 = (undefined4 *)rx8_add_u8_saturate((int)(char)maf_low_fault_counter_ffffaa36,1);
    maf_low_fault_counter_ffffaa36 = (byte)puVar2;
  }
  else {
    maf_low_fault_counter_ffffaa36 = 0;
  }
  if (((2 < maf_high_fault_counter_ffffaa35) || (2 < maf_low_fault_counter_ffffaa36)) ||
     ((snapshot_maf_adc_raw_ffff9eea < 0xf852 && (puVar2 = (undefined4 *)0x7ae, 0x7ad < snapshot_maf_adc_raw_ffff9eea)))) {
    maf_voltage_latched_ffffa9e4 = maf_voltage_ffffaa2c;
    puVar2 = &maf_scaled_latched_ffffa9e8;
    maf_scaled_latched_ffffa9e8 = maf_scaled_ffff9f78;
  }
  return puVar2;
}


