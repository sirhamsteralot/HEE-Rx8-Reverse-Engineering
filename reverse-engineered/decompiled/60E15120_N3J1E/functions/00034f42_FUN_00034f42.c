/* [ADDITIONAL SOURCE REVIEW]
 * immo_state2_challenge_verify [high]: Main state 2 handler; contains the with-RKE patch site 0x34f5c 'cmp/eq r2,r3' (c204 vs c200, pools 0x34fc4/0x34fc8). Match -> ImmoGoodStateSet 0x352c4, c224=0x7f, TX 0x81 (status OK); mismatch -> ImmoBadStateSet 0x35338, c224=0x81, TX 1, c22a=1. c21e==1 -> c20c=500, 0x34e68. Else c21e=5 with rpm>500 -> c228=1, c210/c216 countdowns; c216 timeout with battery>10V -> bad, c224=0x80. Dynamically verified both branches.
 * RAM 0xffffc22a immo_reject_event_flag (u8): set 1 on every bad-state path (0x34c5c/0x34d12/0x34f42), cleared by immo_set_authorized 0x352c4; emulator: 1 after wrong challenge, 0 after good one
 */
/* ROM address: 0x00034f42; body bytes: 230; decompiled */

undefined4 * immo_state2_challenge_verify(void)

{
  undefined4 *puVar1;
  
  if (immo_command_substate_ffffc21e == '\x02') {
    if (immo_challenge_received_ffffc204 == immo_seed_expected_ffffc200) {
      immo_set_authorized();
      immo_status_code_ffffc224 = 0x7f;
      puVar1 = (undefined4 *)immo_tx_frame_build(0x81);
      return puVar1;
    }
    immo_set_rejected();
    immo_status_code_ffffc224 = 0x81;
    puVar1 = (undefined4 *)immo_tx_frame_build(1);
    immo_reject_event_flag_ffffc22a = 1;
  }
  else {
    if (immo_command_substate_ffffc21e == '\x01') {
      immo_timer_a_ffffc20c = 500;
      puVar1 = (undefined4 *)immo_wait_for_key_step();
      return puVar1;
    }
    immo_command_substate_ffffc21e = '\x05';
    if (500.0 < engine_speed_rpm_ffffb548) {
      DAT_ffffc228 = '\x01';
    }
    if ((DAT_ffffc228 == '\x01') && (DAT_ffffc210 != 0)) {
      DAT_ffffc210 = DAT_ffffc210 + -1;
    }
    if (DAT_ffffc210 == 0) {
      immo_lamp_drive(0);
      inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
    }
    puVar1 = &DAT_000350e8;
    if (10.0 < inferred_battery_voltage_ffffb590) {
      if (DAT_ffffc216 != 0) {
        DAT_ffffc216 = DAT_ffffc216 + -1;
      }
      puVar1 = &DAT_000350e8;
      if (DAT_ffffc216 == 0) {
        immo_set_rejected();
        immo_status_code_ffffc224 = 0x80;
        puVar1 = (undefined4 *)immo_tx_frame_build(1);
        immo_reject_event_flag_ffffc22a = 1;
      }
    }
  }
  return puVar1;
}


