/* [ADDITIONAL SOURCE REVIEW]
 * load_delta_enrichment [high]: c138 = tbl 0x6b124(load delta c158); c13c = tbl 0x6b0c0(load); c134 = c138*1.0*c13c when c158 >= 0 else 0; c140 = 3D tip-in tbl 0x6b160 (or 0x6b17c when warmup c010) (rpm, coolant); injectors off (a42c) -> c140 = 0; c110 decays toward 1.0 at -0.0078125 when c14c set.
 * RAM 0xffffc158 load_delta_input (float): c158 = load delta input; c134 = tbl 0x6b124(c158) * tbl 0x6b0c0(load) when c158 >= 0.
 * RAM 0xffffc138 load_delta_scale (float): c138 = lookup_2d tbl 0x6b124(c158).
 * RAM 0xffffc13c load_scale_2d (float): c13c = lookup_2d tbl 0x6b0c0(engine_load).
 * RAM 0xffffc134 load_delta_enrichment (float): c134 = c138 * c13c (0 when load delta < 0).
 * RAM 0xffffc110 tip_in_decay (float): c110 = max(c110 - 0.0078125, 1.0) when c14c set.
 * RAM 0xffffc140 tip_in_enrichment (float): c140 = 3D tbl 0x6b160 (or 0x6b17c when warmup c010)(rpm, coolant); 0 when injectors off.
 * RAM 0xffffc14c tip_in_mode_flag (uint8): c14c gates the c110 decay in load_delta_enrichment.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b0c0: Table 2D - 216 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b124: Table 2D - 219 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b160: Table 3D - 79 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b17c: Table 3D - 80 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00033ec4; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000345f0 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 load_delta_enrichment(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  undefined4 uVar3;
  float snapshot_load_delta_input_ffffc158;
  
  snapshot_load_delta_input_ffffc158 = load_delta_input_ffffc158;
  load_delta_scale_ffffc138 = (float)lookup_2d_descriptor_scaled(load_delta_input_ffffc158,&tbl_table_2d_219_0006b124);
  load_scale_2d_ffffc13c = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_table_2d_216_0006b0c0);
  uVar3 = 0;
  if (0.0 <= snapshot_load_delta_input_ffffc158) {
    load_delta_enrichment_ffffc134 = load_delta_scale_ffffc138 * 1.0 * load_scale_2d_ffffc13c;
  }
  else {
    load_delta_enrichment_ffffc134 = 0.0;
  }
  if (tip_in_mode_flag_ffffc14c == '\x01') {
    tip_in_decay_ffffc110 = rx8_max_float(tip_in_decay_ffffc110 - 0.0078125,1.0);
  }
  if (engine_injectors_off_ffffa42c == '\x01') {
    uVar1 = 1;
    tip_in_enrichment_ffffc140 = uVar3;
  }
  else {
    if (warmup_complete_flag_ffffc010 == '\x01') {
      puVar2 = &tbl_table_3d_80_0006b17c;
    }
    else {
      puVar2 = &tbl_table_3d_79_0006b160;
    }
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,puVar2);
    tip_in_enrichment_ffffc140 = extraout_fr0;
  }
  return uVar1;
}


