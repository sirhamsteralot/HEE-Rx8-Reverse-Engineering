/* ROM address: 0x00049836; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004873a (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00049836(void)

{
  if (DAT_ffffcd20 == '\0') {
    DAT_ffffcd32 = 0;
  }
  else if (DAT_ffffae20 == '\x01') {
    DAT_ffffcd32 = rx8_add_u16_saturate((int)DAT_ffffcd32,1);
  }
  else if (DAT_ffffad20 < 0.5) {
    DAT_ffffcd32 = 0;
  }
  return;
}


