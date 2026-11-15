/* [ADDITIONAL SOURCE REVIEW]
 * misfire_counter_bump [high]: If either event flag set: increments both u16 counters (saturate 0xff) and sets DAT_ffffb694 = 1, else DAT_ffffb694 = 0. Called from 0x26a42.
 * RAM 0xffffb694 misfire_any_event_tick (uint8): Set by 0x26b34 when any per-rotor event flag fired this tick; gates the sustained window 0x44436 (DAT_ffffcb68).
 */
/* ROM address: 0x00026b34; body bytes: 90; decompiled */

undefined4 FUN_00026b34(char param_1,char param_2,ushort *param_3,ushort *param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == '\x01') || (param_2 == '\x01')) {
    uVar1 = 1;
    if (*param_3 < 0xff) {
      uVar1 = rx8_add_u16_saturate((int)(short)*param_3,1);
      *param_3 = (ushort)uVar1;
    }
    if (*param_4 < 0xff) {
      uVar1 = rx8_add_u16_saturate((int)(short)*param_4,1);
      *param_4 = (ushort)uVar1;
    }
    misfire_any_event_tick_ffffb694 = 1;
  }
  else {
    uVar1 = 0;
    misfire_any_event_tick_ffffb694 = 0;
  }
  return uVar1;
}


