/* ROM address: 0x0000d518; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d518 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000d518(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  cVar1 = FUN_0000d648(&DAT_ffff9300,&DAT_ffffdffb);
  FUN_0000a850();
  if (cVar1 == '\0') {
    FUN_00004c70(&DAT_ffffdffc);
    puVar4 = &DAT_ffff9300;
    for (puVar3 = &DAT_ffff6000; puVar3 < &DAT_ffff7fff; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    FUN_0000d648(&DAT_ffff6000,&DAT_ffff7fff);
    FUN_0000a850();
    puVar4 = &DAT_ffff9300;
    for (puVar3 = &DAT_ffff6000; puVar3 < &DAT_ffff7fff; puVar3 = puVar3 + 1) {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar3 = uVar2;
    }
    FUN_00004c76();
  }
  FUN_0000d5ac();
  DAT_ffffa3f0 = cVar1 != '\0';
  return;
}


