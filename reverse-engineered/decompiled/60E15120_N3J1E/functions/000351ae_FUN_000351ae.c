/* [ADDITIONAL SOURCE REVIEW]
 * immo_state4_transition [medium]: Main state 4 handler. c21e==0 && c21c==1 -> c21d=5, run state5 (0x35258); c21e==1 -> c20c=500, c226=0, 0x34e68; else c214 timeout -> c226=1 and if c21c==1 -> c21d=5/state5.
 */
/* ROM address: 0x000351ae; body bytes: 120; decompiled */

uint candidate_immo_state4_transition(void)

{
  uint uVar1;
  
  uVar1 = (uint)immo_command_substate_ffffc21e;
  if (uVar1 == 0) {
    immo_authorized_latch_flag_ffffc226 = 1;
    uVar1 = (uint)immo_ready_engine_off_pending_ffffc21c;
    if (uVar1 == 1) {
      immo_main_state_ffffc21d = 5;
      uVar1 = candidate_immo_state5_ready_engine_off();
      return uVar1;
    }
  }
  else {
    if (uVar1 == 1) {
      immo_timer_a_ffffc20c = 500;
      immo_authorized_latch_flag_ffffc226 = 0;
      uVar1 = immo_wait_for_key_step();
      return uVar1;
    }
    immo_command_substate_ffffc21e = 5;
    if (DAT_ffffc214 != 0) {
      DAT_ffffc214 = DAT_ffffc214 + -1;
    }
    if (DAT_ffffc214 == 0) {
      immo_authorized_latch_flag_ffffc226 = 1;
      uVar1 = (uint)immo_ready_engine_off_pending_ffffc21c;
      if (uVar1 == 1) {
        immo_main_state_ffffc21d = 5;
        uVar1 = candidate_immo_state5_ready_engine_off();
        return uVar1;
      }
    }
  }
  return uVar1;
}


