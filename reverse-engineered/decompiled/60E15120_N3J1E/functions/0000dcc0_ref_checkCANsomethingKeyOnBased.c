/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa409 can_error_recovery_active (uint8): Set to 1 in the bus-off/error branch of 0xdcc0 (mov.b r11,@r3 at 0xdd78, pool 0xddc4 = 0xa409).
 * RAM 0xffffa40a can_error_latch (uint8): Set when error-poll counter 0xffffa40f exceeds 100 (mov #0x64 at 0xdd16, cmp/gt; pool 0xddc2 = 0xa40a) and the latch was 0; cleared after the 0xdade full reset.
 * RAM 0xffffa40c can_error_retry_counter (uint16): Incremented via rx8_add_u16_saturate 0x2460 (pool 0xddd8) each error poll; ref_canSetup re-run only while 0 (tst at 0xdd7c); full reset 0xdade at >= 1000 (pool 0xddc6 = 0x3e8). Cell at pool 0xddd0.
 * RAM 0xffffa40f can_error_poll_counter (uint8): Saturating counter (cap 0xff, pool 0xddc0) incremented while engine running (0xffffaa68==1) and ref_getHCANSomething 0x9b08 (GSR bit1 error warning) is set on either channel; cleared otherwise.
 */
/* ROM address: 0x0000dcc0; body bytes: 252; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000dcc0 (252 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_checkCANsomethingKeyOnBased(void)

{
  char cVar2;
  uint uVar1;
  
  if (((DAT_ffffaa68 == 1) && (DAT_ffffb578 != '\x01')) &&
     ((cVar2 = ref_getHCANSomething(0), cVar2 == '\x01' ||
      (cVar2 = ref_getHCANSomething(1), cVar2 == '\x01')))) {
    if (can_error_poll_counter_ffffa40f != 0xff) {
      can_error_poll_counter_ffffa40f = can_error_poll_counter_ffffa40f + 1;
    }
  }
  else {
    can_error_poll_counter_ffffa40f = 0;
  }
  if ((100 < can_error_poll_counter_ffffa40f) && (ref_CANSetupSomethingDifferentBasedOnBit(), can_error_latch_ffffa40a == 0)) {
    can_error_latch_ffffa40a = 1;
  }
  uVar1 = (uint)DAT_ffffaa68;
  if ((uVar1 == 1) && (uVar1 = 1, DAT_ffffb578 != '\x01')) {
    cVar2 = hcan_bus_off_flag(0);
    if ((cVar2 == '\x01') ||
       ((cVar2 = hcan_bus_off_flag(1), cVar2 == '\x01' || (uVar1 = (uint)can_error_latch_ffffa40a, uVar1 == 1)))) {
      can_error_latch_ffffa40a = 1;
      can_error_recovery_active_ffffa409 = 1;
      if (can_error_retry_counter_ffffa40c == 0) {
        ref_CANSetupSomethingDifferentBasedOnBit();
        ref_canSetup();
      }
      ref_CANSetupSomethingDifferentBasedOnBit();
      uVar1 = rx8_add_u16_saturate((int)(short)can_error_retry_counter_ffffa40c,1);
      can_error_retry_counter_ffffa40c = (ushort)uVar1;
    }
    else {
      can_error_retry_counter_ffffa40c = 0;
    }
    if (999 < can_error_retry_counter_ffffa40c) {
      uVar1 = can_error_full_reset();
      can_error_latch_ffffa40a = 0;
      can_error_retry_counter_ffffa40c = 0;
    }
  }
  return uVar1;
}


