/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00028198; body bytes: 440; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00028ae0 (264 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_learned_table_apply(void)

{
  ushort snapshot_DAT_ffffb6c4;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  undefined4 uVar10;
  float snapshot_DAT_ffffb668;
  float snapshot_engine_speed_rpm_ffffb548;
  float local_3c;
  float local_38;
  short sStack_34;
  
  snapshot_DAT_ffffb6c4 = e2ram_learned_table_cell_index_ffffb6c4;
  uVar10 = 0;
  iVar8 = (int)(short)e2ram_learned_table_cell_index_ffffb6c4;
  uVar2 = (int)sector_parity_bank_ffffb660 & 1;
  iVar6 = uVar2 * 4;
  snapshot_DAT_ffffb668 = DAT_ffffb668;
  if ((engine_speed_rpm_ffffb548 < 750.0) || (9000.0 <= engine_speed_rpm_ffffb548)) {
    if (uVar2 == 0) {
      _DAT_ffffba64 =
           ref_readValue_float_DEFAULTVAL_ADDRESS(0,&e2ram_learned_table_value_pos_ffff8108 + (uint)e2ram_learned_table_cell_index_ffffb6c4 * 8);
    }
    else {
      uVar10 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&e2ram_learned_table_value_neg_ffff8328 + (uint)e2ram_learned_table_cell_index_ffffb6c4 * 8);
      *(undefined4 *)(&e2ram_learned_table_value_bank0_ffffba64 + iVar6) = uVar10;
    }
  }
  else {
    uVar7 = 0;
    sStack_34 = e2ram_learned_table_cell_index_ffffb6c4 - 1;
    snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
    do {
      uVar3 = rx8_add_u8_saturate(uVar7,1);
      iVar5 = iVar8;
      if (((float)(&CAL_Table_2D___333_Check_DataType_648)[uVar7 & 0xff] <= snapshot_engine_speed_rpm_ffffb548) &&
         (snapshot_engine_speed_rpm_ffffb548 < *(float *)(&CAL_table_647 + (uVar3 & 0xff) * 4))) {
        if (snapshot_DAT_ffffb6c4 < 0x43) {
          iVar8 = rx8_add_u16_saturate(iVar8,1);
        }
LAB_000282a0:
        e2ram_learned_table_cell_read(uVar2,iVar5,iVar8,&local_3c,&local_38);
        break;
      }
      if ((*(float *)(&CAL_table_647 + (uVar3 & 0xff) * 4) <= snapshot_engine_speed_rpm_ffffb548) &&
         (snapshot_engine_speed_rpm_ffffb548 < (float)(&CAL_Table_2D___333_Check_DataType_648)[uVar3 & 0xff])) {
        if (snapshot_DAT_ffffb6c4 != 0) {
          iVar5 = (int)sStack_34;
        }
        goto LAB_000282a0;
      }
      uVar7 = uVar7 + 1;
    } while ((uVar7 & 0xff) < 0x10);
    fVar9 = (float)(&CAL_Table_2D___333_Check_DataType_648)[uVar3 & 0xff] -
            (float)(&CAL_Table_2D___333_Check_DataType_648)[uVar7 & 0xff];
    cVar4 = rx8_is_outside_tolerance_band(fVar9,uVar10,0x3727c5ac);
    if (cVar4 != '\0') {
      local_3c = local_3c +
                 ((snapshot_engine_speed_rpm_ffffb548 - (float)(&CAL_Table_2D___333_Check_DataType_648)[uVar7 & 0xff]) / fVar9)
                 * (local_38 - local_3c);
    }
    *(float *)(&e2ram_learned_table_value_bank0_ffffba64 + iVar6) = local_3c;
  }
  DAT_ffffba48 = misfire_excess_deviation_delayed_ffffba44;
  misfire_excess_deviation_delayed_ffffba44 = misfire_excess_deviation_ffffba40;
  e2ram_learned_correction_value_ffffba2c = (snapshot_DAT_ffffb668 - (DAT_ffffb680 - snapshot_DAT_ffffb668) / 6.0) - DAT_ffffb664;
  misfire_residual_ffffba30 = e2ram_learned_correction_value_ffffba2c - *(float *)(&e2ram_learned_table_value_bank0_ffffba64 + iVar6);
  return;
}


