/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b850: Table 2D - 274 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000429fc; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042230 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateThrottlePercentDuringLift(void)

{
  float fVar1;
  float snapshot_inferred_ram_a9bc_ffffa9bc_ffffa9bc;
  
  if (((DAT_ffffca46 == '\x01') && (DAT_ffffca98 < 4)) || (cranking_active_ffffaa62_ffffaa62 == '\x01')) {
    if ((DAT_ffffca48 == '\x01') || (cranking_active_ffffaa62_ffffaa62 == '\x01')) {
      DAT_ffffca34 = inferred_ram_a9bc_ffffa9bc_ffffa9bc;
    }
    else {
      snapshot_inferred_ram_a9bc_ffffa9bc_ffffa9bc = inferred_ram_a9bc_ffffa9bc_ffffa9bc;
      fVar1 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_274_0006b850);
      DAT_ffffca34 = snapshot_inferred_ram_a9bc_ffffa9bc_ffffa9bc - fVar1;
    }
  }
  DAT_ffffca98 = DAT_ffffca41;
  return;
}


