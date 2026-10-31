/* ROM address: 0x000361e4; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036904 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000361e4(void)

{
  char cVar1;
  
  if ((((DAT_ffffc22f == '\x01') && (DAT_ffffc230 == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\r';
    FUN_00035a8c(0xd);
    DAT_ffffc230 = '\x01';
    DAT_ffffc22f = '\0';
  }
  cVar1 = DAT_ffffc230;
  if (DAT_ffffc230 == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc230 = '\0';
    }
  }
  return cVar1;
}


