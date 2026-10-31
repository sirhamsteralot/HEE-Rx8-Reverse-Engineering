/* ROM address: 0x0004aa60; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049a1c (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004aa60(void)

{
  if (((DAT_ffff9fa2 == '\0') && (DAT_ffffcdd1 == '\x01')) && (DAT_ffffd1c5 == '\0')) {
    if (0x2cf < DAT_ffffcdca) {
      DAT_ffffcdc7 = 1;
    }
    DAT_ffffcdca = rx8_add_u16_saturate((int)(short)DAT_ffffcdca,0x1e);
  }
  else {
    DAT_ffffcdc7 = 0;
    DAT_ffffcdca = 0;
  }
  return;
}


