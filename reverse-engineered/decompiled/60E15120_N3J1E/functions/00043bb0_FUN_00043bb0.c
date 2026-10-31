/* ROM address: 0x00043bb0; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000433e4 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00043bb0(void)

{
  DAT_ffffcab8 = engine_speed_rpm_ffffb548 - DAT_ffffcb3c;
  DAT_ffffcabc = engine_load_ffffc0b4 - DAT_ffffcb40;
  DAT_ffffcb3c = engine_speed_rpm_ffffb548;
  DAT_ffffcb40 = engine_load_ffffc0b4;
  return;
}


