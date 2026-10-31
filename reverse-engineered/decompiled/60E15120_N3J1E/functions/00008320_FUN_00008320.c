/* ROM address: 0x00008320; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008320 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00008320(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_0000871c(uVar2);
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xff) < 6);
  return uVar1;
}


