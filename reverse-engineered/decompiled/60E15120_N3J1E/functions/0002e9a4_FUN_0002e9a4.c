/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a95c: Engine On Time Threshold (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002e9a4; body bytes: 320; decompiled */

undefined1 * FUN_0002e9a4(void)

{
  byte snapshot_engine_injectors_off_ffffa42c;
  undefined1 *puVar2;
  float fVar3;
  float fVar4;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_engine_speed_rpm_ffffb548;
  
  snapshot_engine_injectors_off_ffffa42c = engine_injectors_off_ffffa42c;
  fVar4 = 7300.0;
  fVar3 = 115.5;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  DAT_ffffbd88 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_ffffa98c,&tbl_engine_on_time_threshold_0006a95c);
  if (snapshot_engine_speed_rpm_ffffb548 < 600.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 400.0) {
      DAT_ffffbd96 = 0;
    }
  }
  else {
    DAT_ffffbd96 = 1;
  }
  if (snapshot_engine_speed_rpm_ffffb548 < 7800.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < fVar4) {
      DAT_ffffbd97 = '\0';
    }
  }
  else {
    DAT_ffffbd97 = '\x01';
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < 118.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < fVar3) {
      DAT_ffffbd98 = '\0';
    }
  }
  else {
    DAT_ffffbd98 = '\x01';
  }
  puVar2 = (undefined1 *)(uint)inferred_ram_bf3c_ffffbf3c_ffffbf3c;
  if ((((((puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) &&
         (puVar2 = (undefined1 *)(int)DAT_ffffbd88, puVar2 <= (undefined1 *)(int)engine_running_timer_ffffa424)) &&
        (puVar2 = (undefined1 *)(uint)snapshot_engine_injectors_off_ffffa42c, puVar2 == (undefined1 *)0x0)) &&
       ((puVar2 = &DAT_ffffbd92, 2 < DAT_ffffbd92 &&
        (puVar2 = (undefined1 *)(uint)DAT_ffffbd96,
        puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1))))) &&
      ((puVar2 = (undefined1 *)(int)DAT_ffffbd97, puVar2 == (undefined1 *)0x0 &&
       ((puVar2 = &DAT_ffffbd98, DAT_ffffbd98 == '\0' && (DAT_ffffc5e6 == '\0')))))) &&
     ((DAT_ffffbd72 == '\0' &&
      ((DAT_ffffbd73 == '\0' &&
       (puVar2 = (undefined1 *)(uint)DAT_ffffbd76,
       puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1))))))) {
    ac_clutch_on_ffffbd69 = 1;
  }
  else {
    ac_clutch_on_ffffbd69 = 0;
  }
  if (snapshot_engine_injectors_off_ffffa42c == 0) {
    puVar2 = (undefined1 *)rx8_add_u8_saturate((int)(char)DAT_ffffbd92,1);
    DAT_ffffbd92 = (byte)puVar2;
  }
  else {
    DAT_ffffbd92 = 0;
  }
  return puVar2;
}


