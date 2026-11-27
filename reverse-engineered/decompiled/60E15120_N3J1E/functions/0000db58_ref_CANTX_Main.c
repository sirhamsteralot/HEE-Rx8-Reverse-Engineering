/* [ADDITIONAL SOURCE REVIEW]
 * can_tx_main_key_gated [high]: Was ref_CANTX_Main: packs TX IDs 0x41/0x201/0x251/0x231/0x240/0x250/0x420/0x620/0x630/0x650 (pools 0xdc70-0xdc98) only while error poll 0xffffa40f < 100 (pool 0xdc64), latch 0xffffa40a == 0 (0xdc5a), setup error 0xffffa410 == 0 (0xdc68), comm error 0xffffa411 == 0 (0xdc6c), engine flag 0xffffaa68 == 1 (0xdc5c) && 0xffffb578 != 1 (0xdc5e); clears 0xffffc1d1 (pool 0xdc62).
 */
/* ROM address: 0x0000db58; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000db58 (158 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * can_tx_main_key_gated(void)

{
  undefined1 *puVar1;
  
  puVar1 = &can_error_poll_counter_ffffa40f;
  if ((((can_error_poll_counter_ffffa40f < 100) && (can_error_latch_ffffa40a == '\0')) && (can_setup_error_flag_ffffa410 == '\0')) &&
     (((puVar1 = &DAT_ffffa411, DAT_ffffa411 == '\0' &&
       (puVar1 = (undefined1 *)(uint)engine_running_flag_ffffaa68,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) &&
      (puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1), engine_stopped_latch_ffffb578 != '\x01')))) {
    immo_can_tx_pack();
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
  immo_tx_frame_valid_ffffc1d1 = 0;
  return puVar1;
}


