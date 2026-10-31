/* ROM address: 0x0003354e; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033876 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003354e(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffb53c;
  if (DAT_ffffb534 == '\0') {
    if (DAT_ffffb53c == '\0') {
      DAT_ffffc048 = 0.0;
    }
    else if (DAT_ffffc05b == '\0') {
      DAT_ffffc048 = 0.04;
    }
    else {
      DAT_ffffc048 = rx8_max_float(DAT_ffffc048 - 0.0008,0.0);
    }
    DAT_ffffc05b = cVar1;
  }
  else {
    DAT_ffffc048 = 0.0;
  }
  return;
}


