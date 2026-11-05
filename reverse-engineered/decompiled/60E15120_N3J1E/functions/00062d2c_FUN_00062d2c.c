/* ROM address: 0x00062d2c; body bytes: 130; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0006161c (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062d2c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] == param_1) && (uVar1 != dtc_master_current_index_ffff8900._0_2_)) {
      _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] == -1) && (uVar1 != dtc_master_current_index_ffff8900._0_2_)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


