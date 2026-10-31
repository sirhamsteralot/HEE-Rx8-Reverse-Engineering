/* ROM address: 0x0005d77c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005bf6c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0005d77c(void)

{
  char cVar1;
  
  if (engine_stopped_latch_ffffa41c == '\x01') {
    DAT_ffffd36c = 0x80;
    cVar1 = '\x01';
  }
  else {
    cVar1 = DAT_ffffaa63;
    if ((DAT_ffffaa63 == '\x01') && (cVar1 = DAT_ffffb53a, DAT_ffffb53a == '\x01')) {
      DAT_ffffd36c = 0x40;
    }
    else {
      DAT_ffffd36c = 0x20;
    }
  }
  return cVar1;
}


