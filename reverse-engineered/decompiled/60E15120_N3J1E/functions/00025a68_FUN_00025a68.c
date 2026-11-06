/* [ADDITIONAL SOURCE REVIEW]
 * alternator_speed_calc [high]: 0xffffb598 = engine_speed_rpm 0xffffb548 * 2.08 (belt ratio, f32 @ shared pool 0x74990); 0xffffb613 = alternator speed >= 859.0 (pool 0x74994, lower bound folded). Called from 0x267c6 via pool 0x26894.
 */
/* ROM address: 0x00025a68; body bytes: 56; decompiled */

void alternator_speed_calc(void)

{
  inferred_alternator_speed_ffffb598 = engine_speed_rpm_ffffb548 * 2.08;
  if (inferred_alternator_speed_ffffb598 < 859.0) {
    if (inferred_alternator_speed_ffffb598 < 800.406) {
      DAT_ffffb613 = 0;
    }
  }
  else {
    DAT_ffffb613 = 1;
  }
  return;
}


