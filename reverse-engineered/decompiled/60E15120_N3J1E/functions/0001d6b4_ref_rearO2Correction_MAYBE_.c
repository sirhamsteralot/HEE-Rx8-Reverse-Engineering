/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069bc0: Table 2D - 312 Engine Speed (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001d6b4; body bytes: 190; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001e114 (190 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_rearO2Correction_MAYBE_(void)

{
  short sVar2;
  undefined4 *puVar1;
  float fVar3;
  
  fVar3 = DAT_ffffae0c - DAT_ffffae00;
  sVar2 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_2d_312_engine_speed_00069bc0);
  puVar1 = (undefined4 *)(uint)closed_loop_active_ffffae1f;
  if (puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
    puVar1 = (undefined4 *)rx8_add_u16_saturate((int)(short)DAT_ffffb0c0,1);
    DAT_ffffb0c0 = (ushort)puVar1;
  }
  else {
    DAT_ffffb0c0 = 0;
  }
  if ((((((DAT_ffffb0c0 < 0x4e) || (5000.0 <= engine_speed_rpm_ffffb548)) ||
        (puVar1 = &DAT_00070be0, fVar3 < -0.015)) || ((0.015 <= fVar3 || (1.0 < engine_load_ffffc0b4)))) ||
      ((inferred_coolant_temperature_ffffa98c < 70.0 ||
       ((puVar1 = (undefined4 *)(uint)DAT_ffffad24,
        puVar1 != (undefined4 *)((int)&vector_Poweron_Reset + 1) ||
        (puVar1 = (undefined4 *)(int)sVar2, (undefined4 *)(int)engine_running_timer_ffffa424 < puVar1)))))) ||
     (puVar1 = (undefined4 *)(int)DAT_ffffcd5d, puVar1 != (undefined4 *)0x0)) {
    DAT_ffffb07d = 0;
  }
  else {
    DAT_ffffb07d = 1;
  }
  return puVar1;
}


