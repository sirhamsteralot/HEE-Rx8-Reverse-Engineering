/* [ADDITIONAL SOURCE REVIEW]
 * misfire_window_2000_tick [high]: DAT_ffffba9e = 0 and DAT_ffffbaa0 = 1 when DAT_ffffd1c5==1; else wraps at 2000 (0x7d0) and increments while b69c==1. The 400/2000 evaluations fire at ba9c==400 / ba9e==2000 (0x26aa0, 0x44b16/0x44b46, 0x4458a/0x445ba). Called from 0x287aa.
 * RAM 0xffffba9e misfire_window_2000 (uint16): 2000-tick window counter (wraps at 2000 = 0x7d0) counted while b69c==1; the 2000-tick evaluation fires at ==2000 (0x26aa0/0x4458a/0x445ba).
 */
/* ROM address: 0x00028b50; body bytes: 70; decompiled */

uint misfire_window_2000_tick(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    misfire_window_2000_ffffba9e = 0;
    DAT_ffffbaa0 = 1;
    uVar1 = 1;
  }
  else {
    if (1999 < misfire_window_2000_ffffba9e) {
      misfire_window_2000_ffffba9e = 0;
    }
    uVar1 = (uint)misfire_supply_enable_ffffb69c;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u16_saturate((int)(short)misfire_window_2000_ffffba9e,1);
      misfire_window_2000_ffffba9e = (ushort)uVar1;
    }
  }
  return uVar1;
}


