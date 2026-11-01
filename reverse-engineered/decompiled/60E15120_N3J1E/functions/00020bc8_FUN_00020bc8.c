/* ROM address: 0x00020bc8; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021534 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00020bc8(void)

{
  if ((((DAT_ffffad50 < 1.2) || (0xb < DAT_ffffb270)) || (cranking_active_ffffaa62_ffffaa62 != '\0')) ||
     ((engine_running_ffffa428 != '\x01' || (DAT_ffffc5e6 != '\0')))) {
    DAT_ffffb284 = 0;
  }
  else {
    DAT_ffffb284 = 1;
  }
  return;
}


