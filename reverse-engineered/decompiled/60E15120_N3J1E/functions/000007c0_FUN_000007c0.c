/* ROM address: 0x000007c0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000007c0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000007c0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 1) & 0xffffff07;
  if (uVar1 == 4) {
    DAT_ffffdfa0 = FUN_000000f4();
    if (DAT_ffffdfb8 == '\x01') {
      DAT_ffffdfb8 = '\0';
    }
    uVar1 = FUN_00000338(0x98,4,param_1 + 2);
    return uVar1;
  }
  return uVar1;
}


