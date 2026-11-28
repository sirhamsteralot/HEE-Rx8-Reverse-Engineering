/* [ADDITIONAL SOURCE REVIEW]
 * misfire_window_400_tick [high]: DAT_ffffba9c = 0 when DAT_ffffd1c5==1; else wraps at 400 (0x190) and increments (rx8_add_u16_saturate 0x2460) only while b69c==1. Pools: 0x28ba0=0x0190, 0x28ba8=0x2460. Called from 0x287aa.
 * RAM 0xffffba9c misfire_window_400 (uint16): 400-tick window counter (wraps at 400 = 0x190) counted while b69c==1, zeroed on d1c5; the 400-tick evaluation fires at ==400 (0x26aa0/0x44b16/0x44b46).
 */
/* ROM address: 0x00028b10; body bytes: 64; decompiled */

uint misfire_window_400_tick(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    misfire_window_400_ffffba9c = 0;
    uVar1 = 1;
  }
  else {
    if (399 < misfire_window_400_ffffba9c) {
      misfire_window_400_ffffba9c = 0;
    }
    uVar1 = (uint)misfire_supply_enable_ffffb69c;
    if (uVar1 == 1) {
      uVar1 = rx8_add_u16_saturate((int)(short)misfire_window_400_ffffba9c,1);
      misfire_window_400_ffffba9c = (ushort)uVar1;
    }
  }
  return uVar1;
}


