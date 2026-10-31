/* ROM address: 0x0002d520; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002dbc4 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_getCruiseControlAllowedBool__(void)

{
  char cVar1;
  
  if ((((DAT_ffffbce8 == '\x01') || (DAT_ffffbce9 == '\x01')) || (DAT_ffffbcea == '\x01')) ||
     (DAT_ffffbcfe == '\x01')) {
    DAT_ffffbcec = 0;
    cVar1 = '\0';
  }
  else if (27.0 < DAT_ffffbfa0) {
    DAT_ffffbcec = 1;
    cVar1 = DAT_ffffbcfe;
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}


