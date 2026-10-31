/* ROM address: 0x00063680; body bytes: 134; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061f70 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063680(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8908)[uVar1 * 0x1a] == param_1) && (uVar1 != DAT_ffff8d4c._0_2_)) {
      _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff890f)[uVar1 * 0x34] == '\0') && (uVar1 != DAT_ffff8d4c._0_2_)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


