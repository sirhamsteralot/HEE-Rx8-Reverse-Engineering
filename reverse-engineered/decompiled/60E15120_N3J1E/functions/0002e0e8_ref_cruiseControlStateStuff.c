/* ROM address: 0x0002e0e8; body bytes: 118; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002e66c (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_cruiseControlStateStuff(void)

{
  char cVar1;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if (engine_running_flag_ffffaa68 == '\x01') {
    if (DAT_ffffbd53 == '\0') {
      DAT_ffffbd4e = 0;
    }
    else if (DAT_ffffbd4e != 0) {
      DAT_ffffbd4e = DAT_ffffbd4e + -1;
    }
  }
  else {
    DAT_ffffbd4e = 0;
  }
  if ((cVar1 == '\x01') || (DAT_ffffbd4e != 0)) {
    cVar1 = '\x01';
    DAT_ffffbd4c = 1;
  }
  else if (cVar1 == '\0') {
    DAT_ffffbd4c = 0;
  }
  DAT_ffffbd53 = engine_running_flag_ffffaa68;
  return cVar1;
}


