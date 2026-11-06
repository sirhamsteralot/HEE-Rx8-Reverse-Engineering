/* [ADDITIONAL SOURCE REVIEW]
 * ch10b_compare_rearm [high]: OCR10B = tbl 0xd76d[0xffff9f95*2] & 0x7f, TCNT10B = 0, mirrors value to 0xffff9fc3 (decompiled + ROM table bytes). Per-sector tick interval.
 */
/* ROM address: 0x00007b58; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007b58 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ch10b_compare_rearm(void)

{
  ATUII_OCR10B_B = (&tbl_crank_sector_ocr10b_0000d76d)[(uint)crank_sector_index_ffff9f95 * 2] & 0x7f;
  ATUII_TCNT10B_B = 0;
  DAT_ffff9fc3 = (&tbl_crank_sector_ocr10b_0000d76d)[(uint)crank_sector_index_ffff9f95 * 2] & 0x7f;
  return;
}


