/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ac4c: Table 2D - 182 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * calculate_fuel_amount_per_rotation [high]: Per-injector fuel amounts per rotation: bec8/beec/bed8/bedc/bee0 from injector temp multipliers (bde4/bde8/bdec) * flow rates (be0c/be10/be14) * 6e7/rpm * (tbl 0x6ac4c/360) * 369.472/475.93, minus latencies be40/be44; bee4/bee8 = divide-with-zero-fallback ratios.
 * RAM 0xffffbec8 fuel_amount_per_rotation_a (float): bec8 = fuel amount per rotation (bde4*be0c path) * tbl 0x6ac4c/360 * 369.472; per-injector amounts computed in calculate_fuel_amount_per_rotation.
 * RAM 0xffffbeec fuel_amount_per_rotation_b (float): beec = (bdec*be14 path) * 475.93; see 0x30948.
 * RAM 0xffffbed8 fuel_amount_per_rotation_c (float): bed8 = (6e7/rpm - 608 - be40) / fVar7 * 369.472; latency-compensated variant.
 * RAM 0xffffbedc fuel_amount_per_rotation_d (float): bedc = (6e7/rpm - 608 - be44) / fVar4 * 475.93.
 * RAM 0xffffbee0 fuel_amount_per_rotation_e (float): bee0 = (6e7/rpm - 608 - be44) / fVar5 * 475.93.
 * RAM 0xffffbee4 fuel_ratio_a (float): bee4 = rx8_divide_with_zero_fallback(0x493e8ed3, fVar5); ratio derived from per-rotation amounts.
 * RAM 0xffffbee8 fuel_ratio_b (float): bee8 = rx8_divide_with_zero_fallback(0x48fafa8d, fVar4).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030948; body bytes: 346; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00030de4 (346 bytes). Names prefixed ref_
   are inherited hypotheses. */

void calculate_fuel_amount_per_rotation(void)

{
  float snapshot_DAT_ffffbe10;
  float snapshot_DAT_ffffbe14;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float snapshot_injector_latency_primary_ffffbe44;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  float fVar10;
  
  snapshot_DAT_ffffbe14 = DAT_ffffbe14;
  snapshot_DAT_ffffbe10 = DAT_ffffbe10;
  fVar4 = DAT_ffffbe0c;
  fVar5 = DAT_ffffbdec;
  fVar6 = DAT_ffffbde8;
  fVar3 = DAT_ffffbde4;
  snapshot_injector_latency_primary_ffffbe44 = injector_latency_primary_ffffbe44;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffbf18 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_182_0006ac4c);
  fVar10 = 6e+07;
  fVar7 = fVar3 * fVar4 * 6e+07;
  fVar4 = fVar7;
  fVar3 = (float)rx8_divide_with_zero_fallback(0x4c64e1c0,snapshot_engine_speed_rpm_ffffb548);
  fVar4 = (float)rx8_divide_with_zero_fallback(fVar3 * (DAT_ffffbf18 / 360.0),fVar4);
  fuel_amount_per_rotation_a_ffffbec8 = fVar4 * 369.472;
  fVar4 = fVar5 * snapshot_DAT_ffffbe14 * fVar10;
  fVar5 = (float)rx8_divide_with_zero_fallback(fVar10,snapshot_engine_speed_rpm_ffffb548);
  fVar5 = (float)rx8_divide_with_zero_fallback(fVar5 * (DAT_ffffbf18 / 360.0),fVar4);
  fuel_amount_per_rotation_b_ffffbeec = fVar5 * 475.93;
  fVar5 = (float)rx8_divide_with_zero_fallback(fVar10,snapshot_engine_speed_rpm_ffffb548);
  fVar5 = (float)rx8_divide_with_zero_fallback((fVar5 - 608.0) - injector_latency_secondary_ffffbe40,fVar7);
  fuel_amount_per_rotation_c_ffffbed8 = fVar5 * 369.472;
  fVar5 = fVar6 * snapshot_DAT_ffffbe10 * fVar10;
  fVar6 = (float)rx8_divide_with_zero_fallback(fVar10,snapshot_engine_speed_rpm_ffffb548);
  fVar6 = (float)rx8_divide_with_zero_fallback((fVar6 - 608.0) - snapshot_injector_latency_primary_ffffbe44,fVar5);
  fuel_amount_per_rotation_d_ffffbedc = fVar6 * 475.93;
  fVar6 = (float)rx8_divide_with_zero_fallback(fVar10,snapshot_engine_speed_rpm_ffffb548);
  fVar6 = (float)rx8_divide_with_zero_fallback((fVar6 - 608.0) - snapshot_injector_latency_primary_ffffbe44,fVar4);
  fuel_amount_per_rotation_e_ffffbee0 = fVar6 * 475.93;
  fuel_ratio_a_ffffbee4 = rx8_divide_with_zero_fallback(0x493e8ed3,fVar5);
  fuel_ratio_b_ffffbee8 = rx8_divide_with_zero_fallback(0x48fafa8d,fVar4);
  return;
}


