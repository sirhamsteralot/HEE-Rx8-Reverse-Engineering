/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ba68: Table 2D - 279 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ba7c: Table 2D - 280 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ba90: Table 2D - 281 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006baa4: Table 2D - 385 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004910e; body bytes: 4; decompiled */

uint ref_calcSpeedBasedIATCompensation_0004910e(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r0;
  float fVar4;
  float fVar5;
  float extraout_fr0;
  float arg1;
  float snapshot_vehicle_speed_ffffbbb4;
  
  cVar1 = engine_running_flag_ffffaa68;
  arg1 = intake_air_temperature_ffffaddc;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  fVar4 = (float)lookup_2d_descriptor_scaled(vehicle_speed_ffffbbb4,&tbl_table_2d_279_0006ba68);
  fVar5 = (float)lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_280_0006ba7c);
  uVar2 = rx8_lookup_2d_raw_u16(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_385_check_datatype_0006baa4);
  uVar3 = lookup_2d_descriptor_scaled(snapshot_vehicle_speed_ffffbbb4,&tbl_table_2d_281_0006ba90);
  if (((((snapshot_vehicle_speed_ffffbbb4 <= 80.0) || (engine_load_ffffc0b4 <= fVar4)) || (mass_air_flow_ffffa9ec <= fVar5)) ||
      ((uVar3 = 1, DAT_ffffc5e6 == '\x01' || (uVar3 = 1, DAT_ffffc5db == '\x01')))) ||
     (uVar3 = 1, DAT_ffffc61e == '\x01')) {
    DAT_ffffccfc = 0xea6;
  }
  else {
    uVar3 = (uint)DAT_ffffccfc;
    if (uVar3 < (uVar2 & 0xffff)) {
      DAT_ffffccfc = 0;
    }
    else {
      DAT_ffffccfc = DAT_ffffccfc - (short)uVar2;
    }
  }
  if (DAT_ffffccfc == 0) {
    DAT_ffffccf4 = arg1 - extraout_fr0;
  }
  else {
    DAT_ffffccf4 = rx8_min_float(DAT_ffffccf4,arg1);
    uVar3 = extraout_r0;
  }
  if ((cVar1 == '\0') && (uVar3 = (uint)DAT_ffffccfe, uVar3 == 1)) {
    uVar3 = ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffccf4,&DAT_ffff8768);
  }
  DAT_ffffccfe = cVar1;
  return uVar3;
}


