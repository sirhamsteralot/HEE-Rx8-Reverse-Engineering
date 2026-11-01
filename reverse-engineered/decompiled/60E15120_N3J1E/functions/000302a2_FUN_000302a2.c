/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aac4: Table 2D - 171 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000302a2; body bytes: 192; decompiled */

undefined4 * FUN_000302a2(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  undefined *puVar2;
  
  if (-42.5 <= inferred_coolant_temperature_ffffa98c) {
    puVar1 = &DAT_00030340;
    if (-40.0 <= inferred_coolant_temperature_ffffa98c) {
      DAT_ffffbea6 = '\x01';
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
    DAT_ffffbea6 = '\0';
  }
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffbe9c = ((float)crank_period_accumulator_ffff9f88 * 0.25) / 1000.0;
    if (inferred_ram_ce32_ffffce32_ffffce32 == '\x01') {
      puVar2 = &tbl_table_2d_171_0006aac4;
    }
    else {
      puVar2 = &DAT_0006aad8;
    }
    DAT_ffffbe70 = (float)lookup_2d_descriptor_scaled(DAT_ffffbe9c,puVar2);
    DAT_ffffbe74 = (float)lookup_2d_descriptor_scaled(DAT_ffffbe9c,&DAT_0006aaec);
    DAT_ffffbe6c = DAT_ffffbe74;
    if (DAT_ffffbea6 == '\x01') {
      DAT_ffffbe6c = DAT_ffffbe70;
    }
    DAT_ffffbe78 = 0x3e4c0003;
    DAT_ffffbe7c = rx8_first_order_filter(DAT_ffffbe6c,DAT_ffffbe7c,0.1992188,1e-05);
    puVar1 = extraout_r0;
  }
  return puVar1;
}


