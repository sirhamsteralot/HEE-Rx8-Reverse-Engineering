/* ROM address: 0x0001c0d4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001cb84 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001c0d4(void)

{
  undefined4 *puVar1;
  byte bVar2;
  
  puVar1 = &DAT_ffffae6c;
  bVar2 = 1;
  do {
    *puVar1 = 0;
    bVar2 = bVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (bVar2 < 0x16);
  return;
}


