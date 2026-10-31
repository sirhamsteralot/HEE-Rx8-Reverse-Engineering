/* ROM address: 0x0004a184; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049140 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004a184(void)

{
  char cVar1;
  
  if ((DAT_ffffc932 == '\x01') || (DAT_ffffcd83 == '\x01')) {
    cVar1 = '\x01';
    DAT_ffffcd74 = 1;
  }
  else {
    cVar1 = DAT_ffffcd84;
    if (DAT_ffffcd84 == '\x01') {
      cVar1 = '\0';
    }
    DAT_ffffcd74 = 0;
  }
  return cVar1;
}


