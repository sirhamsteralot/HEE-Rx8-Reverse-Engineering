/* ROM address: 0x00009016; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009016 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00009016(int param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_ffffa0d8;
    bVar2 = 0;
    do {
      bVar2 = bVar2 + 1;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1 = puVar1 + 8;
    } while (bVar2 < 4);
  }
  return;
}


