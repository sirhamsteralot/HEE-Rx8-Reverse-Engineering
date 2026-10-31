/* ROM address: 0x00000064; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000064 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00000064(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0x90,6,0xff8);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


