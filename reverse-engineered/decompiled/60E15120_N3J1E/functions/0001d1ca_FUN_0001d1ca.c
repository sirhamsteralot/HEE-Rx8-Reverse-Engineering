/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069adc: Table 3D - 32 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001d1ca; body bytes: 184; decompiled */

uint FUN_0001d1ca(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (DAT_ffffcac8 == '\0') {
    uVar2 = engine_speed_rpm_ffffb548;
    uVar3 = mass_air_flow_ffffa9ec;
    DAT_ffffb016 = rx8_lookup_3d_raw_u16(mass_air_flow_ffffa9ec,engine_speed_rpm_ffffb548,&DAT_00069a98);
    DAT_ffffaff4 = lookup_3d_descriptor_scaled(uVar3,uVar2,&DAT_00069ac0);
  }
  else {
    uVar2 = engine_speed_rpm_ffffb548;
    uVar3 = mass_air_flow_ffffa9ec;
    DAT_ffffb016 = rx8_lookup_3d_raw_u16(mass_air_flow_ffffa9ec,engine_speed_rpm_ffffb548,&DAT_00069aac);
    DAT_ffffaff4 = lookup_3d_descriptor_scaled(uVar3,uVar2,&tbl_table_3d_32_00069adc);
  }
  uVar1 = 1;
  if ((DAT_ffffc700 == '\x01') ||
     ((((uVar1 = (uint)closed_loop_active_ffffae1f, uVar1 == 1 && (150.0 <= inferred_coolant_temperature_ffffa98c)) &&
       (uVar1 = (uint)DAT_ffffad24, uVar1 == 1)) && (uVar1 = (uint)DAT_ffffae20, uVar1 == 0)))) {
    DAT_ffffae21 = 1;
  }
  else {
    DAT_ffffae21 = 0;
  }
  return uVar1;
}


