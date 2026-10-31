/* ROM address: 0x000655e4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063ed4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000655e4(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7c);
  if ((cVar1 != '\0') || (cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7e), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


