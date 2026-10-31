/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b864: Table 2D - 275 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00043188; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000429bc (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getEngineSpeedRateOfChange(void)

{
  float fVar1;
  
  fVar1 = (float)lookup_2d_descriptor_scaled(DAT_ffffca28,&tbl_table_2d_275_0006b864);
  DAT_ffffc9f4 = rx8_max_float(((DAT_ffffc9fc - DAT_ffffc9f8) * fVar1) / DAT_ffffca10,0.0);
  return;
}


