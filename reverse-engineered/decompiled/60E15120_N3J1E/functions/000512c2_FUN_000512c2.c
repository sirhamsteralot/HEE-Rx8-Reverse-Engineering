/* ROM address: 0x000512c2; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004ef76 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000512c2(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = (uint)DAT_ffffcfb5;
  bVar2 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd0d5 == '\0') && (uVar1 = (uint)bVar2, uVar1 == 1)) {
    DAT_ffffd0a9 = 0;
    DAT_ffffd0aa = 0;
  }
  DAT_ffffd0d5 = bVar2;
  return uVar1;
}


