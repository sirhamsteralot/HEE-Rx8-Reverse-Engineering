/* ROM address: 0x000443f4; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043c28 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000443f4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffd1c5;
  if ((DAT_ffffd1c5 == '\x01') && (cVar1 = engine_stopped_latch_ffffa41c, engine_stopped_latch_ffffa41c == '\x01')) {
    DAT_ffffcb60 = 0;
    DAT_ffffcb62 = 0;
    DAT_ffffcb68 = 0;
  }
  return cVar1;
}


