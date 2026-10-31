/* ROM address: 0x00068ba8; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067498 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068ba8(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_ffffddfc;
  puVar1 = &DAT_ffffde04;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (puVar1 < &DAT_ffffde20);
  return;
}


