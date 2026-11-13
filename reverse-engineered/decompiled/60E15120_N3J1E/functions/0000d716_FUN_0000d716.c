/* [ADDITIONAL SOURCE REVIEW]
 * crank_tick_flag_set [high]: Sets crank_tick_flag_ffffa3fc = 1; called from 0x5b3c (CMI10B); readers 0xd6e4/0xd70a.
 * RAM 0xffffa3fc crank_tick_flag (uint8): Set to 1 by 0xd716 inside CMI10B handler 0x5b3c; read by 0xd6e4/0xd70a.
 */
/* ROM address: 0x0000d716; body bytes: 8; decompiled */

void crank_tick_flag_set(void)

{
  crank_tick_flag_ffffa3fc = 1;
  return;
}


