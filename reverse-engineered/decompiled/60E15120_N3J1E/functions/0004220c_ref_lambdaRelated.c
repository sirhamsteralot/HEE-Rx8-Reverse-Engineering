/* ROM address: 0x0004220c; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00041a40 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_lambdaRelated(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  
  puVar1 = (undefined1 *)(uint)engine_stopped_latch_ffffa41c;
  if (((puVar1 == (undefined1 *)0x1) || (closed_loop_active_ffffae1f == '\0')) ||
     (puVar1 = &DAT_ffffaa81, DAT_ffffaa81 == '\0')) {
    DAT_ffffc93c = 1.0;
    DAT_ffffc928 = 1.0;
  }
  else {
    DAT_ffffc93c = ((diag_afr_word_a_ffffaa6c + DAT_ffffadec) - lambda_target_ffffadfc) + DAT_ffffb0d0;
    DAT_ffffc928 = rx8_first_order_filter(DAT_ffffc93c,DAT_ffffc928,0.03,1e-05);
    puVar1 = extraout_r0;
  }
  return puVar1;
}


