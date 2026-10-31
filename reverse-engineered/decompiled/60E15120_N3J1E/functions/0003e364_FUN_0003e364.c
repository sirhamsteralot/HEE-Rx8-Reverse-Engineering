/* ROM address: 0x0003e364; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e900 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003e364(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc4c0;
  if (((DAT_ffffc6a9 == '\0') && (DAT_ffffc4c0 == '\x01')) && (DAT_ffffc6a8 == '\0')) {
    FUN_0003e214();
    FUN_0003e270();
    DAT_ffffc6a8 = '\x01';
  }
  DAT_ffffc6a9 = cVar1;
  return;
}


