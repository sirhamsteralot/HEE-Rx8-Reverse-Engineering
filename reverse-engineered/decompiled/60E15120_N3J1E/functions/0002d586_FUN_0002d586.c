/* ROM address: 0x0002d586; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002dc2a (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_0002d586(void)

{
  undefined1 uVar1;
  
  if (DAT_ffffbcec == '\0') {
    uVar1 = 0;
    DAT_ffffbced = 0;
  }
  else if ((DAT_ffffbfb4 == '\x01') || (DAT_ffffbfb5 == '\x01')) {
    uVar1 = 1;
    DAT_ffffbced = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


