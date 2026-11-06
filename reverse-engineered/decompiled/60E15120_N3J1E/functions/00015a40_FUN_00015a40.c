/* [ADDITIONAL SOURCE REVIEW]
 * fuel_cut_resume_threshold [medium]: 0xffffa830 = tbl 0x69768(rough knock correction leading 0xffffa6ac) when 0xffffa6b7/a6b8/a6b9 are clear, else 0. Called from 0x167c0 via pool 0x168d0.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069768: Off Throttle Fuel Cut - Fuel Resume - In Neutral Threshold7 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00015a40; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00015844 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * candidate_fuel_cut_resume_threshold(void)

{
  undefined1 *puVar1;
  undefined4 extraout_fr0;
  
  if (((DAT_ffffa6b7 == '\0') && (DAT_ffffa6b8 == '\0')) &&
     (puVar1 = &DAT_ffffa6b9, DAT_ffffa6b9 == '\0')) {
    DAT_ffffa830 = 0;
  }
  else {
    puVar1 = (undefined1 *)lookup_2d_descriptor_scaled(rough_knock_correction_leading_ffffa6ac,&tbl_off_throttle_fuel_cut_fuel_resume_in_neutral_threshold7_00069768);
    DAT_ffffa830 = extraout_fr0;
  }
  return puVar1;
}


