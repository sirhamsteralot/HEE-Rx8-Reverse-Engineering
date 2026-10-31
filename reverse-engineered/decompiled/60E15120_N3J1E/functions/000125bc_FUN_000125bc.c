/* [ADDITIONAL SOURCE REVIEW]
 * knock_retard_apply_leading [high]: a648 = ((a734 - a6ac) - max(a750, c9a0)) + a5e0 + b288 - a66c: knock retard minus rough correction, minus max(coolant derate, cold-start reduction), plus idle/base term a5e0 (writer not identified in the export), plus A/C retard, minus trim a66c.
 * RAM 0xffffa6ac rough_knock_correction_leading (float): Leading rough knock correction from 0x13210 (inherited ref_roughKnockCorrection name; knock semantic unproven); subtracted in 0x125bc.
 * RAM 0xffffa750 coolant_timing_derate_leading (float): Coolant-based timing derate (leading) from 0x13ecc (a76c * fVar2); max() with cold-start c9a0 in 0x125bc.
 * RAM 0xffffb288 ac_compressor_leading_timing_retard (float): A/C compressor timing retard (leading): -5.0 deg while ramping else 0 (0x214f8).
 * RAM 0xffffc9a0 cold_start_timing_reduction_leading (float): Cold-start timing reduction (leading): min(c9a8, tbl 0x6b83c(RPM)) * clamp((ECT+30)*0.01, 0, 1) when ca44==1 && ca3f>1 (0x12630).
 */
/* ROM address: 0x000125bc; body bytes: 58; decompiled */

void knock_retard_apply_leading(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = knock_retard_ffffa734 - rough_knock_correction_leading_ffffa6ac;
  fVar1 = rx8_max_float(coolant_timing_derate_leading_ffffa750,cold_start_timing_reduction_leading_ffffc9a0);
  leading_timing_correction_total_ffffa648 = ((fVar2 - fVar1) + DAT_ffffa5e0 + ac_compressor_leading_timing_retard_ffffb288) - DAT_ffffa66c;
  return;
}


