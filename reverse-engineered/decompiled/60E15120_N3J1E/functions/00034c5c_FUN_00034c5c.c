/* [ADDITIONAL SOURCE REVIEW]
 * immo_state0_idle [high]: Main state 0 handler. c21e==3 -> c21d=1 and run state1 (0x34d12); c21e==1 -> run 0x34e68; c21f>1 -> FUN_00035738(0xc6); c20c timeout -> ImmoBadStateSet + c224=0 + TX cmd 1 + c22a=1.
 * RAM 0xffffc20c immo_timer_a (u16): set 500 on entry to challenge states; expiry -> bad state
 */
/* ROM address: 0x00034c5c; body bytes: 114; decompiled */

uint immo_state0_idle(void)

{
  uint uVar1;
  
  uVar1 = (uint)immo_command_substate_ffffc21e;
  if (uVar1 == 3) {
    immo_main_state_ffffc21d = 1;
    uVar1 = immo_state1_key_exchange();
    return uVar1;
  }
  if (uVar1 == 1) {
    uVar1 = immo_wait_for_key_step();
    return uVar1;
  }
  if (1 < immo_fail_counter_ffffc21f) {
    immo_fail_counter_ffffc21f = 0;
    uVar1 = immo_tx_frame_build(0xc6);
  }
  if (immo_timer_a_ffffc20c != 0) {
    immo_timer_a_ffffc20c = immo_timer_a_ffffc20c + -1;
  }
  if (immo_timer_a_ffffc20c == 0) {
    immo_set_rejected();
    immo_status_code_ffffc224 = 0;
    uVar1 = immo_tx_frame_build(1);
    immo_reject_event_flag_ffffc22a = 1;
  }
  return uVar1;
}


