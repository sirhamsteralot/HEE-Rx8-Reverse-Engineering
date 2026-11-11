/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a830: Table 2D - 163 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_iat_comp [medium]: 0xffffa8c0 = tbl 0x6a830(IAT 0xffffaddc). Called from 0x167c0 via pool 0x168d8.
 */
/* ROM address: 0x00016720; body bytes: 20; decompiled */

void candidate_idle_iat_comp(void)

{
  DAT_ffffa8c0 = lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&tbl_table_2d_163_0006a830);
  return;
}


