/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffbcf8 cruise_set_speed (float): Cruise set speed; copied to 0xffffcf18 and compared with vehicle speed 0xffffa9b4 for the enable flag 0xffffcf34 in 0x4c896.
 */
/* ROM address: 0x0004c896; body bytes: 46; decompiled */

void FUN_0004c896(void)

{
  DAT_ffffcf18 = cruise_set_speed_ffffbcf8;
  if ((DAT_ffffbced == '\0') || (cruise_set_speed_ffffbcf8 < DAT_ffffa9b4)) {
    DAT_ffffcf34 = 0;
  }
  else {
    DAT_ffffcf34 = 1;
  }
  return;
}


