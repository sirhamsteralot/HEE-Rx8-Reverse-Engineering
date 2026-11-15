/* [ADDITIONAL SOURCE REVIEW]
 * can_rx_main_key_gated [high]: Was ref_CANRX_Main: processes CAN IDs 0x212 (0x2b29c, pool 0xdc9c), 0x216 (0x28dc0, 0xdca0), 0x231 (AT only, 0x29074, 0xdca4), 0x430 (0x32d24, 0xdca8), 0x4B0 (0x2aff0, 0xdac), 0x4B1 (0x4bd48, 0xdb0), 0x4C0 (0x2b958, 0xdb4), 0x47 (0x3811c, 0xdb8) only while (0xffffaa68 == 1 && 0xffffb578 != 1 && 0xffffa410 == 0) (pools 0xdc5c=0xaa68, 0xdc5e=0xb578, 0xdc68=0xffffa410); always jsr 0x34ae2 (pool 0xdcbc). Key-off stops all non-diag CAN RX processing.
 */
/* ROM address: 0x0000dbf6; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000dbf6 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can_rx_main_key_gated(void)

{
  if (((engine_running_flag_ffffaa68 == '\x01') && (engine_stopped_latch_ffffb578 != '\x01')) && (can_setup_error_flag_ffffa410 == '\0')) {
    can212_rx_main();
    ref_CAN216RX_Main();
    if (automatic_transmission_ffffb534 == '\0') {
      ref_CAN231TX_Main();
    }
    ref_CAN430RX_Main();
    ref_CAN4B0RX_Main();
    ref_CAN4B1RX_Main();
    ref_CAN4C0RX_Main();
    ref_CAN47RX_Main();
  }
  FUN_00034ae2();
  return;
}


