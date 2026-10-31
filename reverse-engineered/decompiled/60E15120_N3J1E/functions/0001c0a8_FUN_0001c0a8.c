/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000698f8: Table 2D - 68 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001c0a8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001cb58 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001c0a8(void)

{
  DAT_ffffadec = 0x3f800000;
  DAT_ffffadf0 = 0x3f800000;
  DAT_ffffadf4 = 0x3f800000;
  DAT_ffffb064 = 0xff;
  DAT_ffffb065 = 0xff;
  DAT_ffffb000 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_2d_68_000698f8);
  return;
}


