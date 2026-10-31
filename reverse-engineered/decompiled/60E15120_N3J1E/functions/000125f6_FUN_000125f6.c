/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_apply_trailing [high]: Trailing mirror of 0x125bc using a738/a6b0/a754/c9a4/b28c and idle/base term a5e4 (writer not identified) -> a658.
 * RAM 0xffffa738 knock_retard_mirror (float): Copy of clamped a734 written by 0x13a60/0x13b40; consumed by 0x125f6 trailing apply.
 * RAM 0xffffa6b0 rough_knock_correction_trailing (float): Trailing counterpart; subtracted in 0x125f6.
 * RAM 0xffffa754 coolant_timing_derate_trailing (float): Trailing counterpart (a770 * fVar2).
 * RAM 0xffffb28c ac_compressor_trailing_timing_retard (float): Trailing counterpart (0x215f8).
 * RAM 0xffffc9a4 cold_start_timing_reduction_trailing (float): Trailing mirror set in 0x12754.
 */
/* ROM address: 0x000125f6; body bytes: 58; decompiled */

void knock_retard_apply_trailing(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = knock_retard_mirror_ffffa738 - rough_knock_correction_trailing_ffffa6b0;
  fVar1 = rx8_max_float(coolant_timing_derate_trailing_ffffa754,cold_start_timing_reduction_trailing_ffffc9a4);
  trailing_timing_correction_total_ffffa658 = ((fVar2 - fVar1) + DAT_ffffa5e4 + ac_compressor_trailing_timing_retard_ffffb28c) - DAT_ffffa670;
  return;
}


