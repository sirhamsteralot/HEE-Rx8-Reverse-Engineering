/* ROM address: 0x0001a614; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b0c4 (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0001a614(void)

{
  char cVar1;
  
  DAT_ffffad08 = FUN_0005d2ec(0);
  DAT_ffffad09 = FUN_0005d388(0);
  DAT_ffffad04 = FUN_0005d450(0);
  DAT_ffffad06 = FUN_0005d528(0);
  cVar1 = FUN_0005bffe(0x15);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_0005bffe(0x16), cVar1 != '\x01')) &&
      (cVar1 = FUN_0005bffe(0x17), cVar1 != '\x01')) &&
     (cVar1 = FUN_0005bffe(0x18), cVar1 != '\x01')) {
    DAT_ffffad0a = 0;
    return 0;
  }
  DAT_ffffad0a = 1;
  return 1;
}


