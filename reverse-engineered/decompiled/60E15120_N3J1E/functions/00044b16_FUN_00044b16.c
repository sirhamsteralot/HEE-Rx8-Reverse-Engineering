/* [ADDITIONAL SOURCE REVIEW]
 * misfire_400_threshold [medium]: At DAT_ffffba9c == 400: DAT_ffffcba2 = 100 when DAT_ffffcf90 < 0.0, else DAT_ffffcb84. Called from 0x287aa.
 */
/* ROM address: 0x00044b16; body bytes: 48; decompiled */

void candidate_misfire_400_threshold(void)

{
  if (misfire_window_400_ffffba9c == 400) {
    if (DAT_ffffcf90 < 0.0) {
      DAT_ffffcba2 = 100;
    }
    else {
      DAT_ffffcba2 = DAT_ffffcb84;
    }
  }
  return;
}


