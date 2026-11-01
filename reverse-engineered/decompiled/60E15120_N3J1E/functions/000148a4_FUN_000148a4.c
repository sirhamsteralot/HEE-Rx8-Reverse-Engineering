/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000692bc: Table 2D - 16 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000148a4; body bytes: 20; decompiled */

void FUN_000148a4(void)

{
  DAT_ffffa7a0 = lookup_2d_descriptor_scaled(inferred_ram_a7ac_ffffa7ac_ffffa7ac,&tbl_table_2d_16_000692bc);
  return;
}


