/* [ADDITIONAL SOURCE REVIEW]
 * trailing_timing_add_corrections [high]: a63c = a650 + a658: base trailing timing plus total corrections.
 * RAM 0xffffa658 trailing_timing_correction_total (float): Total trailing correction from 0x125f6; added in 0x123ca.
 */
/* ROM address: 0x000123ca; body bytes: 16; decompiled */

void trailing_timing_add_corrections(void)

{
  trailing_timing_with_corrections_ffffa63c = DAT_ffffa650 + trailing_timing_correction_total_ffffa658;
  return;
}


