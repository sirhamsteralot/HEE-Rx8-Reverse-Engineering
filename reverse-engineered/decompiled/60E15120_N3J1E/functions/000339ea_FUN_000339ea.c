/* [ADDITIONAL SOURCE REVIEW]
 * knock_state_reset_rpm_window [high]: 6500/7000 RPM hysteresis -> 0xc116(1) at/above 7000, 0xc116(0) below 6500; called from 0x19cf4 vehicle-speed task.
 */
/* ROM address: 0x000339ea; body bytes: 42; decompiled */

void knock_state_reset_rpm_window(void)

{
  if (7000.0 <= engine_speed_rpm_ffffb548) {
    reset_knock_state_on_mode_change(1);
    return;
  }
  if (engine_speed_rpm_ffffb548 < 6500.0) {
    reset_knock_state_on_mode_change(0);
    return;
  }
  return;
}


