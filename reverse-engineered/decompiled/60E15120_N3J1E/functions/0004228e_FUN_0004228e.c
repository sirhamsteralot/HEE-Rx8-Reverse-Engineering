/* ROM address: 0x0004228e; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00041ac2 (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004228e(void)

{
  char cVar1;
  
  if ((DAT_ffffc92f == '\x01') || (DAT_ffffc94f == '\x01')) {
    DAT_ffffc932 = 1;
  }
  else {
    DAT_ffffc932 = 0;
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc933 = 0;
    DAT_ffffc931 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((DAT_ffffc930 == '\x01') || (DAT_ffffc92d == '\x01')) {
      DAT_ffffc933 = 1;
      DAT_ffffc931 = 0;
    }
    cVar1 = DAT_ffffc92e;
    if ((DAT_ffffc92e == '\x01') && (cVar1 = DAT_ffffc92c, DAT_ffffc92c == '\x01')) {
      DAT_ffffc931 = 1;
      DAT_ffffc933 = 0;
    }
  }
  return cVar1;
}


