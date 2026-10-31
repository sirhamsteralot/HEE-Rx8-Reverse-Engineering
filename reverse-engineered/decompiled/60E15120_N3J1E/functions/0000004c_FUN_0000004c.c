/* ROM address: 0x0000004c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000004c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000004c(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0x88,6,0xfec);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


