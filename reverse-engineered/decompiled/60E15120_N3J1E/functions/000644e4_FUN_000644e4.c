/* ROM address: 0x000644e4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062dd4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000644e4(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e78);
  if ((cVar1 != '\0') || (cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7a), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


