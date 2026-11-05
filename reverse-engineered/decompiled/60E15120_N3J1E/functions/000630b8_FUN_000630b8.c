/* ROM address: 0x000630b8; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000619a8 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000630b8(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87bc)[uVar1 * 0x10];
}


