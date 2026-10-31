/* ROM address: 0x000481d2; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004725e (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000481d2(void)

{
  if (DAT_ffffcc92 == '\0') {
    DAT_ffffcca2 = 0;
    DAT_ffffcca3 = 0;
  }
  else if (DAT_ffffcc92 == '\x01') {
    DAT_ffffcca2 = 0;
    DAT_ffffcca3 = 1;
  }
  else {
    DAT_ffffcca2 = 1;
    DAT_ffffcca3 = 0;
  }
  return;
}


