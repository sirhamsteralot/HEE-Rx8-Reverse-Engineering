/* [ADDITIONAL SOURCE REVIEW]
 * leading_timing_add_corrections [high]: a634 = a640 + a648: base leading timing plus total corrections.
 * RAM 0xffffa648 leading_timing_correction_total (float): Total leading correction written by 0x125bc; added to base in 0x123ba.
 */
/* ROM address: 0x000123ba; body bytes: 16; decompiled */

void leading_timing_add_corrections(void)

{
  leading_timing_with_corrections_ffffa634 = DAT_ffffa640 + leading_timing_correction_total_ffffa648;
  return;
}


