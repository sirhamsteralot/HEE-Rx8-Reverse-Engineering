/* ROM address: 0x00036830; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036f50 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_00036830(void)

{
  char cVar1;
  
  if ((((DAT_ffffc244 == '\x01') && (DAT_ffffc245 == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x0f';
    candidate_e2ram_param_write_dispatch(0xf);
    DAT_ffffc245 = '\x01';
    DAT_ffffc244 = '\0';
  }
  cVar1 = DAT_ffffc245;
  if (DAT_ffffc245 == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc245 = '\0';
    }
  }
  return cVar1;
}


