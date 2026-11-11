/* [ADDITIONAL SOURCE REVIEW]
 * idle_base_timing_select [high]: a780 = lookup_2d(tbl 0x69208) when cranking (aa62==1); else tbl 0x6921c if ECT<90 or load<0.5, else tbl 0x69230; mirrors to a784. Feeds the +a780/a784 term of the 0x123da/0x124d6 blend.
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


