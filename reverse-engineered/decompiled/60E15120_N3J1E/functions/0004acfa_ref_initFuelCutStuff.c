/* ROM address: 0x0004acfa; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049cb6 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_initFuelCutStuff(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcdbc = 0;
    cVar1 = '\x01';
  }
  else {
    cVar1 = '\x01';
    if ((DAT_ffffcdc0 == '\x01') || (cVar1 = DAT_ffffcdc1, DAT_ffffcdc1 == '\x01')) {
      DAT_ffffcdbc = 1;
    }
    else {
      DAT_ffffcdbc = 0;
    }
  }
  return cVar1;
}


