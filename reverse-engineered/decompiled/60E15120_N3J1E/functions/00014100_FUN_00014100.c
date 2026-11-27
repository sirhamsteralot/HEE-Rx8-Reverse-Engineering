/* [ADDITIONAL SOURCE REVIEW]
 * idle_base_timing_select [high]: With 0xffffaa62 == 1 (cmp/eq at 0x14112) 0xffffa780 (pool 0x14158) = scaled lookup of coolant against descriptor 0x69208 (pool 0x14164; data 0x6d8e4 = 80 in every cell, scale 0.5 offset -40 -> constant 0.0 deg); otherwise 0x6921c when coolant < f32 0x6d8bc = 90.0 or load < f32 0x6d8b8 = 0.5, else 0x69230. Mirrors into 0xffffa784. Called from 0x1465e at 0x1466a (task[11] body 0x6584), not from 0x142a4.
 * RAM 0xffffa780 idle_base_timing_leading (float): Written by 0x14100 idle_base_timing_select (fmov.s fr0,@r14 0x14120 and 0x14146 via mov.w pool 0x14158=0xa780 @0x1410a); read by 0x123da (pool 0x1253c @0x124b4) and 0x121fc (pool 0x122b8 @0x12200).
 * RAM 0xffffa784 idle_base_timing_trailing (float): Written by 0x14100 idle_base_timing_select (fmov.s fr3,@r3 0x1414c via mov.w pool 0x1415e=0xa784 @0x1414a); read by 0x124d6 (pool 0x1268a @0x12598) and 0x12300 (pool 0x123fe @0x12304).
 */
/* ROM address: 0x00014100; body bytes: 86; decompiled */

void idle_base_timing_select(void)

{
  undefined *puVar1;
  
  if (cranking_active_ffffaa62_ffffaa62 == '\x01') {
    idle_base_timing_leading_ffffa780 = lookup_2d_descriptor_scaled(&candidate_tbl_idle_base_timing_cranking_00069208);
  }
  else {
    if ((inferred_coolant_temperature_ffffa98c < 90.0) || (engine_load_ffffc0b4 < 0.5)) {
      puVar1 = &candidate_tbl_idle_base_timing_cold_lowload_0006921c;
    }
    else {
      puVar1 = &candidate_tbl_idle_base_timing_warm_highload_00069230;
    }
    idle_base_timing_leading_ffffa780 = lookup_2d_descriptor_scaled(puVar1);
  }
  idle_base_timing_trailing_ffffa784 = idle_base_timing_leading_ffffa780;
  return;
}


