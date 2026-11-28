/* [ADDITIONAL SOURCE REVIEW]
 * misfire_fault_persistence [medium]: If rpm >= 660.0: b6be = 0. If engine not stopped (a41c==0) && b6be==1: b6a4 = 4, b6a6 = 0xf; else if b6ac==0: b6a4 = 0xff, b6a6 = 0xf; else if b6a4!=0: b6a4--. b6a4/b6a6 feed the supply gate 0x26fc0. Called from 0x287aa.
 */
/* ROM address: 0x00026f38; body bytes: 102; decompiled */

void candidate_misfire_fault_persistence(void)

{
  if (660.0 <= engine_speed_rpm_ffffb548) {
    DAT_ffffb6be = '\0';
  }
  if ((engine_stopped_latch_ffffa41c == '\0') && (DAT_ffffb6be == '\x01')) {
    DAT_ffffb6a4 = 4;
    DAT_ffffb6a6 = 0xf;
  }
  else if (DAT_ffffb6ac == '\0') {
    DAT_ffffb6a4 = 0xff;
    DAT_ffffb6a6 = 0xf;
  }
  else if (DAT_ffffb6a4 != 0) {
    DAT_ffffb6a4 = DAT_ffffb6a4 + -1;
  }
  return;
}


