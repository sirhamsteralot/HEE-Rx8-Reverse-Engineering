/* ROM address: 0x00067518; body bytes: 152; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00065e08 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067518(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8ea0)[uVar1 * 0x14] == param_1) && (uVar1 != DAT_ffff8f98)) {
      _DAT_ffff8f9c = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff8ea0)[uVar1 * 0x14] == -1) && (uVar1 != DAT_ffff8f98)) break;
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8f9c = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


