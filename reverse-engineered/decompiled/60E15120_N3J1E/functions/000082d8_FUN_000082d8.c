/* ROM address: 0x000082d8; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000082d8 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000082d8(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_000087a2(uVar2);
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xff) < 6);
  return uVar1;
}


