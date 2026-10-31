/* ROM address: 0x0001bcae; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001c75e (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001bcae(void)

{
  if (DAT_ffffad62 == '\x01') {
    DAT_ffffad64 = DAT_ffffadca < 4;
    DAT_ffffadca = rx8_add_u16_saturate((int)(short)DAT_ffffadca,1);
  }
  else {
    DAT_ffffadca = 0;
    DAT_ffffad64 = 0;
  }
  return;
}


