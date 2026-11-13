/* [ADDITIONAL SOURCE REVIEW]
 * cranking_timing_leading_filter [high]: was ref_calculateCrankingTimingLeading. When cranking (aa62==1 && b53c==1): caa4 = lookup_2d(ECT, tbl 0x6b630 'Off Throttle Leading Timing Realted'); ca9c = first_order_filter(caa4, ca9c, 1.0, 1e-5) (or divide-with-fallback on first edge). Else 0. Feeds +ca9c in 0x123da.
 * RAM 0xffffca9c cranking_angle_timing_leading_filtered (float): mov.w pool 0x43a1c (sign-extends to 0xffffca9c) in 0x43934 cranking_timing_leading_filter and 0x4391c, pool 0x12538 in 0x123da; filtered = raw / period via rx8_divide_with_zero_fallback, stored by 0x43934.
 * RAM 0xffffcaa4 cranking_angle_timing_leading_raw (float): mov.l pool 0x43a28 in 0x4391c and 0x43934; raw leading = lookup_2d(ECT, tbl 0x6b630) stored by 0x43934 cranking_timing_leading_filter.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00043934; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043168 (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint cranking_timing_leading_filter(void)

{
  byte snapshot_at_drive_range_engaged_ffffb53c;
  uint uVar2;
  uint extraout_r0;
  float fVar3;
  float extraout_fr0;
  
  snapshot_at_drive_range_engaged_ffffb53c = at_drive_range_engaged_ffffb53c;
  uVar2 = (uint)cranking_active_ffffaa62_ffffaa62;
  if ((uVar2 == 1) && (uVar2 = (uint)at_drive_range_engaged_ffffb53c, uVar2 == 1)) {
    cranking_angle_timing_leading_raw_ffffcaa4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_off_throttle_leading_timing_realted_0006b630);
    if (DAT_ffffcaac == '\0') {
      fVar3 = rx8_min_float(1.0,1.0);
      uVar2 = rx8_divide_with_zero_fallback(cranking_angle_timing_leading_raw_ffffcaa4,fVar3);
      cranking_angle_timing_leading_filtered_ffffca9c = extraout_fr0;
    }
    else {
      cranking_angle_timing_leading_filtered_ffffca9c = rx8_first_order_filter(cranking_angle_timing_leading_raw_ffffcaa4,cranking_angle_timing_leading_filtered_ffffca9c,1.0,1e-05);
      uVar2 = extraout_r0;
    }
  }
  else {
    cranking_angle_timing_leading_raw_ffffcaa4 = 0.0;
    cranking_angle_timing_leading_filtered_ffffca9c = 0.0;
  }
  DAT_ffffcaac = snapshot_at_drive_range_engaged_ffffb53c;
  return uVar2;
}


