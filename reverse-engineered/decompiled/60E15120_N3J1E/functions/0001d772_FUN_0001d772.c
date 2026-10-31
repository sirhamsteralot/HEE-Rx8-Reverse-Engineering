/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069bf4: Table 2D - 81 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c08: Table 2D - 82 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001d772; body bytes: 140; decompiled */

void FUN_0001d772(void)

{
  float arg0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffcac8 == '\x01') {
    DAT_ffffb0b0 = 0.65;
    DAT_ffffb0b4 = 0.0;
    DAT_ffffb0b8 = 0.0;
  }
  else {
    DAT_ffffb0b0 = 0.5;
    DAT_ffffb0b4 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_table_2d_81_00069bf4);
    uVar1 = rx8_decode_u16_affine(0x41000000,uVar1,(int)engine_running_timer_ffffa424);
    DAT_ffffb0b8 = (float)lookup_2d_descriptor_scaled(uVar1,&tbl_table_2d_82_00069c08);
  }
  arg0 = rx8_first_order_filter(DAT_ffffb0b0 + DAT_ffffb0b4 + DAT_ffffb0b8,DAT_ffffb078,1.0,1e-05);
  DAT_ffffb078 = rx8_clamp_float(arg0,0.0,1.0);
  return;
}


