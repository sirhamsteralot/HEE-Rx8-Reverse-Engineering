/* ROM address: 0x000623b0; body bytes: 112; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060ca0 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000623b0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87a4._0_1_ == '\x02') {
    uVar1 = (uint)DAT_ffff879c;
    _DAT_ffff8e72 = rx8_pack_u8_with_complement((int)(char)(&DAT_ffff8d54)[uVar1 * 2]);
    _DAT_ffff8e74 = rx8_pack_u8_with_complement((int)(char)(&DAT_ffff8d55)[uVar1 * 2]);
    _DAT_ffff8e70 = rx8_pack_u8_with_complement((int)DAT_ffff8e6c._0_1_);
    DAT_ffff87a4 = rx8_pack_u8_with_complement(1);
  }
  else if (DAT_ffff87a4._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a4 = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}


