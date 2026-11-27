/* [ADDITIONAL SOURCE REVIEW]
 * immobilizer_main_state_dispatch [high]: Called from can_rx_main_key_gated 0xdbf6 (callgraph). Body (298 B) verified in disassembly: gates on engine_running_flag 0xffffaa68==1 && engine_stopped_latch 0xffffb578!=1 (else clears c21d/c1d0/c1d1, lamp off); calls 0x35ea0 then 0x355f0 (the bsr at 0x34b10 is the immo-disable patch site); dispatches on main state DAT_ffffc21d: 0->0x34c5c, 1->0x34d12, 2->0x34f42, 3->0x35062, 4->0x351ae, 5->0x35258, else reset to 0; fail counter c21f increments when c21e in {5,6} && c226==0 && c229==0, 3 strikes set c1d1=1; tail calls afterImmoMain 0x36908 and 7 EEPROM-write sequencer steps.
 * RAM 0xffffc21d immo_main_state (u8): 0x34b14 reads it; handlers 0x34c5c/0x34d12/0x34f42/0x35062/0x351ae/0x35258 via bsr at 0x34b40/0x34b98/0x34ba0/0x34ba8/0x34bb0/0x34bb8
 * RAM 0xffffc21f immo_fail_counter (u8): counts consecutive c21e in {5,6} cycles with c226==0 && c229==0
 */
/* ROM address: 0x00034ae2; body bytes: 298; decompiled */

void immobilizer_main_state_dispatch(void)

{
  if ((engine_running_flag_ffffaa68 == '\x01') && (engine_stopped_latch_ffffb578 != '\x01')) {
    immo_eeprom_flag_sequencer();
    immo_can_command_decode();
    if (immo_main_state_ffffc21d == '\0') {
      immo_state0_idle();
    }
    else if (immo_main_state_ffffc21d == '\x01') {
      immo_state1_key_exchange();
    }
    else if (immo_main_state_ffffc21d == '\x02') {
      immo_state2_challenge_verify();
    }
    else if (immo_main_state_ffffc21d == '\x03') {
      immo_state3_authorized();
    }
    else if (immo_main_state_ffffc21d == '\x04') {
      candidate_immo_state4_transition();
    }
    else if (immo_main_state_ffffc21d == '\x05') {
      candidate_immo_state5_ready_engine_off();
    }
    else {
      immo_main_state_ffffc21d = '\0';
    }
    if ((((immo_command_substate_ffffc21e == '\x05') || (immo_command_substate_ffffc21e == '\x06')) && (immo_authorized_latch_flag_ffffc226 == '\0')) &&
       (DAT_ffffc229 == '\0')) {
      immo_fail_counter_ffffc21f = rx8_add_u8_saturate((int)(char)immo_fail_counter_ffffc21f,1);
    }
    else {
      immo_fail_counter_ffffc21f = 0;
    }
    if (2 < immo_fail_counter_ffffc21f) {
      immo_fail_counter_ffffc21f = 0;
      immo_tx_frame_valid_ffffc1d1 = 1;
    }
  }
  else {
    immo_main_state_ffffc21d = '\0';
    immo_lamp_drive(0);
    inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
    immo_tx_frame_valid_ffffc1d1 = 0;
  }
  DAT_ffffc229 = 0;
  immo_eeprom_write_dispatch();
  FUN_0003625e();
  FUN_00036700();
  FUN_0003665a();
  FUN_00036830();
  FUN_0003677a();
  FUN_000360c8();
  FUN_00036142();
  FUN_000361e4();
  return;
}


