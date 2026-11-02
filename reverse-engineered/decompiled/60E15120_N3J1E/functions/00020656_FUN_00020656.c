/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a4dc: Table 2D - 145 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00020656; body bytes: 264; decompiled */

uint FUN_00020656(void)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  
  cVar1 = fuel_cut_flag_a_ffffa444;
  fVar3 = (float)lookup_2d_descriptor_scaled(inferred_predicted_engine_speed_ffffb55c,&tbl_table_2d_145_0006a4dc);
  if (((((0xb < DAT_ffffb252) && (cVar1 == '\0')) && (DAT_ffffb261 == '\x01')) &&
      (DAT_ffffb0c8 == '\0')) &&
     (((fVar3 < DAT_ffffb41c || ((cranking_active_ffffaa62_ffffaa62 == '\0' && (DAT_ffffa450 == '\0')))) &&
      ((0x2c < DAT_ffffb256 || (DAT_ffffb263 == 0)))))) {
    DAT_ffffb263 = 1;
    DAT_ffffb244 = 0x43fa0000;
    DAT_ffffb25c = 0;
    DAT_ffffb256 = 0;
    DAT_ffffb268 = 1;
  }
  uVar2 = (uint)DAT_ffffb263;
  if (uVar2 == 1) {
    if (DAT_ffffb25c < 5) {
      os_schedule_task_event(0,4);
      DAT_ffffb25c = rx8_add_u8_saturate((int)(char)DAT_ffffb25c,1);
    }
    else {
      DAT_ffffb268 = 0;
    }
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb256,1);
    DAT_ffffb256 = (ushort)uVar2;
  }
  if (cVar1 == '\0') {
    DAT_ffffb252 = 0;
  }
  else {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb252,1);
    DAT_ffffb252 = (ushort)uVar2;
  }
  DAT_ffffb261 = cVar1;
  return uVar2;
}


