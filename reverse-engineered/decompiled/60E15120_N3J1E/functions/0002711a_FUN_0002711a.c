/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a694: Table 2D - 332 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002711a; body bytes: 94; decompiled */

void FUN_0002711a(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  float snapshot_engine_load_ffffc0b4;
  
  snapshot_engine_load_ffffc0b4 = engine_load_ffffc0b4;
  uVar1 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&tbl_table_2d_332_check_datatype_0006a694);
  DAT_ffffba10 = (undefined2)uVar1;
  uVar2 = DAT_ffffba10;
  if (0.4 <= snapshot_engine_load_ffffc0b4) {
    if (0.65 <= snapshot_engine_load_ffffc0b4) {
      if (3.0 <= snapshot_engine_load_ffffc0b4) {
        uVar3 = 0x33;
      }
      else {
        uVar3 = 0x22;
      }
      uVar2 = rx8_add_u16_saturate(uVar1,uVar3);
    }
    else {
      uVar2 = rx8_add_u16_saturate(uVar1,0x11);
    }
  }
  e2ram_learned_table_cell_index_ffffb6c4 = uVar2;
  return;
}


