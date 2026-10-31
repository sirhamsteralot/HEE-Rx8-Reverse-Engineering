/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b630: Off Throttle Leading Timing Realted (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00043934; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043168 (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_calculateCrankingTimingLeading(void)

{
  byte snapshot_DAT_ffffb53c;
  uint uVar2;
  uint extraout_r0;
  float fVar3;
  float extraout_fr0;
  
  snapshot_DAT_ffffb53c = DAT_ffffb53c;
  uVar2 = (uint)DAT_ffffaa62;
  if ((uVar2 == 1) && (uVar2 = (uint)DAT_ffffb53c, uVar2 == 1)) {
    DAT_ffffcaa4 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_off_throttle_leading_timing_realted_0006b630);
    if (DAT_ffffcaac == '\0') {
      fVar3 = rx8_min_float(1.0,1.0);
      uVar2 = rx8_divide_with_zero_fallback(DAT_ffffcaa4,fVar3);
      DAT_ffffca9c = extraout_fr0;
    }
    else {
      DAT_ffffca9c = rx8_first_order_filter(DAT_ffffcaa4,DAT_ffffca9c,1.0,1e-05);
      uVar2 = extraout_r0;
    }
  }
  else {
    DAT_ffffcaa4 = 0.0;
    DAT_ffffca9c = 0.0;
  }
  DAT_ffffcaac = snapshot_DAT_ffffb53c;
  return uVar2;
}


