/* ROM address: 0x00035ea0; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000365c0 (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_ImmoUpdateRelated(void)

{
  if (DAT_ffffc265 == '\0') {
    if (DAT_ffffc266 == '\0') {
      if (DAT_ffffc268 == 'Z') {
        DAT_ffffc265 = '\x01';
      }
      else {
        DAT_ffffc268 = 'Z';
        DAT_ffffc261 = '\f';
        FUN_00035a8c(0xc);
        DAT_ffffc267 = '\x01';
        DAT_ffffc266 = '\x01';
      }
    }
    else if (DAT_ffffc267 == '\x01') {
      FUN_00035d80((int)DAT_ffffc261);
      if (DAT_ffffc288 == '\x01') {
        DAT_ffffc262 = 0;
        DAT_ffffc267 = 0;
        DAT_ffffc261 = 3;
        FUN_00035a8c(3);
        return;
      }
    }
    else {
      FUN_00035d80((int)DAT_ffffc261);
      if (DAT_ffffc288 == '\x01') {
        DAT_ffffc262 = 0;
        DAT_ffffc261 = '\0';
        DAT_ffffc265 = '\x01';
        DAT_ffffc266 = '\0';
      }
    }
  }
  return;
}


