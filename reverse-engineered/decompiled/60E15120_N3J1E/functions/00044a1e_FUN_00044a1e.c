/* [ADDITIONAL SOURCE REVIEW]
 * misfire_high_rpm_latch [medium]: DAT_ffffcb87 = 1 when 5000.0 <= rpm 0xffffb548; 0 when d1c5==1. Called from 0x287aa; gates the 400-tick fault branch 0x44b46.
 */
/* ROM address: 0x00044a1e; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004423a (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * candidate_misfire_high_rpm_latch(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb87 = 0;
    puVar1 = (undefined4 *)0x1;
  }
  else {
    puVar1 = &engine_speed_rpm_ffffb548;
    if (5000.0 <= engine_speed_rpm_ffffb548) {
      DAT_ffffcb87 = 1;
    }
  }
  return puVar1;
}


