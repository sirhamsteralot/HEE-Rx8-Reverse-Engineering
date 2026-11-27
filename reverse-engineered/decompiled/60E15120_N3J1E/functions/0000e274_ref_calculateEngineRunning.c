/* [ADDITIONAL SOURCE REVIEW]
 * engine_running_from_rpm [high]: Sets byte 0xffffa428 (pool 0xe29e) from rpm 0xffffb548 (pool 0xe29c): 0 below f32 0x6c190 = 250.0 (pool 0xe2a0), 1 at f32 0x6c194 = 500.0 and above (pool 0xe2a4), held in between.
 * RAM 0xffffb548 engine_speed_rpm (float): Engine speed in rpm. The start thresholds 250/300/500 rpm and the timing-fade thresholds (0xffffa7ac + 10000.0, minus 100.0) all compare against this cell (pools 0x14884, 0xe29c, 0x123fc).
 */
/* ROM address: 0x0000e274; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e278 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void engine_running_from_rpm(void)

{
  if (250.0 <= engine_speed_rpm_ffffb548) {
    if (500.0 <= engine_speed_rpm_ffffb548) {
      engine_running_ffffa428 = 1;
    }
  }
  else {
    engine_running_ffffa428 = 0;
  }
  return;
}


