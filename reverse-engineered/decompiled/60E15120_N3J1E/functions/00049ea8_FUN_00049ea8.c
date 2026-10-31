/* ROM address: 0x00049ea8; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00048e64 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00049ea8(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((((((DAT_ffffc96f == '\x01') || (cVar1 = '\x01', DAT_ffffc96d == '\x01')) ||
        (cVar1 = '\x01', DAT_ffffc6d5 == '\x01')) ||
       ((cVar1 = '\x01', DAT_ffffc6d7 == '\x01' || (cVar1 = '\x01', DAT_ffffc971 == '\x01')))) ||
      ((cVar1 = '\x01', DAT_ffffc912 == '\x01' ||
       ((cVar1 = '\x01', DAT_ffffc914 == '\x01' || (cVar1 = '\x01', DAT_ffffc91d == '\x01')))))) ||
     ((cVar1 = '\x01', DAT_ffffd26e == '\x01' || (cVar1 = DAT_ffffc590, DAT_ffffc590 == '\x01')))) {
    DAT_ffffcd5c = 1;
  }
  else {
    DAT_ffffcd5c = 0;
  }
  return cVar1;
}


