/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_learned_table_cell_read [high]: Fetches two neighbouring learned floats: base 0xffff8108 (pool 0x2850c) + bank*0x220 (mov.w pool 0x284f6) + cell*8, via ref_readValue_float_DEFAULTVAL_ADDRESS 0x3dc22 (pool 0x28508); returns them for RPM interpolation. Called from 0x28198.
 */
/* ROM address: 0x00028484; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028dcc (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_learned_table_cell_read(short param_1,ushort param_2,ushort param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = &e2ram_learned_table_value_pos_ffff8108;
  uVar3 = 0;
  if (param_1 != 0) {
    puVar1 = &e2ram_learned_table_value_neg_ffff8328;
  }
  uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,puVar1 + (uint)param_2 * 8);
  *param_4 = uVar2;
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar3,puVar1 + (uint)param_3 * 8);
  *param_5 = uVar3;
  return;
}


