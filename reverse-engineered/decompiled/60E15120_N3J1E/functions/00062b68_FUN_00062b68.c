/* ROM address: 0x00062b68; body bytes: 2; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061458 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062b68(void)

{
  DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  *(ushort *)(&DAT_ffff8d54 + (uint)DAT_ffff879c * 2) =
       (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
  DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  return;
}


