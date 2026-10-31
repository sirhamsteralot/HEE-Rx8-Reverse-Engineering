/* ROM address: 0x0004e8c6; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004c382 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004e8c6(void)

{
  char cVar1;
  
  if (DAT_ffffcfc9 == '\0') {
    cVar1 = '\0';
  }
  else {
    cVar1 = ref_getKnownBooleanValue__();
    if ((cVar1 == '\0') || (((int)DAT_ffffce20 & 0x80U) != 0)) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = '\x02';
    }
  }
  if (cVar1 == '\0') {
    DAT_ffffcfb5 = -0x80;
  }
  else if (cVar1 == '\x01') {
    DAT_ffffcfb5 = '@';
  }
  else {
    DAT_ffffcfb5 = cVar1;
    if (cVar1 == '\x02') {
      DAT_ffffcfb5 = ' ';
    }
  }
  return cVar1;
}


