/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a6cc: Table 2D - 334 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001481c; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001477c (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getEngineCrankingState__(void)

{
  char cVar1;
  
  if (DAT_ffffa79d != '\0') {
    DAT_ffffa79d = DAT_ffffa79d + -1;
  }
  if (engine_speed_rpm_ffffb548 < 500.0) {
    cVar1 = DAT_ffffa79e;
    if (engine_speed_rpm_ffffb548 < 300.0) {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = '\x01';
    if (DAT_ffffa79e == '\0') {
      DAT_ffffa79d = rx8_lookup_2d_raw_u8(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_334_check_datatype_0006a6cc);
    }
  }
  DAT_ffffa79e = cVar1;
  if (DAT_ffffa79d != '\0') {
    cVar1 = '\0';
  }
  DAT_ffffa79c = cVar1;
  return;
}


