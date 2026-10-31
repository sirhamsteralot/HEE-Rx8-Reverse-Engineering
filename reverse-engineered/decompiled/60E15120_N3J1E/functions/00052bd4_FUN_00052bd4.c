/* ROM address: 0x00052bd4; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050b56 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00052bd4(void)

{
  char cVar1;
  
  if (DAT_ffffcfc6 == '\x01') {
    DAT_ffffd12c = 0x3a03126f;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffd0f2;
    if (DAT_ffffd0f2 == '\x01') {
      DAT_ffffd12c = 0x3a83126f;
    }
  }
  return cVar1;
}


