/* ROM address: 0x00062918; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061208 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062918(void)

{
  uint uVar1;
  
  FUN_00067b58();
  uVar1 = (uint)DAT_ffff87ac._0_1_;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    DAT_ffff87ac = (undefined2)uVar1;
  }
  return uVar1;
}


