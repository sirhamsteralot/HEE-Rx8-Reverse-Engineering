/* ROM address: 0x00036700; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036e20 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00036700(void)

{
  char cVar1;
  
  if ((((DAT_ffffc240 == '\x01') && (DAT_ffffc241 == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\b';
    candidate_e2ram_param_write_dispatch(8);
    DAT_ffffc241 = '\x01';
    DAT_ffffc240 = '\0';
  }
  cVar1 = DAT_ffffc241;
  if (DAT_ffffc241 == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc241 = '\0';
    }
  }
  return cVar1;
}


