/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a4dc: Table 2D - 145 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000207b2; body bytes: 264; decompiled */

uint FUN_000207b2(void)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  
  cVar1 = fuel_cut_flag_b_ffffa445;
  fVar3 = (float)lookup_2d_descriptor_scaled(inferred_predicted_engine_speed_ffffb55c,&tbl_table_2d_145_0006a4dc);
  if (((((0xb < DAT_ffffb254) && (cVar1 == '\0')) && (DAT_ffffb262 == '\x01')) &&
      (DAT_ffffb0c9 == '\0')) &&
     (((fVar3 < DAT_ffffb41c || ((cranking_active_ffffaa62_ffffaa62 == '\0' && (DAT_ffffa450 == '\0')))) &&
      ((0x2c < DAT_ffffb258 || (DAT_ffffb264 == 0)))))) {
    DAT_ffffb264 = 1;
    DAT_ffffb248 = 0x43fa0000;
    DAT_ffffb25d = 0;
    DAT_ffffb258 = 0;
    DAT_ffffb269 = 1;
  }
  uVar2 = (uint)DAT_ffffb264;
  if (uVar2 == 1) {
    if (DAT_ffffb25d < 5) {
      os_schedule_task_event(0,4);
      DAT_ffffb25d = rx8_add_u8_saturate((int)(char)DAT_ffffb25d,1);
    }
    else {
      DAT_ffffb269 = 0;
    }
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb258,1);
    DAT_ffffb258 = (ushort)uVar2;
  }
  if (cVar1 == '\0') {
    DAT_ffffb254 = 0;
  }
  else {
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffb254,1);
    DAT_ffffb254 = (ushort)uVar2;
  }
  DAT_ffffb262 = cVar1;
  return uVar2;
}


