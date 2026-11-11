/* ROM address: 0x0000db58; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000db58 (158 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_CANTX_Main(void)

{
  undefined1 *puVar1;
  
  puVar1 = &can_error_poll_counter_ffffa40f;
  if ((((can_error_poll_counter_ffffa40f < 100) && (can_error_latch_ffffa40a == '\0')) && (can_setup_error_flag_ffffa410 == '\0')) &&
     (((puVar1 = &DAT_ffffa411, DAT_ffffa411 == '\0' &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffaa68,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) &&
      (puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1), DAT_ffffb578 != '\x01')))) {
    ref_can41TXPack();
    ref_can201TX_getAndPack();
    FUN_0002941a();
    ref_can251TX_getAndPack();
    if (automatic_transmission_ffffb534 == '\x01') {
      ref_can231TX_getAndPack();
    }
    ref_can240TX_getAndPack();
    ref_can250TX_getAndPack();
    ref_can420TX_getAndPack();
    ref_can620TX_getAndPack();
    ref_can630TX_getAndPack();
    puVar1 = (undefined1 *)ref_can650TX_getAndPack();
  }
  DAT_ffffc1d1 = 0;
  return puVar1;
}


