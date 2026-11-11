/* [ADDITIONAL SOURCE REVIEW]
 * maf_sensor_scaling [high]: 9f78 = tbl 0x69788 'MAF Scaling'(raw 9eea * 5/65536); fault status 9f7c: 0 raw < 0xac0, 2 raw >= 0xfae2, else 1.
 * RAM 0xffff9eea maf_adc_raw (uint16): Raw MAF ADC value; scaled *5/65536 into tbl 0x69788 'MAF Scaling'; fault bands <0xac0 / >=0xfae2.
 * RAM 0xffff9f78 maf_scaled (float): 9f78 = lookup_2d tbl 0x69788(raw * 5/65536); latched into a9e8 by maf_voltage_and_fault_counters (0x19f4e).
 * RAM 0xffff9f7c maf_fault_status (uint8): 9f7c: 0 = raw < 0xac0 (low), 1 = normal, 2 = raw >= 0xfae2 (high).
 */
/* [MATH AND UNITS REVIEW]
 * 7.6293945e-05 is binary32 5/65536. The MAF lookup input is raw*5/65536, consistent with a 5-V full-scale normalized ADC signal; volts is an inference until ADC representation/reference are verified, not proof of a 16-bit ADC.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00007438; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007438 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * maf_sensor_scaling(void)

{
  ushort snapshot_maf_adc_raw_ffff9eea;
  undefined2 *puVar2;
  
  snapshot_maf_adc_raw_ffff9eea = maf_adc_raw_ffff9eea;
  maf_scaled_ffff9f78 = lookup_2d_descriptor_scaled((float)maf_adc_raw_ffff9eea * 7.6293945e-05,&tbl_maf_scaling_00069788);
  if (snapshot_maf_adc_raw_ffff9eea < 0xfae2) {
    puVar2 = &DAT_0006c104;
    if (snapshot_maf_adc_raw_ffff9eea < 0xac0) {
      maf_fault_status_ffff9f7c = 2;
    }
    else {
      maf_fault_status_ffff9f7c = 0;
    }
  }
  else {
    puVar2 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
    maf_fault_status_ffff9f7c = 1;
  }
  return puVar2;
}


