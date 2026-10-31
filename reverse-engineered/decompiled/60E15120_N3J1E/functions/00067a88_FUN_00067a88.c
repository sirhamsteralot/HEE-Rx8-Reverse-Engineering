/* ROM address: 0x00067a88; body bytes: 142; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00066378 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067a88(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8fa0)[uVar1 * 5] == param_1) && (uVar1 != DAT_ffff8fb4)) {
      _DAT_ffff8fb8 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff8fa0)[uVar1 * 5] == -1) && (uVar1 != DAT_ffff8fb4)) break;
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8fb8 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


