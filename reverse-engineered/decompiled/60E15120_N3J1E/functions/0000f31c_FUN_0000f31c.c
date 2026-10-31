/* ROM address: 0x0000f31c; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f320 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0000f31c(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffa4b2;
  if (DAT_ffffa4b2 == '\x01') {
    if (DAT_ffffa4b0 != '\0') {
      DAT_ffffa4b0 = DAT_ffffa4b0 + -1;
    }
  }
  else {
    DAT_ffffa4b2 = '\x01';
  }
  return cVar1;
}


