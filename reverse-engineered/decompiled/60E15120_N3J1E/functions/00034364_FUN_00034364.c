/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b228: Table 2D - 225 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b23c: Table 2D - 226 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00034364; body bytes: 546; decompiled */

undefined4 * FUN_00034364(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *extraout_r0;
  float extraout_fr0;
  float fVar3;
  float fVar4;
  undefined4 snapshot_engine_speed_rpm_ffffb548;
  float fVar6;
  float arg0;
  
  cVar1 = engine_running_ffffa428;
  DAT_ffffc154 = engine_load_ffffc0b4 - DAT_ffffc188;
  fVar4 = engine_load_raw_ffffc0b0;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  arg0 = engine_load_ffffc0b4;
  engine_load_delta_ffffc150 = rx8_absolute_difference(engine_load_ffffc0b4,DAT_ffffc188);
  DAT_ffffc16c = arg0 - DAT_ffffc18c;
  DAT_ffffc190 = (float)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_225_0006b228);
  puVar2 = (undefined4 *)lookup_2d_descriptor_scaled(snapshot_engine_speed_rpm_ffffb548,&tbl_table_2d_226_0006b23c);
  fVar6 = 0.0;
  if ((cVar1 == '\0') ||
     ((puVar2 = &DAT_ffffc190, DAT_ffffc190 <= DAT_ffffc16c && (DAT_ffffc16c < extraout_fr0)))) {
    load_delta_input_ffffc158 = 0.0;
  }
  else {
    load_delta_input_ffffc158 = DAT_ffffc16c;
  }
  DAT_ffffc170 = arg0;
  if (10.0 <= engine_load_delta_ffffc150) {
    DAT_ffffc170 = fVar4;
  }
  fVar3 = fVar4;
  DAT_ffffc194 = extraout_fr0;
  if (((cVar1 != '\0') &&
      (puVar2 = (undefined4 *)&DAT_0007a07a, fVar4 = arg0, fVar3 = arg0, DAT_ffffc168 < 0xfe)) &&
     (puVar2 = (undefined4 *)&DAT_0007a07c, engine_on_time_counter_ffffa426 != 0)) {
    if (((0.0 < DAT_ffffc15c) && (DAT_ffffc154 < -10.0)) ||
       ((DAT_ffffc15c <= 0.0 && (10.0 <= DAT_ffffc154)))) {
      DAT_ffffc174 = DAT_ffffc188;
      DAT_ffffc180 = DAT_ffffc188;
      fVar4 = DAT_ffffc174;
      fVar3 = DAT_ffffc180;
    }
    else {
      fVar4 = 1e-05;
      DAT_ffffc174 = rx8_first_order_filter(arg0,DAT_ffffc174,DAT_ffffc178,1e-05);
      fVar3 = rx8_first_order_filter(arg0,DAT_ffffc180,DAT_ffffc184,fVar4);
      puVar2 = extraout_r0;
      fVar4 = DAT_ffffc174;
    }
  }
  DAT_ffffc180 = fVar3;
  DAT_ffffc174 = fVar4;
  DAT_ffffc160 = DAT_ffffc170 - DAT_ffffc174;
  DAT_ffffc17c = DAT_ffffc170 - DAT_ffffc180;
  DAT_ffffc15c = fVar6;
  if ((cVar1 != '\0') && ((DAT_ffffc160 < -0.032227 || (0.032227 <= DAT_ffffc160)))) {
    DAT_ffffc15c = DAT_ffffc160;
  }
  DAT_ffffc164 = fVar6;
  if ((cVar1 != '\0') && ((DAT_ffffc17c < -0.032227 || (0.032227 <= DAT_ffffc17c)))) {
    DAT_ffffc164 = DAT_ffffc17c;
  }
  if (engine_load_delta_ffffc150 < 0.077148) {
    if (DAT_ffffc17c < 0.0) {
      DAT_ffffc184 = 0.02;
    }
    else {
      DAT_ffffc184 = 0.008;
    }
  }
  else if (DAT_ffffc17c < 0.0) {
    DAT_ffffc184 = 0.02;
  }
  else {
    DAT_ffffc184 = 0.008;
  }
  DAT_ffffc178 = 0.02;
  DAT_ffffc18c = DAT_ffffc188;
  DAT_ffffc188 = arg0;
  return puVar2;
}


