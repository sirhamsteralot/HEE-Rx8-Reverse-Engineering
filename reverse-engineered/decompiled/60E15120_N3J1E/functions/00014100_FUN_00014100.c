/* [ADDITIONAL SOURCE REVIEW]
 * idle_base_timing_select [high]: a780 = lookup_2d(tbl 0x69208) when cranking (aa62==1); else tbl 0x6921c if ECT<90 or load<0.5, else tbl 0x69230; mirrors to a784. Feeds the +a780/a784 term of the 0x123da/0x124d6 blend.
 */
/* ROM address: 0x00014100; body bytes: 86; decompiled */

void idle_base_timing_select(void)

{
  undefined *puVar1;
  
  if (DAT_ffffaa62 == '\x01') {
    DAT_ffffa780 = lookup_2d_descriptor_scaled(&DAT_00069208);
  }
  else {
    if ((inferred_coolant_temperature_ffffa98c < 90.0) || (engine_load_ffffc0b4 < 0.5)) {
      puVar1 = &DAT_0006921c;
    }
    else {
      puVar1 = &DAT_00069230;
    }
    DAT_ffffa780 = lookup_2d_descriptor_scaled(puVar1);
  }
  DAT_ffffa784 = DAT_ffffa780;
  return;
}


