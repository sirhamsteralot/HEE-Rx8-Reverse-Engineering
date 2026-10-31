/* ROM address: 0x00037134; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037854 (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_afterImmo_5(void)

{
  char cVar1;
  
  if ((((DAT_ffffc255 == '\x01') && (DAT_ffffc256 == '\0')) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x06';
    FUN_00035a8c(6);
    DAT_ffffc256 = '\x01';
    DAT_ffffc255 = '\0';
  }
  cVar1 = DAT_ffffc256;
  if (DAT_ffffc256 == '\x01') {
    FUN_00035d80((int)DAT_ffffc261);
    cVar1 = DAT_ffffc288;
    if (DAT_ffffc288 == '\x01') {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc256 = '\0';
    }
  }
  return cVar1;
}


