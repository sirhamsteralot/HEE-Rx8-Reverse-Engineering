/* ROM address: 0x0004a9c0; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004997c (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_fuelCutTimerAfterReset(void)

{
  if (((DAT_ffff9fa2 == '\0') && (DAT_ffffcdd1 == '\x01')) && (DAT_ffffd1c5 == '\0')) {
    if (0x167 < DAT_ffffcdc8) {
      DAT_ffffcdc6 = 1;
    }
    DAT_ffffcdc8 = rx8_add_u16_saturate((int)(short)DAT_ffffcdc8,0x1e);
  }
  else {
    DAT_ffffcdc6 = 0;
    DAT_ffffcdc8 = 0;
  }
  return;
}


