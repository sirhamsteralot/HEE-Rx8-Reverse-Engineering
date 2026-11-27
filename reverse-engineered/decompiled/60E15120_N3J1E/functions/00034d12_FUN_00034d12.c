/* [ADDITIONAL SOURCE REVIEW]
 * immo_state1_key_exchange [high]: Main state 1 handler. c21e==3: c274==1 -> c220=0xff, TX cmd 9, c21d=0; else compute expected words (0x35356), c220=1, TX cmd 9, c20e=500. c21e==4: c220 1..4 compares c1ec against c1f0/c1f4/c1f8/c1fc and advances; all 4 matched -> c20c=500, TX 0xc6, c21d=0. Else c21e=5, c20e timeout -> bad state. Dynamically verified: cmd 0xc9 then cmd 0x90 subs 1-4 with the computed words advance c220 1->4 and end with c21d=0, TX 0xc6.
 * RAM 0xffffc1f0 immo_expected_key_words (u32[4] c1f0-c1fc): c1f0 = c1dc|0x01000000 ... c1fc = c1e8|0x04000000
 * RAM 0xffffc220 immo_key_word_index (u8): emulator: 1->2->3->4 across cmd 0x90 subs
 */
/* ROM address: 0x00034d12; body bytes: 282; decompiled */

uint immo_state1_key_exchange(void)

{
  uint uVar1;
  
  uVar1 = (uint)immo_command_substate_ffffc21e;
  if (uVar1 == 3) {
    if (inferred_ram_c274_ffffc274_ffffc274 == '\x01') {
      immo_key_word_index_ffffc220 = 0xff;
      uVar1 = immo_tx_frame_build(9);
      immo_main_state_ffffc21d = 0;
    }
    else {
      immo_compute_expected_key_words();
      immo_key_word_index_ffffc220 = 1;
      uVar1 = immo_tx_frame_build(9);
      DAT_ffffc20e = 500;
    }
  }
  else if (uVar1 == 4) {
    uVar1 = (uint)immo_key_word_index_ffffc220;
    if (uVar1 == 1) {
      if (immo_received_key_word_ffffc1ec == immo_expected_key_words_ffffc1f0) {
        immo_key_word_index_ffffc220 = 2;
      }
      uVar1 = immo_tx_frame_build(9);
      return uVar1;
    }
    if (uVar1 == 2) {
      if (immo_received_key_word_ffffc1ec == DAT_ffffc1f4) {
        immo_key_word_index_ffffc220 = 3;
      }
      uVar1 = immo_tx_frame_build(9);
      return uVar1;
    }
    if (uVar1 == 3) {
      if (immo_received_key_word_ffffc1ec == DAT_ffffc1f8) {
        immo_key_word_index_ffffc220 = 4;
      }
      uVar1 = immo_tx_frame_build(9);
      return uVar1;
    }
    if (uVar1 == 4) {
      if (immo_received_key_word_ffffc1ec != DAT_ffffc1fc) {
        uVar1 = immo_tx_frame_build(9);
        return uVar1;
      }
      immo_timer_a_ffffc20c = 500;
      uVar1 = immo_tx_frame_build(0xc6);
      immo_main_state_ffffc21d = 0;
    }
  }
  else {
    immo_command_substate_ffffc21e = 5;
    if (DAT_ffffc20e != 0) {
      DAT_ffffc20e = DAT_ffffc20e + -1;
    }
    if (DAT_ffffc20e == 0) {
      immo_set_rejected();
      immo_status_code_ffffc224 = 0;
      uVar1 = immo_tx_frame_build(1);
      immo_reject_event_flag_ffffc22a = 1;
    }
  }
  return uVar1;
}


