/* [ADDITIONAL SOURCE REVIEW]
 * open_loop_changeover_enrichment [high]: b124 = 0 when b146 == 0, else tbl 0x69e00 'Open Loop Changeover Enrichment'(RPM); b124 feeds calc_fuel_volume_request (0x306e8) via max(ae10, b124).
 * RAM 0xffffb124 open_loop_changeover_enrichment (float): b124 = tbl 0x69e00 'Open Loop Changeover Enrichment'(RPM) when b146 != 0 else 0; feeds 0x306e8 via max(ae10, b124).
 */
/* ROM address: 0x0002024c; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00020cac (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void open_loop_changeover_enrichment(void)

{
  if (DAT_ffffb146 == 0) {
    open_loop_changeover_enrichment_ffffb124 = 0;
  }
  else {
    open_loop_changeover_enrichment_ffffb124 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_open_loop_changeover_enrichment_00069e00);
  }
  return;
}


