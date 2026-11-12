/* [ADDITIONAL SOURCE REVIEW]
 * cranking_timing_trailing_filter [high]: Trailing mirror of 0x43934: caa8 = lookup_2d(ECT, tbl 0x6b644 'Ignition Trailing - Cranking Timing Advance'); caa0 filtered. Feeds +caa0 in 0x124d6.
 * RAM 0xffffcaa0 cranking_angle_timing_trailing_filtered (float): 
 * RAM 0xffffcaa8 cranking_angle_timing_trailing_raw (float): 
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000439b2; body bytes: 126; decompiled */

uint cranking_timing_trailing_filter(void)

{
  byte snapshot_at_drive_range_engaged_ffffb53c;
  uint uVar2;
  uint extraout_r0;
  float fVar3;
  float extraout_fr0;
  
  snapshot_at_drive_range_engaged_ffffb53c = at_drive_range_engaged_ffffb53c;
  uVar2 = (uint)cranking_active_ffffaa62_ffffaa62;
  if ((uVar2 == 1) && (uVar2 = (uint)at_drive_range_engaged_ffffb53c, uVar2 == 1)) {
    cranking_angle_timing_trailing_raw_ffffcaa8 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_ignition_trailing_cranking_timing_advance_0006b644);
    if (DAT_ffffcaad == '\0') {
      fVar3 = rx8_min_float(1.0,1.0);
      uVar2 = rx8_divide_with_zero_fallback(cranking_angle_timing_trailing_raw_ffffcaa8,fVar3);
      cranking_angle_timing_trailing_filtered_ffffcaa0 = extraout_fr0;
    }
    else {
      cranking_angle_timing_trailing_filtered_ffffcaa0 = rx8_first_order_filter(cranking_angle_timing_trailing_raw_ffffcaa8,cranking_angle_timing_trailing_filtered_ffffcaa0,1.0,1e-05);
      uVar2 = extraout_r0;
    }
  }
  else {
    cranking_angle_timing_trailing_raw_ffffcaa8 = 0.0;
    cranking_angle_timing_trailing_filtered_ffffcaa0 = 0.0;
  }
  DAT_ffffcaad = snapshot_at_drive_range_engaged_ffffb53c;
  return uVar2;
}


