/* ROM address: 0x0001a564; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b014 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDriverOffThrottleInstatanious(void)

{
  if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.5) {
    if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.0) {
      DAT_ffffaa65 = '\0';
    }
  }
  else {
    DAT_ffffaa65 = '\x01';
  }
  if (DAT_ffffaa65 == '\0') {
    if (DAT_ffffaa60 < 0x13) {
      DAT_ffffaa63 = 1;
      cranking_active_ffffaa62_ffffaa62 = 0;
    }
    else {
      DAT_ffffaa63 = 1;
      cranking_active_ffffaa62_ffffaa62 = 1;
    }
  }
  else {
    DAT_ffffaa63 = 0;
    cranking_active_ffffaa62_ffffaa62 = 0;
  }
  return;
}


