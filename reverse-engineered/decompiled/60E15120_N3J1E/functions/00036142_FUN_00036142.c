/* ROM address: 0x00036142; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036862 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00036142(void)

{
  char cVar1;
  
  if ((((DAT_ffffc22b == '\x01') && (DAT_ffffc22c == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x01';
    FUN_00035a8c(1);
    DAT_ffffc22c = '\x01';
    DAT_ffffc22b = '\0';
  }
  cVar1 = DAT_ffffc22c;
  if (DAT_ffffc22c == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc22c = '\0';
    }
  }
  return cVar1;
}


