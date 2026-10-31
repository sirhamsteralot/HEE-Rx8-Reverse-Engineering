/* [ADDITIONAL SOURCE REVIEW]
 * knock_condition_snapshots_init [high]: Resets knock state via 0xc116(0); stores snapshots c06c/c070/c074 (RPM/load/throttle), c098/c09c/c0a0 and constants.
 */
/* ROM address: 0x000335e4; body bytes: 78; decompiled */

void knock_condition_snapshots_init(void)

{
  reset_knock_state_on_mode_change(0);
  DAT_ffffc06c = engine_speed_rpm_ffffb548;
  DAT_ffffc070 = engine_load_ffffc0b4;
  DAT_ffffc074 = DAT_ffffad48;
  knock_filter_coeff_a_ffffc060 = 0x3d800000;
  knock_filter_coeff_b_ffffc064 = 0x3e004ea5;
  knock_filter_coeff_c_ffffc068 = 0x3d000000;
  DAT_ffffc09c = engine_load_ffffc0b4;
  DAT_ffffc098 = engine_speed_rpm_ffffb548;
  DAT_ffffc0a0 = DAT_ffffad48;
  return;
}


