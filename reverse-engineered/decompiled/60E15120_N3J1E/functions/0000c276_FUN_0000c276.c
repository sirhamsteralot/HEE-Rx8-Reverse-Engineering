/* [ADDITIONAL SOURCE REVIEW]
 * knock_reference_adc_read [high]: a326 = adc_read_result_bank2(): knock reference-channel ADC; called from 0xc8dc (knock_sensor_sci_command) and 0x5a4c.
 */
/* ROM address: 0x0000c276; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c276 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void knock_reference_adc_read(void)

{
  ushort uVar1;
  
  knock_voltage_reference_ffffa326 = adc_read_result_bank2();
  uVar1 = ATUII_TIER8_W;
  ATUII_TIER8_W = uVar1 & 0xefff;
  return;
}


