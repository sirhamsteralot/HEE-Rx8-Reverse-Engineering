/* ROM address: 0x00018e84; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019a80 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00018e84(void)

{
  if (DAT_ffffc5e6 == '\0') {
    inferred_coolant_temperature_ffffa990 = DAT_ffffa988;
    DAT_ffffa994 = DAT_ffffa988;
  }
  else {
    inferred_coolant_temperature_ffffa990 = 0x42a00000;
    DAT_ffffa994 = 0x41f00000;
  }
  inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa990;
  return;
}


