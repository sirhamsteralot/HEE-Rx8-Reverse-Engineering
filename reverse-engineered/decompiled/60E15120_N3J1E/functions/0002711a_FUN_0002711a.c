/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a694: Table 2D - 332 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_learned_table_cell_index [high]: DAT_ffffb6c4 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548, tbl 0x6a694 [17 cells, RPM axis 0x755dc = 0,1125,1750,...,8750, identity u16 data 0x75620]) + 17*load_band; load bands from engine_load_ffffc0b4 vs 0.4/0.65/3.0 (float pools 0x755a4/0x755a8/0x755ac): <0.4 -> +0, <0.65 -> +0x11, <3.0 -> +0x22, else +0x33 (rx8_add_u16_saturate 0x2460, pool 0x2724c). Cell = rpm_cell(0..16) + 17*load_band(0..3). Called from 0x287aa.
 * RAM 0xffffb6c4 e2ram_learned_table_cell_index (uint16): Current learned-table cell = rpm_cell(0..16) + 17*load_band(0..3), computed by 0x2711a from engine_speed_rpm_ffffb548 (tbl 0x6a694) and engine_load_ffffc0b4 (bands 0.4/0.65/3.0). Consumed by 0x271b0/0x276ec/0x28198.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002711a; body bytes: 94; decompiled */

void e2ram_learned_table_cell_index(void)

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


