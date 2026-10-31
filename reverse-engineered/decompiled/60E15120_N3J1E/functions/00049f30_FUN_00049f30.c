/* ROM address: 0x00049f30; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00048eec (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00049f30(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((((DAT_ffffcd15 == '\x01') || (cVar1 = '\x01', DAT_ffffc6b9 == '\x01')) ||
      (cVar1 = '\x01', DAT_ffffc6bb == '\x01')) ||
     (((cVar1 = '\x01', DAT_ffffc995 == '\x01' || (cVar1 = '\x01', DAT_ffffc997 == '\x01')) ||
      (cVar1 = DAT_ffffc6bd, DAT_ffffc6bd == '\x01')))) {
    DAT_ffffcd5d = 1;
  }
  else {
    DAT_ffffcd5d = 0;
  }
  return cVar1;
}


