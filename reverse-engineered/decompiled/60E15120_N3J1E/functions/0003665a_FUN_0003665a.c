/* ROM address: 0x0003665a; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036d7a (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003665a(void)

{
  char cVar1;
  
  if ((((DAT_ffffc23e == '\x01') && (DAT_ffffc23f == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\t';
    candidate_e2ram_param_write_dispatch(9);
    DAT_ffffc23f = '\x01';
    DAT_ffffc23e = '\0';
  }
  cVar1 = DAT_ffffc23f;
  if (DAT_ffffc23f == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc23f = '\0';
    }
  }
  return cVar1;
}


