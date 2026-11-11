/* [ADDITIONAL SOURCE REVIEW]
 * maf_filtered_update [high]: mass_air_flow a9ec = a9e8 (scaled/latched MAF); a9f4 = a9e8. | promoted to high (data/labels/60E15120_N3J1E/fueling_labels.json/function_aliases)
 */
/* ROM address: 0x00019f40; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001aca0 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void maf_filtered_update(void)

{
  mass_air_flow_ffffa9ec = maf_scaled_latched_ffffa9e8;
  DAT_ffffa9f4 = maf_scaled_latched_ffffa9e8;
  return;
}


