/* [ADDITIONAL SOURCE REVIEW]
 * uds_rx_channel_set_service [high]: DAT_ffffddf3[ch*2]=service, state=4, calls 0x67d8c timer | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00068b10; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067400 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_rx_channel_set_service(byte param_1,undefined1 param_2)

{
  (&DAT_ffffddf3)[(uint)param_1 * 2] = param_2;
  (&DAT_ffffddf4)[(uint)param_1 * 2] = 4;
  FUN_00067d8c();
  return;
}


