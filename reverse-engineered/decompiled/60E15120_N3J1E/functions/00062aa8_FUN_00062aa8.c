/* ROM address: 0x00062aa8; body bytes: 192; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061398 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062aa8(void)

{
  if (DAT_ffff87a4._0_1_ == '\0') {
    DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
    *(ushort *)(&DAT_ffff8d54 + (uint)DAT_ffff879c * 2) =
         (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
    DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  }
  if (DAT_ffff87a6._0_1_ == '\0') {
    dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement((int)DAT_ffff8904);
  }
  if (DAT_ffff87a8._0_1_ == '\0') {
    DAT_ffff8d4c = rx8_pack_u16_with_complement((int)DAT_ffff8d50);
  }
  if (DAT_ffff87aa == '\0') {
    FUN_000675b0();
  }
  if (DAT_ffff87ac._0_1_ == '\0') {
    FUN_00067b16();
  }
  DAT_ffff8798 = rx8_pack_u8_with_complement(1);
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  return;
}


