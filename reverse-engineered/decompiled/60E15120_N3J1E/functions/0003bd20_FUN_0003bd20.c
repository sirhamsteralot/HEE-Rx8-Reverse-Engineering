/* ROM address: 0x0003bd20; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003c154 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003bd20(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5b7 = 0;
    DAT_ffffc5b8 = '\0';
    cVar1 = '\x01';
  }
  else {
    if (DAT_ffffc5a5 == '\0') {
      DAT_ffffc5b8 = '\x01';
    }
    cVar1 = DAT_ffffc5b8;
    if (DAT_ffffc5b8 == '\x01') {
      DAT_ffffc5b7 = 0;
    }
    else if (DAT_ffffc5a4 == '\0') {
      DAT_ffffc5b7 = 1;
    }
  }
  return cVar1;
}


