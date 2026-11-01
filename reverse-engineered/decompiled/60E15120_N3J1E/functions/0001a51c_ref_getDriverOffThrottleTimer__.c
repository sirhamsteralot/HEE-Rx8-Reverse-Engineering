/* ROM address: 0x0001a51c; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001afcc (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getDriverOffThrottleTimer__(void)

{
  if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.5) {
    if (inferred_ram_a9bc_ffffa9bc_ffffa9bc < 2.0) {
      DAT_ffffaa64 = '\0';
    }
  }
  else {
    DAT_ffffaa64 = '\x01';
  }
  if (DAT_ffffaa64 == '\0') {
    DAT_ffffaa60 = rx8_add_u16_saturate((int)DAT_ffffaa60,1);
  }
  else {
    DAT_ffffaa60 = 0;
  }
  return;
}


