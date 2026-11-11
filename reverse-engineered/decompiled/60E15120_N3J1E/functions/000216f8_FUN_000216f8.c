/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a218: Table 2D - 121 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a22c: Table 2D - 122 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a240: Table 2D - 123 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * idle_air_output_clamp [high]: Final idle air output: 0xffffb2a4 = clamp(tbl 0x6a218(0xffffa838), tbl 0x6a240(coolant), tbl 0x6a22c(coolant)) via 0x2404 rx8_clamp_float; pool 0x21740-0x2175c (classified mixed_pool) words: 0x21744=0x2068 (lookup helper), 0x21748=0x6a218, 0x2174c=0x6a240, 0x21750=0xffffb2a8, 0x21754=0x6a22c, 0x21758=0xffffb2ac, 0x2175c=0x2404 (clamp); descriptors parsed (0x6a218 n=21 type 4 axis 0x732dc data 0x73330; 0x6a22c n=13 axis 0x73348 data 0x7337c; 0x6a240 n=13 axis 0x7338c data 0x733c0). 0xffffb2a4 is read by 0x21a80 ref_throttlePlatePosToTorqueOutput_ (pool 0x21b10 at 0x21a88) - the electronic-throttle torque chain, plus 0x1b940/0x233ec/0x29d4c/0x48558.
 * RAM 0xffffb2a4 idle_air_required (float): Clamped idle air output of 0x216f8: clamp(tbl 0x6a218(a838), tbl 0x6a240(coolant), tbl 0x6a22c(coolant)). Read by 0x21a80 ref_throttlePlatePosToTorqueOutput_ (pool 0x21b10 at 0x21a88 -> electronic throttle torque chain, terminals 1B/1C), also 0x1b940/0x233ec/0x29d4c/0x48558.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000216f8; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022064 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void idle_air_output_clamp(void)

{
  float arg0;
  undefined4 snapshot_inferred_coolant_temperature_ffffa990;
  
  snapshot_inferred_coolant_temperature_ffffa990 = inferred_coolant_temperature_ffffa990;
  arg0 = (float)lookup_2d_descriptor_scaled(idle_air_calc_total_ffffa838,&tbl_table_2d_121_0006a218);
  DAT_ffffb2a8 = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_123_0006a240);
  DAT_ffffb2ac = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa990,&tbl_table_2d_122_0006a22c);
  idle_air_required_ffffb2a4 = rx8_clamp_float(arg0,DAT_ffffb2a8,DAT_ffffb2ac);
  return;
}


