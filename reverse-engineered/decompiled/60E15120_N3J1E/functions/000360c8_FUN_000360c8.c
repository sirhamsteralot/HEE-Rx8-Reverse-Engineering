/* ROM address: 0x000360c8; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000367e8 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000360c8(void)

{
  char cVar1;
  
  if ((((DAT_ffffc22d == '\x01') && (DAT_ffffc22e == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x02';
    FUN_00035a8c(2);
    DAT_ffffc22e = '\x01';
    DAT_ffffc22d = '\0';
  }
  cVar1 = DAT_ffffc22e;
  if (DAT_ffffc22e == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc22e = '\0';
    }
  }
  return cVar1;
}


