/* ROM address: 0x0005bf50; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a740 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005bf50(void)

{
  undefined2 *puVar1;
  byte bVar2;
  
  puVar1 = &DAT_0005f728;
  bVar2 = 0;
  do {
    bVar2 = bVar2 + 1;
    **(undefined1 **)(puVar1 + 6) = 0;
    puVar1 = puVar1 + 8;
  } while (bVar2 < 0x1a);
  return;
}


