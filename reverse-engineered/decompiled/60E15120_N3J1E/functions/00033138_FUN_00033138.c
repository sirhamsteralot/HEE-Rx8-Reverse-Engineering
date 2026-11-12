/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006aef0: Table 2D - 202 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006af04: Table 2D - 203 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00033138; body bytes: 444; decompiled */

void FUN_00033138(void)

{
  byte snapshot_can212_torque_signal_ffffbbc8;
  byte snapshot_DAT_ffffbbc9;
  char cVar3;
  char cVar4;
  float arg0;
  float fVar5;
  float fVar6;
  float fVar7;
  float arg2;
  
  cVar4 = DAT_ffffc030;
  cVar3 = DAT_ffffbbcb;
  snapshot_DAT_ffffbbc9 = DAT_ffffbbc9;
  snapshot_can212_torque_signal_ffffbbc8 = can212_torque_signal_ffffbbc8;
  fVar6 = DAT_ffffbfa0 - DAT_ffffc02c;
  fVar7 = DAT_ffffc02c - DAT_ffffbfa0;
  arg2 = 100.0;
  if (DAT_ffffc030 == '\x01') {
    if ((DAT_ffffc040 == 0) || (DAT_ffffc043 == '\0')) {
      fVar5 = throttle_position_1_percent_ffffa9b4;
      if ((DAT_ffffbbcb != '\x01') ||
         ((arg0 = DAT_ffffc034, 0xfd < can212_torque_signal_ffffbbc8 && (0xfd < DAT_ffffbbc9)))) {
        arg0 = (float)lookup_2d_descriptor_scaled(fVar6,&tbl_table_2d_202_0006aef0);
      }
      DAT_ffffc034 = rx8_clamp_float(arg0,0.0,100.0);
      if (DAT_ffffc043 == '\0') {
        fVar5 = fVar5 - 10.0;
      }
      else {
        fVar5 = DAT_ffffc038;
        if (((((fVar7 < -0.25) || (0.25 <= fVar7)) && (0.0 <= DAT_ffffc028)) &&
            (DAT_ffffc028 < 100.0)) && ((cVar3 != '\x01' || ((0xfd < snapshot_can212_torque_signal_ffffbbc8 && (0xfd < snapshot_DAT_ffffbbc9)))))) {
          DAT_ffffc03c = (float)lookup_2d_descriptor_scaled(fVar6,&tbl_table_2d_203_0006af04);
          fVar5 = DAT_ffffc038 + DAT_ffffc03c;
        }
      }
      DAT_ffffc038 = rx8_clamp_float(fVar5,0.0,100.0);
      DAT_ffffc028 = rx8_clamp_float(DAT_ffffc034 + DAT_ffffc038,25.0,arg2);
      DAT_ffffc040 = 0x10;
    }
    if (DAT_ffffc040 != 0) {
      DAT_ffffc040 = DAT_ffffc040 + -1;
    }
  }
  else {
    if (throttle_position_1_percent_ffffa9b4 <= DAT_ffffc028) {
      DAT_ffffc034 = 0.0;
      DAT_ffffc038 = 100.0;
      DAT_ffffc028 = 100.0;
    }
    else {
      DAT_ffffc034 = rx8_clamp_float(DAT_ffffc034 + 0.3,0.0,100.0);
      DAT_ffffc038 = rx8_clamp_float(DAT_ffffc038 + 0.3,0.0,100.0);
      DAT_ffffc028 = rx8_clamp_float(DAT_ffffc034 + DAT_ffffc038,25.0,arg2);
    }
    DAT_ffffc040 = 0;
  }
  DAT_ffffc043 = cVar4;
  return;
}


