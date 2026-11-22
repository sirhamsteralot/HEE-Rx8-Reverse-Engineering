/* [ADDITIONAL SOURCE REVIEW]
 * immobilizer_main_state_dispatch [high]: Called from can_rx_main_key_gated 0xdbf6 (callgraph). Body (298 B) verified in disassembly: gates on engine_running_flag 0xffffaa68==1 && engine_stopped_latch 0xffffb578!=1 (else clears c21d/c1d0/c1d1, lamp off); calls 0x35ea0 then 0x355f0 (the bsr at 0x34b10 is the immo-disable patch site); dispatches on main state DAT_ffffc21d: 0->0x34c5c, 1->0x34d12, 2->0x34f42, 3->0x35062, 4->0x351ae, 5->0x35258, else reset to 0; fail counter c21f increments when c21e in {5,6} && c226==0 && c229==0, 3 strikes set c1d1=1; tail calls afterImmoMain 0x36908 and 7 EEPROM-write sequencer steps.
 * RAM 0xffffc21d immo_main_state (u8): 0x34b14 reads it; handlers 0x34c5c/0x34d12/0x34f42/0x35062/0x351ae/0x35258 via bsr at 0x34b40/0x34b98/0x34ba0/0x34ba8/0x34bb0/0x34bb8
 * RAM 0xffffc21f immo_fail_counter (u8): counts consecutive c21e in {5,6} cycles with c226==0 && c229==0
 */
/* ROM address: 0x00034ae2; body bytes: 298; decompiled */

void FUN_00034ae2(void)

{
  if ((engine_running_flag_ffffaa68 == '\x01') && (engine_stopped_latch_ffffb578 != '\x01')) {
    ref_ImmoUpdateRelated();
    FUN_000355f0();
    if (DAT_ffffc21d == '\0') {
      FUN_00034c5c();
    }
    else if (DAT_ffffc21d == '\x01') {
      FUN_00034d12();
    }
    else if (DAT_ffffc21d == '\x02') {
      FUN_00034f42();
    }
    else if (DAT_ffffc21d == '\x03') {
      FUN_00035062();
    }
    else if (DAT_ffffc21d == '\x04') {
      FUN_000351ae();
    }
    else if (DAT_ffffc21d == '\x05') {
      ref_ImmoStateReadyToDriveEngineOff();
    }
    else {
      DAT_ffffc21d = '\0';
    }
    if ((((DAT_ffffc21e == '\x05') || (DAT_ffffc21e == '\x06')) && (DAT_ffffc226 == '\0')) &&
       (DAT_ffffc229 == '\0')) {
      DAT_ffffc21f = rx8_add_u8_saturate((int)(char)DAT_ffffc21f,1);
    }
    else {
      DAT_ffffc21f = 0;
    }
    if (2 < DAT_ffffc21f) {
      DAT_ffffc21f = 0;
      DAT_ffffc1d1 = 1;
    }
  }
  else {
    DAT_ffffc21d = '\0';
    ref_setImmoLight__(0);
    inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
    DAT_ffffc1d1 = 0;
  }
  DAT_ffffc229 = 0;
  ref_afterImmoMain();
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


