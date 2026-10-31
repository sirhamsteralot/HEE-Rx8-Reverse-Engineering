/* ROM address: 0x0001077a; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001076e (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001077a(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (puVar1 = &DAT_ffffa578; puVar1 < &DAT_ffffa5d0; puVar1 = puVar1 + 0x2c) {
    for (pcVar3 = puVar1 + 0xc; pcVar2 = pcVar3, pcVar3 < puVar1 + 0x2c; pcVar3 = pcVar3 + 0x10) {
      while (pcVar2 = pcVar2 + 1, pcVar2 < pcVar3 + 3) {
        FUN_00008e28((int)*pcVar2);
      }
    }
  }
  return;
}


