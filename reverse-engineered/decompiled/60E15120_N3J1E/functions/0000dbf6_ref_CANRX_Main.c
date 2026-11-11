/* ROM address: 0x0000dbf6; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000dbf6 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_CANRX_Main(void)

{
  if (((DAT_ffffaa68 == '\x01') && (DAT_ffffb578 != '\x01')) && (can_setup_error_flag_ffffa410 == '\0')) {
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


