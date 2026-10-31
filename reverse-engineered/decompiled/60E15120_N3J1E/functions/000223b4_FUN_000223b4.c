/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a254: Table 2D - 124 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a268: Table 2D - 125 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a27c: Table 2D - 126 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a2b0: Table 3D - 46 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000223b4; body bytes: 274; decompiled */

void FUN_000223b4(void)

{
  ushort snapshot_DAT_ffffa422;
  ushort uVar3;
  ushort uVar4;
  int iVar2;
  undefined *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  snapshot_DAT_ffffa422 = DAT_ffffa422;
  fVar7 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
  fVar6 = fVar6 - fVar7;
  DAT_ffffb34e = rx8_lookup_2d_raw_u16(fVar7,&PTR_CAL_table_845_0006a290);
  uVar3 = DAT_ffffb34e + 0xf;
  uVar4 = DAT_ffffb34e + 0x61;
  DAT_ffffb348 = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&PTR_PTR_0006a2b0);
  if (engine_running_ffffa428 == '\0') {
    if (12.0 <= fVar6) {
      DAT_ffffb340 = '\x01';
    }
    else {
      DAT_ffffb340 = '\0';
    }
  }
  fVar6 = 0.0;
  if (DAT_ffffb338 == '\0') {
    DAT_ffffb33c = 0.0;
  }
  else {
    if (DAT_ffffb340 == '\x01') {
      if (uVar3 <= snapshot_DAT_ffffa422) {
        if (snapshot_DAT_ffffa422 < uVar4) {
          puVar5 = &tbl_table_2d_125_0006a268;
        }
        else {
          puVar5 = &tbl_table_2d_126_0006a27c;
        }
        DAT_ffffb33c = (float)lookup_2d_descriptor_scaled(fVar7,puVar5);
        goto LAB_000224ca;
      }
      puVar5 = &tbl_table_2d_124_0006a254;
    }
    else {
      puVar5 = &tbl_table_2d_126_0006a27c;
    }
    DAT_ffffb33c = (float)lookup_2d_descriptor_scaled(fVar7,puVar5);
  }
LAB_000224ca:
  fVar7 = rx8_clamp_float(DAT_ffffb33c,fVar6,DAT_ffffb348);
  fVar8 = 100.0;
  fVar6 = 65536.0;
  iVar2 = FUN_0005c49c((int)((fVar7 / 100.0) * 65536.0));
  DAT_ffffb330 = ((float)iVar2 / fVar6) * fVar8;
  return;
}


