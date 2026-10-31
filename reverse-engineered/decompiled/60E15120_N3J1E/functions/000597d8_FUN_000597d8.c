/* ROM address: 0x000597d8; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00057f90 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000597d8(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (((DAT_ffffd261 == '\x01') || (cVar1 = '\x01', DAT_ffffd266 == '\x01')) ||
     (cVar1 = DAT_ffffd26f, DAT_ffffd26f == '\x01')) {
    DAT_ffffd25d = 1;
  }
  else {
    DAT_ffffd25d = 0;
  }
  return cVar1;
}


