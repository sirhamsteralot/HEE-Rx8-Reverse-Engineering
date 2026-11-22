/* [ADDITIONAL SOURCE REVIEW]
 * idle_aux_air_term [medium]: When 0xffffb2f6==1: 0xffffa89c = clamp(0xffffb1dc * 0.6345 * tbl 0x6a13c(0xffffb220) * 60 / rpm, 0, 0.2), else 0. Called from 0x167c0 via pool 0x168d4.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a13c: Table 2D - 117 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016380; body bytes: 118; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001639a) */
/* Unique exact-byte match to related 60E0FC00 function at 00016184 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_idle_aux_air_term(void)

{
  uint uVar1;
  uint extraout_r0;
  float arg0;
  float arg1;
  
  uVar1 = (uint)DAT_ffffb2f6;
  arg1 = 0.0;
  if (uVar1 == 1) {
    DAT_ffffa8a0 = (float)lookup_2d_descriptor_scaled(DAT_ffffb220,&tbl_table_2d_117_0006a13c);
    arg0 = (float)rx8_divide_with_zero_fallback
                            (DAT_ffffb1dc * 0.6345 * DAT_ffffa8a0 * 60.0,engine_speed_rpm_ffffb548);
    DAT_ffffa89c = rx8_clamp_float(arg0,arg1,0.2);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa89c = 0.0;
  }
  return uVar1;
}


