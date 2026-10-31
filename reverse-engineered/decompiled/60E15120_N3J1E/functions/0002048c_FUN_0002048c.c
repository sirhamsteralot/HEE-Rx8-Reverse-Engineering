/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069f60: Table 2D - 329 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002048c; body bytes: 294; decompiled */

void FUN_0002048c(void)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float snapshot_DAT_ffffbdfc;
  
  fVar5 = 100.0;
  DAT_ffffb1dc = (DAT_ffffb2ec * mass_air_flow_ffffa9ec) / 100.0;
  fVar4 = mass_air_flow_ffffa9ec;
  snapshot_DAT_ffffbdfc = DAT_ffffbdfc;
  DAT_ffffb23a = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&tbl_table_2d_329_check_datatype_00069f60);
  if ((&DAT_ffffb1dc)[DAT_ffffb23a] < DAT_ffffb224) {
    DAT_ffffb234 = 0.78;
  }
  else {
    DAT_ffffb234 = 0.4;
  }
  DAT_ffffb224 = rx8_first_order_filter
                           ((&DAT_ffffb1dc)[DAT_ffffb23a],DAT_ffffb224,DAT_ffffb234,1e-05);
  fVar4 = (float)rx8_divide_with_zero_fallback(DAT_ffffb224,fVar4);
  DAT_ffffb22c = fVar4 * fVar5;
  if (snapshot_DAT_ffffbdfc < 2.6) {
    DAT_ffffb23e = 0;
  }
  else {
    DAT_ffffb23e = rx8_add_u16_saturate((int)DAT_ffffb23e,1);
  }
  if (-2.6 <= snapshot_DAT_ffffbdfc) {
    DAT_ffffb240 = 0;
  }
  else {
    DAT_ffffb240 = rx8_add_u16_saturate((int)DAT_ffffb240,1);
  }
  cVar2 = '\x0f';
  uVar1 = 0xe;
  puVar3 = &DAT_ffffb21c;
  do {
    cVar2 = cVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = (&DAT_ffffb1dc)[uVar1 & 0xff];
    uVar1 = uVar1 + 0xff;
  } while (cVar2 != '\0');
  return;
}


