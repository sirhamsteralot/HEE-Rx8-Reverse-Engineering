/* ROM address: 0x0002c5e4; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002cd9c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0002c5e4(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = automatic_transmission_ffffb534;
  if ((automatic_transmission_ffffb534 == '\x01') && (cVar1 = DAT_ffffb53a, DAT_ffffb53a != '\x01')) {
    cVar2 = '\x0f';
  }
  else {
    cVar2 = '\0';
  }
  DAT_ffffbc5d = cVar2 * '\x10' + '\x0f';
  return cVar1;
}


