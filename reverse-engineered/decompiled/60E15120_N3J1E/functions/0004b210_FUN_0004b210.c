/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bb88: Table 2D - 286 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bb9c: Table 2D - 287 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006bbb0: Table 3D - 102 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004b210; body bytes: 304; decompiled */

uint FUN_0004b210(void)

{
  bool bVar1;
  char cVar2;
  uint extraout_r0;
  uint uVar3;
  uint extraout_r0_00;
  uint extraout_r0_01;
  float fVar4;
  float fVar5;
  float fVar6;
  float arg2;
  float arg1;
  
  cVar2 = DAT_ffffd147;
  bVar1 = ((int)DAT_ffffcfb5 & 0x80U) != 0;
  arg1 = 0.0;
  uVar3 = 1;
  if ((DAT_ffffd263 != '\x01') && (uVar3 = 1, DAT_ffffc932 != '\x01')) {
    arg2 = 100.0;
    if (DAT_ffffd264 == '\x01') {
      DAT_ffffce04 = 100.0;
      DAT_ffffce0c = DAT_ffffd147;
      return 1;
    }
    if (((bVar1) && (DAT_ffffce0c == '\0')) && (DAT_ffffd147 == '\x01')) {
      DAT_ffffce04 = 0.0;
      DAT_ffffce0c = DAT_ffffd147;
      return 0;
    }
    if ((bVar1) && (DAT_ffffd147 == '\x01')) {
      DAT_ffffce04 = rx8_min_float(DAT_ffffce04 + 0.0,0.0);
      DAT_ffffce0c = cVar2;
      return extraout_r0;
    }
    uVar3 = (uint)DAT_ffffcf85;
    if (uVar3 < 0x28) {
      if (uVar3 != 0) {
        DAT_ffffce04 = rx8_min_float(DAT_ffffce04 + 2.0,DAT_ffffcf80);
        DAT_ffffce0c = cVar2;
        return extraout_r0_00;
      }
      if (DAT_ffffcf9c != '\0') {
        fVar4 = (float)lookup_3d_descriptor_scaled(DAT_ffffce10,DAT_ffffbe00,&tbl_table_3d_102_0006bbb0);
        fVar5 = (float)lookup_2d_descriptor_scaled(intake_air_temperature_ffffaddc,&tbl_table_2d_286_0006bb88);
        fVar6 = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_287_0006bb9c);
        DAT_ffffce04 = rx8_clamp_float(fVar6 + fVar4 * fVar5,arg1,arg2);
        DAT_ffffce0c = cVar2;
        return extraout_r0_01;
      }
      DAT_ffffce04 = 0.0;
      DAT_ffffce0c = DAT_ffffd147;
      return 0;
    }
  }
  DAT_ffffce04 = 0.0;
  DAT_ffffce0c = cVar2;
  return uVar3;
}


