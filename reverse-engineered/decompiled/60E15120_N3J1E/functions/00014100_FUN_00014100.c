/* [ADDITIONAL SOURCE REVIEW]
 * idle_base_timing_select [high]: a780 = lookup_2d(tbl 0x69208) when cranking (aa62==1); else tbl 0x6921c if ECT<90 or load<0.5, else tbl 0x69230; mirrors to a784. Feeds the +a780/a784 term of the 0x123da/0x124d6 blend.
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


