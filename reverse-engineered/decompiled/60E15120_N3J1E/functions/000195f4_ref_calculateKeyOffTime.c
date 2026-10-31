/* ROM address: 0x000195f4; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001a310 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateKeyOffTime(void)

{
  if (DAT_ffffaa68 == '\0') {
    DAT_ffffa9e2 = rx8_add_u16_saturate((int)DAT_ffffa9e2,1);
  }
  else {
    DAT_ffffa9e2 = 0;
  }
  return;
}


