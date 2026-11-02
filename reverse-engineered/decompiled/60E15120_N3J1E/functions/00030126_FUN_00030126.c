/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ab34: Table 2D - 175 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030126; body bytes: 192; decompiled */

undefined1 * FUN_00030126(void)

{
  byte snapshot_engine_injectors_off_ffffa42c;
  undefined1 *puVar2;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  snapshot_engine_injectors_off_ffffa42c = engine_injectors_off_ffffa42c;
  puVar2 = &DAT_ffffbe64;
  if (DAT_ffffbe64 == '\0') {
    snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
    if (DAT_ffffbea8 == '\0') {
      if ((DAT_ffffbea7 == '\0') &&
         (puVar2 = (undefined1 *)(uint)engine_injectors_off_ffffa42c, puVar2 == (undefined1 *)0x1)) {
        DAT_ffffbea4 = 0;
        DAT_ffffbea8 = '\x01';
      }
    }
    else {
      puVar2 = (undefined1 *)rx8_add_u8_saturate((int)(char)DAT_ffffbea4,1);
      DAT_ffffbea4 = (byte)puVar2;
    }
    if ((((0xb < DAT_ffffbea4) && (-5.0 <= snapshot_inferred_coolant_temperature_ffffa98c)) &&
        (puVar2 = (undefined1 *)(int)engine_running_ffffa428, puVar2 == (undefined1 *)0x0)) &&
       ((inferred_throttle_position_ffffad44 < 20.0 && (puVar2 = &DAT_ffffce33, DAT_ffffce33 == '\0')))) {
      DAT_ffffbe64 = '\x01';
      DAT_ffffbea4 = 0;
      DAT_ffffbea8 = '\0';
      DAT_ffffbe60 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_ffffa98c,&tbl_table_2d_175_0006ab34);
      puVar2 = (undefined1 *)os_schedule_task_event(0,1,&DAT_ffffbe60);
    }
  }
  DAT_ffffbea7 = snapshot_engine_injectors_off_ffffa42c;
  return puVar2;
}


