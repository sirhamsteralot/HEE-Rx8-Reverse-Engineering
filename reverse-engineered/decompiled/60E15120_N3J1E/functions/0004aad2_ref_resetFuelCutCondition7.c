/* ROM address: 0x0004aad2; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049a8e (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_resetFuelCutCondition7(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\0') {
    cVar1 = DAT_ffff9fa2;
    if (DAT_ffff9fa2 == '\x02') {
      cVar1 = '\0';
      DAT_ffffcdbe = 1;
    }
  }
  else {
    cVar1 = '\0';
    DAT_ffffcdbe = 0;
  }
  return cVar1;
}


