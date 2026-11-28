/* [ADDITIONAL SOURCE REVIEW]
 * misfire_2000_threshold [high]: At DAT_ffffba9e == 2000 (0x7d0): DAT_ffffcb72 = 0xff when DAT_ffffcf90 < 0.0, else 100. Pools: 0x44674=0xba9e, 0x44676=0x07d0, 0x44680=0xffffcb72, 0x44678=0xcf90. Called from 0x287aa.
 * RAM 0xffffcb72 misfire_threshold_2000 (uint16): 2000-tick window threshold: 0xff when DAT_ffffcf90 < 0.0 else 100, written by 0x4458a at ba9e==2000; compared against b692 in 0x445ba.
 */
/* ROM address: 0x0004458a; body bytes: 48; decompiled */

void misfire_2000_threshold(void)

{
  if (misfire_window_2000_ffffba9e == 2000) {
    if (DAT_ffffcf90 < 0.0) {
      misfire_threshold_2000_ffffcb72 = 0xff;
    }
    else {
      misfire_threshold_2000_ffffcb72 = 100;
    }
  }
  return;
}


