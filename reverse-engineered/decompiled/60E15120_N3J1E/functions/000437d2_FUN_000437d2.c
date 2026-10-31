/* ROM address: 0x000437d2; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043006 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_000437d2(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffbae5 >> 4;
  bVar1 = DAT_ffffbae6 >> 4;
  if ((((bVar2 == 3) && (bVar1 == 3)) || ((bVar2 == 4 && (bVar2 = bVar1, bVar1 == 4)))) &&
     (bVar2 = bVar1, DAT_ffffca43 == '\0')) {
    bVar2 = 1;
    DAT_ffffca4c = 1;
  }
  else {
    DAT_ffffca4c = 0;
  }
  return bVar2;
}


