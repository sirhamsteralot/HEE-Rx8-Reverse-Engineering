/* ROM address: 0x000454d2; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004455e (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_000454d2(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  
  uVar2 = PFDR_W;
  bVar1 = (uVar2 & 0x8000) == 0;
  if (bVar1) {
    cVar3 = DAT_ffffcbd1;
    if (DAT_ffffcbd1 == '\x01') {
      DAT_ffffcbd0 = 1;
    }
  }
  else {
    cVar3 = bVar1;
    if (DAT_ffffcbd1 == '\0') {
      DAT_ffffcbd0 = 0;
    }
  }
  DAT_ffffcbd1 = bVar1;
  return cVar3;
}


