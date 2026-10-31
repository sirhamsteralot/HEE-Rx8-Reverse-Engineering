/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b6f0: Table 2D - 259 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00041964; body bytes: 386; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00041a08) */

uint FUN_00041964(void)

{
  char cVar1;
  byte snapshot_DAT_ffffd1c5;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar3;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  undefined4 uVar9;
  undefined4 uVar10;
  
  snapshot_DAT_ffffd1c5 = DAT_ffffd1c5;
  cVar1 = DAT_ffffaa62;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  DAT_ffffc950 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_259_0006b6f0);
  uVar10 = 0;
  uVar9 = 0x3727c5ac;
  cVar4 = rx8_is_outside_tolerance_band(warmup_enrichment_total_ffffc00c,0,0x3727c5ac);
  cVar5 = rx8_is_outside_tolerance_band(DAT_ffffc01c,uVar10,uVar9);
  cVar6 = rx8_is_outside_tolerance_band(DAT_ffffb0c4,uVar10,uVar9);
  cVar7 = ref_getFaultStatus__(0x1f);
  if ((((cVar7 != '\0') || (cVar7 = ref_getFaultStatus__(0x20), cVar7 != '\0')) || (snapshot_DAT_ffffd1c5 != 0)) ||
     ((DAT_ffffb0da != '\x01' &&
      (((((closed_loop_active_ffffae1f != '\x01' || (snapshot_inferred_coolant_temperature_ffffa98c < 70.0)) ||
         ((150.0 <= snapshot_inferred_coolant_temperature_ffffa98c || ((60.0 <= intake_air_temperature_ffffaddc || (cVar4 != '\0')))))) || (cVar5 != '\0')) ||
       (((((cVar6 != '\0' || (1.0 <= engine_load_delta_ffffc150)) || (DAT_ffffcac8 != '\0')) ||
         (DAT_ffffc700 != '\0')) ||
        (((cVar1 != '\0' || (engine_load_ffffc0b4 < DAT_ffffc950)) &&
         ((cVar1 != '\x01' || (DAT_ffffc954 < 8)))))))))))) {
    DAT_ffffc94c = 0;
  }
  else {
    DAT_ffffc94c = 1;
  }
  uVar3 = (uint)snapshot_DAT_ffffd1c5;
  if ((uVar3 == 1) || (cVar1 == '\0')) {
    DAT_ffffc954 = 0;
  }
  else {
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffc954,1);
    DAT_ffffc954 = (ushort)uVar3;
  }
  return uVar3;
}


