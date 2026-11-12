/* ROM address: 0x00023558; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023dcc (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00023558(void)

{
  if (DAT_ffffccc9 == '\x01') {
    throttle_pedal_position_delta_ffffb414 = 0.0;
  }
  else {
    throttle_pedal_position_delta_ffffb414 = inferred_ram_b410_ffffb410_ffffb410 - DAT_ffffb428;
  }
  DAT_ffffb428 = inferred_ram_b410_ffffb410_ffffb410;
  return DAT_ffffccc9;
}


