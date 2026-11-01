/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a768: Table 2D - 160 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a77c: Table 2D - 161 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0002cde2; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d486 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDesiredTorqueCalcVar3(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)lookup_2d_descriptor_scaled(inferred_ram_ad48_ffffad48_ffffad48,&tbl_table_2d_161_0006a77c);
  fVar2 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_160_0006a768);
  fVar2 = rx8_max_float(fVar2 - DAT_ffffbcb8,0.0);
  DAT_ffffbcbc = fVar1 * fVar2;
  return;
}


