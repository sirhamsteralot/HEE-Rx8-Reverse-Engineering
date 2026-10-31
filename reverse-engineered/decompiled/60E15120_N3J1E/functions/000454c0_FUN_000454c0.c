/* ROM address: 0x000454c0; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004454c (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000454c0(void)

{
  ushort uVar1;
  
  uVar1 = PFDR_W;
  DAT_ffffcbd1 = (uVar1 & 0x8000) == 0;
  return;
}


