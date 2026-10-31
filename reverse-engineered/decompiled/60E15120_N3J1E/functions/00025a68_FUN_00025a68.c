/* ROM address: 0x00025a68; body bytes: 56; decompiled */

void FUN_00025a68(void)

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


