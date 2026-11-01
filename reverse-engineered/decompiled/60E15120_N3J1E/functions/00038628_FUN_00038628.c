/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b368: Table 2D - 232 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b37c: Table 2D - 233 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b390: Table 2D - 234 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b3a4: Table 2D - 364 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00038628; body bytes: 294; decompiled */

undefined2 * FUN_00038628(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined *puVar3;
  float snapshot_DAT_ffffc4e4;
  float snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  
  if (DAT_ffffc504 == '\x01') {
    puVar3 = &tbl_table_2d_233_0006b37c;
  }
  else {
    puVar3 = &tbl_table_2d_232_0006b368;
  }
  snapshot_DAT_ffffc4e4 = DAT_ffffc4e4;
  snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  DAT_ffffc50c = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_catalyst_temp_model_ffffa998,puVar3);
  DAT_ffffc520 = rx8_lookup_2d_raw_u16(snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_2d_364_check_datatype_0006b3a4);
  DAT_ffffc51c = (float)lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_2d_234_0006b390);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc500 = 0;
    DAT_ffffc501 = 0;
    puVar1 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  else {
    puVar1 = &DAT_ffffc4f8;
    if ((0x49 < DAT_ffffc4f8) && (76.25 < inferred_temp_c4c8_ffffc4c8_ffffc4c8)) {
      uVar2 = ref_getFaultStatus__(0x18);
      puVar1 = (undefined2 *)(uVar2 & 0xff);
      if ((puVar1 == (undefined2 *)0x0) && ((snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 < 35.625 && (DAT_ffffc5fe == '\0')))) {
        uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fbc,0);
        puVar1 = (undefined2 *)(uVar2 & 0xff);
        if ((puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) &&
           ((puVar1 = &DAT_ffffc520, engine_running_timer_ffffa424 < DAT_ffffc520 && (DAT_ffffc502 == '\0')))) {
          uVar2 = FUN_0005f9f0(0x1e,0);
          puVar1 = (undefined2 *)(uVar2 & 0xff);
          if (puVar1 == (undefined2 *)0x0) {
            uVar2 = FUN_0005f9f0(0x1f,0);
            puVar1 = (undefined2 *)(uVar2 & 0xff);
            if (((puVar1 == (undefined2 *)0x0) && (DAT_ffffc590 == '\0')) &&
               (puVar1 = (undefined2 *)(int)DAT_ffffc5e6, puVar1 == (undefined2 *)0x0)) {
              if (DAT_ffffc51c <= snapshot_DAT_ffffc4e4) {
                if (DAT_ffffc50c < snapshot_DAT_ffffc4e4) {
                  DAT_ffffc500 = 1;
                  DAT_ffffc501 = 0;
                }
              }
              else {
                DAT_ffffc501 = 1;
                DAT_ffffc500 = 0;
              }
            }
          }
        }
      }
    }
  }
  return puVar1;
}


