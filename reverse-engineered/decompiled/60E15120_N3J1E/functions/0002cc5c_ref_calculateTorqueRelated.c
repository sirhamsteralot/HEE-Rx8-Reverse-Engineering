/* ROM address: 0x0002cc5c; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d300 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateTorqueRelated(void)

{
  DAT_ffffbc9c = DAT_ffffbc98 -
                 (DAT_ffffbc94 - leading_ignition_timing_ffffa630) * (DAT_ffffbc94 - leading_ignition_timing_ffffa630) * DAT_ffffbc90;
  return;
}


