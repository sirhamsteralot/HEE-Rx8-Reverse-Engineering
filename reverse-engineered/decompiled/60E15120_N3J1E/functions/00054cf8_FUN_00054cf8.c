/* ROM address: 0x00054cf8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052de4 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00054cf8(void)

{
  uint uVar1;
  
  if (DAT_ffff9010 == -0x5b) {
    uVar1 = FUN_00054ca6();
    if ((uVar1 & 0xffff) == (uint)DAT_ffff9012) {
      return uVar1 & 0xffff;
    }
  }
  uVar1 = FUN_00054c6c();
  return uVar1;
}


