/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a13c: Table 2D - 117 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016380; body bytes: 118; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001639a) */
/* Unique exact-byte match to related 60E0FC00 function at 00016184 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00016380(void)

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


