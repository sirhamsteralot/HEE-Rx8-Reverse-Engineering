/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069830: Table 2D - 60 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069844: Table 2D - 61 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069858: Table 2D - 62 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006986c: Table 2D - 63 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00020c14; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021580 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_00020c14(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffb284;
  if (puVar1 == (undefined4 *)0x1) {
    DAT_ffffb274 = (float)lookup_2d_descriptor_scaled(DAT_ffffad50,&tbl_table_2d_60_00069830);
    DAT_ffffb278 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&tbl_table_2d_61_00069844);
    DAT_ffffb27c = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_62_00069858);
    DAT_ffffb280 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_63_0006986c);
    DAT_ffffb26c = DAT_ffffb274 * 1.0 * DAT_ffffb278 * DAT_ffffb27c * DAT_ffffb280;
    puVar1 = &DAT_00020ce8;
    if (500.0 <= DAT_ffffb26c) {
      DAT_ffffb285 = 1;
      puVar1 = (undefined4 *)ref_osTaskScheduler(0,1,&DAT_ffffb26c);
      return puVar1;
    }
  }
  DAT_ffffb285 = 0;
  return puVar1;
}


