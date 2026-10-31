/* ROM address: 0x000235c8; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023e3c (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000235c8(void)

{
  uint uVar1;
  
  FUN_0002377a();
  uVar1 = FUN_0000b99c(&DAT_ffffb440,&DAT_ffffb478,0x1c);
  if ((uVar1 & 0xff) == 0) {
    DAT_ffffb43c = 0;
    uVar1 = FUN_0002376c();
    return uVar1;
  }
  DAT_ffffb43c = 1;
  return uVar1;
}


