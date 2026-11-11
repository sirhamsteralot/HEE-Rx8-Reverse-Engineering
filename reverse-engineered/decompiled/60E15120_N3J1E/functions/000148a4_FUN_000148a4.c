/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000692bc: Table 2D - 16 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_target_term_lookup [medium]: 0xffffa7a0 = tbl 0x692bc(0xffffa7ac). Called from 0x167c0 via pool 0x1688c.
 */
/* ROM address: 0x000148a4; body bytes: 20; decompiled */

void candidate_idle_target_term_lookup(void)

{
  DAT_ffffa7a0 = lookup_2d_descriptor_scaled(inferred_ram_a7ac_ffffa7ac_ffffa7ac,&tbl_table_2d_16_000692bc);
  return;
}


