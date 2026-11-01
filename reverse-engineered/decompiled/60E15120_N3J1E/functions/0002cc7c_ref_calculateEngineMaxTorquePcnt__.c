/* ROM address: 0x0002cc7c; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d320 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_calculateEngineMaxTorquePcnt__(void)

{
  char cVar2;
  undefined4 *puVar1;
  
  cVar2 = rx8_is_outside_tolerance_band(idle_base_timing_leading_ffffa780,0,0x3727c5ac);
  puVar1 = (undefined4 *)(uint)cranking_active_ffffaa62_ffffaa62;
  if ((((puVar1 != (undefined4 *)0x1) || (cVar2 != '\0')) ||
      (puVar1 = &DAT_0002cd7c, 2000.0 <= engine_speed_rpm_ffffb548)) ||
     (puVar1 = (undefined4 *)(uint)inferred_ram_ce1c_ffffce1c_ffffce1c, puVar1 != (undefined4 *)0x1)) {
    DAT_ffffbca0 = DAT_ffffbc98 -
                   (dsc_mode_a_base_timing_ffffbc94 - leading_timing_with_corrections_ffffa634) * (dsc_mode_a_base_timing_ffffbc94 - leading_timing_with_corrections_ffffa634) * DAT_ffffbc90;
  }
  else {
    DAT_ffffbca0 = DAT_ffffbc9c;
  }
  return puVar1;
}


