/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a830: Table 2D - 163 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016720; body bytes: 20; decompiled */

void FUN_00016720(void)

{
  DAT_ffffa8c0 = lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&tbl_table_2d_163_0006a830);
  return;
}


