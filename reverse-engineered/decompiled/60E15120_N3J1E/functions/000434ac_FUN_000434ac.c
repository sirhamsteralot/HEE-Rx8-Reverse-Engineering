/* ROM address: 0x000434ac; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042ce0 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000434ac(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffca44;
  if (DAT_ffffca44 == '\x01') {
    cVar1 = DAT_ffffca45;
    if (DAT_ffffca45 == '\x01') {
      DAT_ffffc9bc = 0x40000000;
    }
    else {
      DAT_ffffc9bc = 0;
    }
  }
  return cVar1;
}


