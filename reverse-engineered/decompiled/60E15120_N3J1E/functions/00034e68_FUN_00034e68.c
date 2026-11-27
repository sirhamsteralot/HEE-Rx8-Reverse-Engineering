/* [ADDITIONAL SOURCE REVIEW]
 * immo_wait_for_key_step [high]: c21e==1 dispatch on c221: 1 -> bad state (c224=0, TX 1, c22a=1); 3 -> c21d=0; 2 (seed request) -> key-count check (c282: 0 or >2 -> lamp off, c1d0=0; else c282-=1, c22f=1, lamp on, c1d0=1, c228=0), c216=0x2ee, immo_compute_seed 0x353ce, TX cmd 7 with raw seed c208, c21d=2. Dynamically verified.
 */
/* ROM address: 0x00034e68; body bytes: 178; decompiled */

uint immo_wait_for_key_step(void)

{
  uint uVar1;
  
  uVar1 = (uint)immo_command_substate_ffffc21e;
  if (uVar1 == 1) {
    uVar1 = (uint)immo_request_subtype_ffffc221;
    if (uVar1 == 1) {
      immo_set_rejected();
      immo_status_code_ffffc224 = 0;
      uVar1 = immo_tx_frame_build(1);
      immo_reject_event_flag_ffffc22a = 1;
    }
    else if (uVar1 == 3) {
      immo_main_state_ffffc21d = 0;
    }
    else if (uVar1 == 2) {
      if ((immo_registered_key_count_ffffc282 == 0) || (2 < immo_registered_key_count_ffffc282)) {
        immo_lamp_drive(0);
        inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
      }
      else {
        immo_registered_key_count_ffffc282 = immo_registered_key_count_ffffc282 - 1;
        DAT_ffffc22f = 1;
        immo_lamp_drive(1);
        inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 1;
        DAT_ffffc228 = 0;
      }
      DAT_ffffc216 = 0x2ee;
      immo_compute_seed();
      uVar1 = immo_tx_frame_build(7);
      immo_main_state_ffffc21d = 2;
    }
  }
  else {
    if (uVar1 == 3) {
      uVar1 = immo_state1_key_exchange();
      return uVar1;
    }
    immo_command_substate_ffffc21e = 5;
  }
  return uVar1;
}


