/* ROM address: 0x00063e24; body bytes: 84; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00062714 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063e24(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&DAT_ffff8d54;
  do {
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 < &DAT_ffff8e6c);
  DAT_ffff8e6c = rx8_pack_u8_with_complement(0xa5);
  DAT_ffff8e6e = rx8_pack_u8_with_complement(0xa5);
  _DAT_ffff8e70 = rx8_pack_u8_with_complement(0xa5);
  _DAT_ffff8e72 = rx8_pack_u8_with_complement(0);
  _DAT_ffff8e74 = rx8_pack_u8_with_complement(0);
  return;
}


