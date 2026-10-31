/* ROM address: 0x0004ab68; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049b24 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004ab68(void)

{
  if ((DAT_ffffcdc2 == 500) || (DAT_ffffd1c5 == '\x01')) {
    DAT_ffffcdc2 = 0;
  }
  else {
    DAT_ffffcdc2 = rx8_add_u16_saturate((int)DAT_ffffcdc2,1);
  }
  return;
}


