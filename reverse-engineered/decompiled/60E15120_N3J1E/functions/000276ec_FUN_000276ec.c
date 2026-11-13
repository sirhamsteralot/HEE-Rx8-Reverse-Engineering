/* ROM address: 0x000276ec; body bytes: 218; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028034 (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 *
FUN_000276ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar2;
  undefined2 *puVar1;
  short sVar3;
  undefined2 *extraout_r0;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  float fVar7;
  
  uVar2 = sector_parity_bank_ffffb660 & 1;
  puVar1 = &DAT_ffffba04;
  if ((((DAT_ffffba04 != 0) && (DAT_ffffba06 == 0)) && (DAT_ffffb8f0 - 100.0 <= engine_speed_rpm_ffffb548)) &&
     (engine_speed_rpm_ffffb548 < DAT_ffffb8f0 + 100.0)) {
    uVar5 = (uint)e2ram_learned_table_cell_index_ffffb6c4;
    uVar4 = (uint)e2ram_learned_table_cell_index_ffffb6c4;
    if ((&e2ram_learned_table_live_counter_ffffb8f4)[(uint)uVar2 * 0x44 + uVar5] == 0) {
      psVar6 = &e2ram_learned_table_live_counter_ffffb8f4 + (uint)uVar2 * 0x44 + uVar5;
      puVar1 = (undefined2 *)rx8_add_u16_saturate((int)*psVar6,1,param_3,param_4,psVar6);
      *psVar6 = (short)puVar1;
      (&e2ram_learned_table_live_value_ffffb6cc)[(uint)uVar2 * 0x44 + uVar4] = e2ram_learned_correction_value_ffffba2c;
    }
    else {
      psVar6 = &e2ram_learned_table_live_counter_ffffb8f4 + (uint)uVar2 * 0x44 + uVar5;
      sVar3 = rx8_add_u16_saturate((int)*psVar6,1,param_3,param_4,psVar6);
      *psVar6 = sVar3;
      fVar7 = rx8_first_order_filter
                        (e2ram_learned_correction_value_ffffba2c,(float)(&e2ram_learned_table_live_value_ffffb6cc)[(uint)uVar2 * 0x44 + uVar4],0.031,1e-05
                        );
      (&e2ram_learned_table_live_value_ffffb6cc)[(uint)uVar2 * 0x44 + uVar4] = fVar7;
      puVar1 = extraout_r0;
    }
  }
  return puVar1;
}


