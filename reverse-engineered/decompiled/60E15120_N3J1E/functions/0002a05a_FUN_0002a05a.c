/* ROM address: 0x0002a05a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a7ae (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0002a05a(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  if ((engine_running_ffffa428 == '\x01') || (cVar1 = engine_injectors_off_ffffa42c, engine_injectors_off_ffffa42c == '\x01')) {
    DAT_ffffbb48 = 1;
  }
  else {
    DAT_ffffbb48 = 0;
  }
  return cVar1;
}


