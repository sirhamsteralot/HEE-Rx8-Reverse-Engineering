/* ROM address: 0x00026760; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027084 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setAlternatorWarningLight(void)

{
  if ((((DAT_ffffb613 == '\0') || (DAT_ffffb5b0 == '\x01')) || (DAT_ffffb5b1 == '\x01')) ||
     ((DAT_ffffb5b2 == '\x01' || (DAT_ffffc5db == '\x01')))) {
    inferred_ram_b5b4_ffffb5b4_ffffb5b4 = 1;
  }
  else {
    inferred_ram_b5b4_ffffb5b4_ffffb5b4 = 0;
  }
  return;
}


