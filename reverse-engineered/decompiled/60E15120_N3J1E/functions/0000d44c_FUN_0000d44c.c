/* ROM address: 0x0000d44c; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d44c (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000d44c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa3fb;
  if (uVar1 == 1) {
    uVar1 = jump_to_0x00006366();
    DAT_ffff8000 = 0xaa55;
  }
  return uVar1;
}


