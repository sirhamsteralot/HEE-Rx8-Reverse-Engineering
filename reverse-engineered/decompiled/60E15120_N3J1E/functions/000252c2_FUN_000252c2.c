/* [ADDITIONAL SOURCE REVIEW]
 * key_off_shutdown_state_machine [high]: Key-off state machine (called from 0x253e8, itself from slow task 0x11534): state in 0xffffb57a (pool 0x25380); engine flag 0xffffaa68 (pool 0x25378) == 1 && state 0 -> arm: 0xffffdf99 = 0x5a (pool 0x2537a=0xdf99), 0xffffb580 = 0, 0xffffb579 = 1 (pool 0x25374); engine stopped && state 0 -> state 1, 0xffffb578 = 1 (pool 0x2537c); counting: 0xffffb57c (u32, pool 0x2539c) ++ saturating at -1; state 2 when b57c >= u32 @ROM 0x74940 (pool 0x253a4=0x74940; ROM word = 0x36ee8) or when b57c >= 0x19 and 0xffffb582 (pool 0x2538c) <= 0xffffb583 (pool 0x25390): then state = 2, E2-shadow 0xffff8104 = 1 via 0x3dc70 (pools 0x25376=0x8104, 0x25384=0x3dc70), 0xffffb579 = 0, 0xffffdf99 = 0, jmp 0x9ea2 (pool 0x253a8=0x9ea2).
 * RAM 0xffffb57a key_off_state (uint8): Key-off state machine state: 0 = armed/key-on, 1 = engine stopped (counting), 2 = shutdown (0x252c2, pool 0x25380=0xffffb57a).
 * RAM 0xffffb578 engine_stopped_latch (uint8): Set 1 on the engine-stop transition by 0x252c2 (pool 0x2537c=0xb578); gates CAN RX/TX mains 0xdbf6/0xdb58 and CAN error recovery 0xdcc0.
 * RAM 0xffffb579 key_off_armed_flag (uint8): Armed flag of the key-off sequence (pool 0x25374=0xb579; init 1 in 0x25290).
 * RAM 0xffffb57c key_off_timer (uint32): Saturating u32 key-off timer (pool 0x2539c=0xffffb57c); shutdown when >= u32 @ROM 0x74940 = 0x36ee8 (pool 0x253a4=0x74940) or >= 0x19 with 0xffffb582 <= 0xffffb583.
 * RAM 0xffffdf99 key_off_marker_byte (uint8): Set to 0x5a when the key-off sequence arms, 0 on the shutdown transition (0x252c2, pool 0x2537a=0xdf99).
 */
/* ROM address: 0x000252c2; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025b4a (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * key_off_shutdown_state_machine(void)

{
  undefined1 *puVar1;
  
  if (engine_running_flag_ffffaa68 == '\x01') {
    if (key_off_state_ffffb57a != '\0') {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&shutdown_e2_shadow_flag_ffff8104,0);
      puVar1 = (undefined1 *)ref_whileLoop();
      return puVar1;
    }
    puVar1 = (undefined1 *)0x5a;
    key_off_marker_byte_ffffdf99 = 0x5a;
    DAT_ffffb580 = 0;
    key_off_armed_flag_ffffb579 = 1;
  }
  else if (key_off_state_ffffb57a == '\0') {
    key_off_timer_ffffb57c = 0;
    key_off_state_ffffb57a = '\x01';
    engine_stopped_latch_ffffb578 = 1;
    puVar1 = &engine_stopped_latch_ffffb578;
    DAT_ffffb580 = DAT_ffffb580 + 1;
  }
  else {
    if (key_off_timer_ffffb57c != 0xffffffff) {
      key_off_timer_ffffb57c = key_off_timer_ffffb57c + 1;
    }
    if ((0x36ee7 < key_off_timer_ffffb57c) ||
       ((puVar1 = (undefined1 *)((int)&vector_Slot_illegal + 1), 0x18 < key_off_timer_ffffb57c &&
        (puVar1 = &key_off_early_counter_b_ffffb583, key_off_early_counter_a_ffffb582 <= key_off_early_counter_b_ffffb583)))) {
      key_off_state_ffffb57a = 2;
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&shutdown_e2_shadow_flag_ffff8104,1);
      key_off_armed_flag_ffffb579 = 0;
      key_off_marker_byte_ffffdf99 = 0;
      puVar1 = (undefined1 *)shutdown_wait_key_pin_then_halt();
      return puVar1;
    }
  }
  return puVar1;
}


