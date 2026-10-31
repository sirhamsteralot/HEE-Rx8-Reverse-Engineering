/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ad58: Table 2D - 193 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00031624; body bytes: 172; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00031654) */
/* WARNING: Removing unreachable block (ram,0x0003165c) */
/* WARNING: Removing unreachable block (ram,0x0003166a) */
/* WARNING: Removing unreachable block (ram,0x00031672) */
/* WARNING: Removing unreachable block (ram,0x0003167e) */
/* Unique exact-byte match to related 60E0FC00 function at 00031acc (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateSecondaryAirPumpEnirchment(void)

{
  float arg1;
  
  if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
    DAT_ffffbf64 = DAT_ffffbf48;
  }
  else {
    DAT_ffffbf64 = 0.0;
  }
  if (secondary_air_request_final_ffffa960 == '\0') {
    DAT_ffffbf40 = 0.0;
  }
  else {
    arg1 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_193_0006ad58);
    DAT_ffffbf40 = rx8_min_float(DAT_ffffbf64,arg1);
  }
  return;
}


