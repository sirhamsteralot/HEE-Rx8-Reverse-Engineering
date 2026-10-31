/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069e5c: Table 2D - 326 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001fd48; body bytes: 390; decompiled */

uint FUN_0001fd48(void)

{
  char cVar1;
  byte snapshot_DAT_ffffbecc;
  uint uVar3;
  
  snapshot_DAT_ffffbecc = DAT_ffffbecc;
  cVar1 = DAT_ffffb158;
  if (engine_load_ffffc0b4 < 0.0) {
    if (engine_load_ffffc0b4 < -0.04) {
      DAT_ffffb1d1 = '\0';
    }
  }
  else {
    DAT_ffffb1d1 = '\x01';
  }
  if (engine_load_ffffc0b4 <= 0.875) {
    if (engine_load_ffffc0b4 <= 0.835) {
      DAT_ffffb1d2 = '\0';
    }
  }
  else {
    DAT_ffffb1d2 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 < 3500.0) {
    if (engine_speed_rpm_ffffb548 < 3300.0) {
      DAT_ffffb1d3 = '\0';
    }
  }
  else {
    DAT_ffffb1d3 = '\x01';
  }
  if (engine_speed_rpm_ffffb548 <= 6000.0) {
    if (engine_speed_rpm_ffffb548 <= 5800.0) {
      DAT_ffffb1d4 = '\0';
    }
  }
  else {
    DAT_ffffb1d4 = '\x01';
  }
  if ((((DAT_ffffb1d1 == '\x01') && (DAT_ffffb1d2 == '\0')) && (DAT_ffffb1d3 == '\x01')) &&
     ((DAT_ffffb1d4 == '\0' && ((DAT_ffffbc3d == '\x05' || (DAT_ffffbc3d == '\x06')))))) {
    DAT_ffffb158 = '\x01';
  }
  else {
    DAT_ffffb158 = '\0';
  }
  if ((cVar1 == '\x01') && (DAT_ffffb158 == '\0')) {
    DAT_ffffb1ac = 0;
  }
  else if (DAT_ffffb1ac != 0) {
    DAT_ffffb1ac = DAT_ffffb1ac + -1;
  }
  if ((DAT_ffffb158 == '\x01') || (DAT_ffffb1ac != 0)) {
    ol_decay_enable_c_ffffb157 = 1;
  }
  else {
    ol_decay_enable_c_ffffb157 = 0;
  }
  uVar3 = (uint)ol_decay_enable_c_ffffb157;
  if (((uVar3 == 1) && (DAT_ffffb1da == '\0')) && (uVar3 = (uint)DAT_ffffbecc, uVar3 == 1)) {
    uVar3 = rx8_lookup_2d_raw_u16(&PTR_PTR_00069e5c);
    ol_target_select_ffffb150 = (short)uVar3;
  }
  else if (ol_target_select_ffffb150 != 0) {
    ol_target_select_ffffb150 = ol_target_select_ffffb150 + -1;
  }
  DAT_ffffb1da = snapshot_DAT_ffffbecc;
  return uVar3;
}


