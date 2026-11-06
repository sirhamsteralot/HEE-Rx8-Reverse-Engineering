/* [ADDITIONAL SOURCE REVIEW]
 * uds_rx_channel_set_service [medium]: DAT_ffffddf3[ch*2]=service, state=4, calls 0x67d8c timer
 */
/* ROM address: 0x00068b10; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067400 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_uds_rx_channel_set_service(byte param_1,undefined1 param_2)

{
  (&DAT_ffffddf3)[(uint)param_1 * 2] = param_2;
  (&DAT_ffffddf4)[(uint)param_1 * 2] = 4;
  FUN_00067d8c();
  return;
}


