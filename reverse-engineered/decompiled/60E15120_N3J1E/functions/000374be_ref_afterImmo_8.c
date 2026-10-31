/* ROM address: 0x000374be; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037bde (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_afterImmo_8(void)

{
  char cVar1;
  
  if ((((DAT_ffffc25b == '\x01') && (DAT_ffffc25c == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\n';
    FUN_00035a8c(10);
    DAT_ffffc25c = '\x01';
    DAT_ffffc25b = '\0';
  }
  cVar1 = DAT_ffffc25c;
  if (DAT_ffffc25c == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc25c = '\0';
      DAT_ffffc25d = 1;
    }
  }
  return cVar1;
}


