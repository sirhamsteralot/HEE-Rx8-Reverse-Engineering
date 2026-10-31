/* ROM address: 0x000436a6; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042eda (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000436a6(void)

{
  bool bVar1;
  char cVar2;
  
  cVar2 = DAT_ffffca4e;
  if ((DAT_ffffb534 == '\x01') && (DAT_ffffb53a == '\0')) {
    DAT_ffffca4e = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffca4e = 0;
    bVar1 = false;
  }
  if ((cVar2 != '\x01') || (bVar1)) {
    if (DAT_ffffca40 != '\0') {
      DAT_ffffca40 = DAT_ffffca40 + -1;
    }
  }
  else {
    cVar2 = '^';
    DAT_ffffca40 = '^';
  }
  return cVar2;
}


