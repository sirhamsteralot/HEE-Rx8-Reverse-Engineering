/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b984: Table 3D - 124 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00043c08; body bytes: 466; decompiled */

uint FUN_00043c08(void)

{
  char cVar1;
  char cVar3;
  char cVar4;
  uint uVar2;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float snapshot_DAT_ffffcad0;
  float arg1;
  
  cVar1 = DAT_ffffd1c5;
  snapshot_DAT_ffffcad0 = DAT_ffffcad0;
  fVar5 = rx8_absolute_difference(DAT_ffffaa70,lambda_target_ffffadfc);
  arg1 = 0.0;
  fVar6 = rx8_absolute_difference(DAT_ffffcab8,0.0);
  fVar7 = rx8_absolute_difference(DAT_ffffcabc,arg1);
  fVar8 = rx8_absolute_difference(DAT_ffffad50,arg1);
  cVar3 = rx8_is_outside_tolerance_band(DAT_ffffb2f0,arg1,0x3727c5ac);
  DAT_ffffcb38 = rx8_lookup_3d_raw_u8(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_124_0006b984);
  cVar4 = ref_getFaultStatus__(0x2c);
  if (((((((cVar4 != '\0') || (DAT_ffffcb3a != '\x01')) || (DAT_ffffb07d != '\x01')) ||
        ((inferred_coolant_temperature_ffffa98c < 70.0 || (snapshot_DAT_ffffcad0 < 400.0)))) ||
       (((1200.0 <= snapshot_DAT_ffffcad0 || ((0.0996 <= fVar5 || (DAT_ffffcb56 < 0x1f)))) || (vehicle_speed_ffffbbb4 < 0.0)))
       ) || ((((DAT_ffffcb38 < 0x80 || (50.0 <= fVar6)) || (0.05 <= fVar7)) ||
             (((0.42 <= fVar8 || (DAT_ffffc702 != '\x01')) ||
              ((DAT_ffffcacc != '\0' || (cVar1 != '\0')))))))) ||
     ((cVar3 != '\0' && (DAT_ffffb2f4 < 0x271)))) {
    DAT_ffffcac8 = 0;
  }
  else {
    DAT_ffffcac8 = 1;
  }
  if ((0.0996 <= fVar5) || (cVar1 != '\0')) {
    DAT_ffffcb56 = 0;
  }
  else {
    DAT_ffffcb56 = rx8_add_u16_saturate((int)(short)DAT_ffffcb56,1);
  }
  uVar2 = (uint)DAT_ffffcac8;
  if (uVar2 == 1) {
    if (0x25 < DAT_ffffcb58) {
      DAT_ffffcac9 = 1;
    }
    uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffcb58,1);
    DAT_ffffcb58 = (ushort)uVar2;
  }
  else {
    DAT_ffffcac9 = 0;
    DAT_ffffcb58 = 0;
  }
  return uVar2;
}


