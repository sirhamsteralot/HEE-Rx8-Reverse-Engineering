/* [ADDITIONAL SOURCE REVIEW]
 * immo_state3_authorized [high]: Main state 3 handler. c21e==0 -> c274=1, c22b=1, c1d3|=0x40, c255=1, c226=1 (authorized latch); c21e==1 -> c214=500, c224=0x7f, TX 0x81; else timeouts. Engine-off detection: rpm<=0 edge -> c222=1, c212=15000; c212 expiry -> TX 0xc8 (200), c21d=5, c21c=1, c212=500.
 * RAM 0xffffc212 immo_timer_engine_off (u16): 15000 after authorization, 500 in ready-engine-off state
 * RAM 0xffffc21c immo_ready_engine_off_pending (u8): set with TX 0xc8 when c212 expires in state 3
 * RAM 0xffffc226 immo_authorized_latch_flag (u8): set when state 3 sees c21e==0
 */
/* ROM address: 0x00035062; body bytes: 256; decompiled */

uint immo_state3_authorized(void)

{
  bool bVar1;
  uint uVar2;
  
  if (engine_speed_rpm_ffffb548 <= 500.0) {
    if ((engine_speed_rpm_ffffb548 <= 0.0) && (bVar1 = DAT_ffffc222 == 0, DAT_ffffc222 = 1, bVar1)) {
      immo_timer_engine_off_ffffc212 = 15000;
    }
  }
  else {
    DAT_ffffc222 = 0;
  }
  if (immo_command_substate_ffffc21e == '\0') {
    if (DAT_ffffc248 == '\0') {
      inferred_ram_c274_ffffc274_ffffc274 = 1;
      DAT_ffffc22b = 1;
      inferred_ram_c1d3_ffffc1d3_ffffc1d3 = inferred_ram_c1d3_ffffc1d3_ffffc1d3 | 0x40;
      DAT_ffffc255 = 1;
    }
    immo_authorized_latch_flag_ffffc226 = 1;
  }
  else if (immo_command_substate_ffffc21e == '\x01') {
    DAT_ffffc214 = 500;
    immo_status_code_ffffc224 = 0x7f;
    immo_tx_frame_build(0x81);
  }
  else {
    immo_command_substate_ffffc21e = '\x05';
    if (10.0 < inferred_battery_voltage_ffffb590) {
      if (DAT_ffffc214 != 0) {
        DAT_ffffc214 = DAT_ffffc214 + -1;
      }
      if (DAT_ffffc214 == 0) {
        immo_authorized_latch_flag_ffffc226 = 1;
      }
    }
  }
  uVar2 = (uint)DAT_ffffc222;
  if (uVar2 == 1) {
    if (immo_timer_engine_off_ffffc212 != 0) {
      immo_timer_engine_off_ffffc212 = immo_timer_engine_off_ffffc212 + -1;
    }
    uVar2 = (uint)DAT_ffffc222;
    if ((uVar2 == 1) && (immo_timer_engine_off_ffffc212 == 0)) {
      uVar2 = immo_tx_frame_build(200);
      immo_main_state_ffffc21d = 5;
      immo_ready_engine_off_pending_ffffc21c = 1;
      immo_timer_engine_off_ffffc212 = 500;
    }
  }
  return uVar2;
}


