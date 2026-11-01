/* ROM address: 0x00061014; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f904 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061014(void)

{
  char cVar2;
  short sVar1;
  undefined4 uVar3;
  
  uVar3 = 0;
  cVar2 = FUN_000655e4();
  if ((((cVar2 != '\0') || (cVar2 = FUN_000644e4(), cVar2 != '\0')) ||
      (sVar1 = FUN_00002034(&inferred_ram_8788_ffff8788_ffff8788), sVar1 != 0)) ||
     ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff878c), cVar2 != '\0' ||
      (sVar1 = FUN_00002034(&DAT_ffff8784), sVar1 != 0)))) {
    uVar3 = 1;
  }
  return uVar3;
}


