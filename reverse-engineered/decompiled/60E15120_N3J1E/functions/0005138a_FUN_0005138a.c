/* ROM address: 0x0005138a; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004f03e (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005138a(void)

{
  if (engine_speed_rpm_ffffb548 < 1200.0) {
    if (engine_speed_rpm_ffffb548 < 1106.25) {
      DAT_ffffd0f6 = 0;
    }
  }
  else {
    DAT_ffffd0f6 = 1;
  }
  if (engine_speed_rpm_ffffb548 < 4000.0) {
    if (engine_speed_rpm_ffffb548 < 3906.25) {
      DAT_ffffd0f7 = 0;
    }
  }
  else {
    DAT_ffffd0f7 = 1;
  }
  return;
}


