/* ROM address: 0x0004c728; body bytes: 56; decompiled */

void FUN_0004c728(void)

{
  DAT_ffffcec0 = 0;
  DAT_ffffcec1 = 0;
  DAT_ffffcec2 = diag_encode_leading_timing();
  DAT_ffffcec3 = diag_encode_iat();
  DAT_ffffcec4 = diag_encode_maf();
  DAT_ffffcec6 = diag_encode_throttle_pct();
  DAT_ffffcec7 = diag_read_secondary_air_status();
  return;
}


