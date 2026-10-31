/* ROM address: 0x00067a24; body bytes: 68; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00066314 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067a24(void)

{
  undefined2 *puVar1;
  
  _DAT_ffff8fb4 = rx8_pack_u16_with_complement(0);
  _DAT_ffff8fb8 = rx8_pack_u16_with_complement(1);
  puVar1 = &DAT_ffff8fa0;
  do {
    *puVar1 = 0xffff;
    puVar1[2] = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    *(undefined1 *)(puVar1 + 4) = 0xa7;
    puVar1 = puVar1 + 5;
  } while (puVar1 < &DAT_ffff8fb4);
  return 0xa7;
}


