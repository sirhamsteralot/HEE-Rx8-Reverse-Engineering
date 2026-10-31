/* ROM address: 0x0002f868; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fd20 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_getACSwitchStatus(void)

{
  DAT_ffffbdb8 = (DAT_ffff9ecd & 4) == 0;
  return DAT_ffffbdb8;
}


