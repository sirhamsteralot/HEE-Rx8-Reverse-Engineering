/* [ADDITIONAL SOURCE REVIEW]
 * misfire_counter_delay [high]: DAT_ffffcb80 = DAT_ffffcb78; DAT_ffffcb82 = DAT_ffffcb7c (one-tick delay of the rpm/load threshold counters). Pools: 0x4495e=0xcb78, 0x4495c... verified 0x4495e=0xcb78, 0x44960=0xcb80, 0x44962=0xcb82, 0x44956=0xcb7c. Called from 0x287aa.
 */
/* ROM address: 0x0004493a; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00044156 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void misfire_counter_delay(void)

{
  DAT_ffffcb80 = misfire_rpm_counter_a_ffffcb78;
  DAT_ffffcb82 = misfire_load_counter_a_ffffcb7c;
  return;
}


