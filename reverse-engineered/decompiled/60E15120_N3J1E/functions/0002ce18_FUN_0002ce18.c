/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a790: Table 2D - 162 (RX8Defs data pointer, axes and dimensions match).
 */
/* [RX8DEFS 2026-09-30 0002ce18]
 * Suggested interpretation: inferred_update_alternator_torque_estimate.
 * Confidence: lookup and ratio multiplication verified; torque units upstream.
 * Descriptor 6a790 (data 75cc8, five uint16 values) is indexed by inferred alternator speed ffffb598. Near-zero ffffb5a0 forces ffffbcc4 to zero; otherwise lookup result is multiplied by ffffb5a4/ffffb5a0 and assigned to ffffbcc4. This supports a speed-dependent maximum modulated by a ratio, but does not establish Nm or the ratio's physical meanings.
 */
/* ROM address: 0x0002ce18; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d4bc (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0002ce18(void)

{
  char cVar2;
  undefined4 uVar1;
  float extraout_fr0;
  float fVar3;
  
  fVar3 = 0.0;
  uVar1 = DAT_ffffb5a0;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffb5a0,0,0x3727c5ac);
  if (cVar2 == '\0') {
    uVar1 = 0;
    DAT_ffffbcc4 = fVar3;
  }
  else {
    fVar3 = (float)lookup_2d_descriptor_scaled(inferred_alternator_speed_ffffb598,&tbl_table_2d_162_0006a790);
    uVar1 = rx8_divide_with_zero_fallback(DAT_ffffb5a4,uVar1);
    DAT_ffffbcc4 = fVar3 * extraout_fr0;
  }
  return uVar1;
}


