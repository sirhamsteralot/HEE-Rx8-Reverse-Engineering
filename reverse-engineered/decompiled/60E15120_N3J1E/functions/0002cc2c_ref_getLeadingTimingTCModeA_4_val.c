/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_a_base_timing_lookup [high]: was ref_getLeadingTimingTCModeA_4_val. bc94 = lookup_3d(load, rpm, tbl 0x6a7a4 'Ignition Timing Leading - DSC Mode A - Base'). Consumed by 0x1815c and torque-loss calc 0x2cc5c/0x2cc7c ((bc94 - actual)^2 * bc90).
 * RAM 0xffffbc94 dsc_mode_a_base_timing (float): mov.w pool 0x2cd44 (sign-extends to 0xffffbc94) in 0x2cc2c dsc_mode_a_base_timing_lookup (also 0x2cc5c/0x2cc7c), pool 0x18278 in 0x1815c; = lookup_3d(load, rpm, tbl 0x6a7a4) stored by 0x2cc2c.
 */
/* ROM address: 0x0002cc2c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d2d0 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void dsc_mode_a_base_timing_lookup(void)

{
  dsc_mode_a_base_timing_ffffbc94 = lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_ignition_timing_leading_dsc_mode_a_base_0006a7a4);
  return;
}


