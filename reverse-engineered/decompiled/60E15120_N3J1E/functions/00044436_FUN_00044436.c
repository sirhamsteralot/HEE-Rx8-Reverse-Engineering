/* [ADDITIONAL SOURCE REVIEW]
 * misfire_sustained_window [high]: Sustained-event window: if load within [DAT_ffffba50, DAT_ffffba80] && DAT_ffffb69c==1 && DAT_ffffb53a==0 && (4000<=rpm || vehicle_speed<0) == false && !(DAT_ffffb694==0 && DAT_ffffcb68==0): bumps DAT_ffffcb60/0xffffcb62 (saturate 1000); DAT_ffffcb68 = 0x28 when DAT_ffffb694 else decays. Called from 0x287aa.
 * RAM 0xffffcb60 misfire_sustained_counter_a (uint16): Sustained-event counters DAT_ffffcb60/0xffffcb62 bumped by 0x44436 (saturate 1000) while the misfire window conditions hold; consumed by 0x273d4/0x445ba.
 * RAM 0xffffcb62 misfire_sustained_counter_b (uint16): Second sustained counter (0x44436); compared in the 2000-tick evaluation 0x445ba (uVar2 < cb62).
 * RAM 0xffffcb68 misfire_sustained_decay (uint8): Set to 0x28 by 0x44436 when any event fired this tick (b694), decays otherwise; part of the sustained-window gate.
 */
/* ROM address: 0x00044436; body bytes: 226; decompiled */

undefined4 * misfire_sustained_window(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = misfire_any_event_tick_ffffb694;
  puVar2 = (undefined4 *)(uint)DAT_ffffd1c5;
  if (puVar2 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
    misfire_sustained_counter_a_ffffcb60 = 0;
    misfire_sustained_counter_b_ffffcb62 = 0;
    misfire_sustained_decay_ffffcb68 = 0;
  }
  else {
    if ((((DAT_ffffcb64 <= misfire_deviation_now_ffffba50) && (misfire_deviation_now_ffffba50 <= misfire_threshold_b_ffffba80)) &&
        (puVar2 = (undefined4 *)(uint)misfire_supply_enable_ffffb69c,
        puVar2 == (undefined4 *)((int)&vector_Poweron_Reset + 1))) &&
       ((puVar2 = (undefined4 *)(int)DAT_ffffb53a, puVar2 == (undefined4 *)0x0 &&
        (((4000.0 <= engine_speed_rpm_ffffb548 || (puVar2 = &DAT_0007bf5c, vehicle_speed_ffffbbb4 < 0.0)) ||
         ((misfire_any_event_tick_ffffb694 == '\0' && (misfire_sustained_decay_ffffcb68 == 0)))))))) {
      if (misfire_sustained_counter_a_ffffcb60 < 1000) {
        puVar2 = (undefined4 *)rx8_add_u16_saturate((int)(short)misfire_sustained_counter_a_ffffcb60,1);
        misfire_sustained_counter_a_ffffcb60 = (ushort)puVar2;
      }
      else {
        misfire_sustained_counter_a_ffffcb60 = 1000;
      }
      if (misfire_sustained_counter_b_ffffcb62 < 1000) {
        puVar2 = (undefined4 *)rx8_add_u16_saturate((int)(short)misfire_sustained_counter_b_ffffcb62,1);
        misfire_sustained_counter_b_ffffcb62 = (ushort)puVar2;
      }
      else {
        misfire_sustained_counter_b_ffffcb62 = 1000;
      }
    }
    if (cVar1 == '\0') {
      if (misfire_sustained_decay_ffffcb68 != 0) {
        misfire_sustained_decay_ffffcb68 = misfire_sustained_decay_ffffcb68 + -1;
      }
    }
    else {
      misfire_sustained_decay_ffffcb68 = 0x28;
    }
  }
  return puVar2;
}


