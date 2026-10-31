/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000697f8: Table 2D - 299 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069804: Table 2D - 300 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001aa98; body bytes: 288; decompiled */

uint FUN_0001aa98(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float arg2;
  undefined4 snapshot_mass_air_flow_ffffa9ec;
  float fVar4;
  float arg3;
  
  uVar1 = (uint)DAT_ffffad0a;
  if ((uVar1 == 1) && (uVar1 = (uint)engine_running_ffffa428, uVar1 == 1)) {
    arg3 = 1e-05;
    if (DAT_ffffad0a == 0) {
      fVar4 = DAT_ffffaa88 - DAT_ffffacfc;
      snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
      fVar2 = (float)lookup_2d_descriptor_scaled(mass_air_flow_ffffa9ec,&tbl_table_2d_299_check_datatype_000697f8);
      arg2 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_300_check_datatype_00069804);
      if (0.0 <= fVar4) {
        fVar2 = DAT_ffffaa88;
        if (0.0 < fVar4) {
          fVar2 = rx8_first_order_filter(DAT_ffffaa88,diag_afr_word_a_ffffaa6c,arg2,arg3);
        }
      }
      else {
        fVar2 = rx8_first_order_filter(DAT_ffffaa88,diag_afr_word_a_ffffaa6c,fVar2,arg3);
      }
    }
    else if (DAT_ffffacfc <= DAT_ffffaa88) {
      fVar2 = DAT_ffffaa88;
      if (DAT_ffffad04 != 0) {
        fVar2 = (float)rx8_decode_u16_affine(0x37800000,0);
        fVar2 = rx8_first_order_filter(DAT_ffffaa88,diag_afr_word_a_ffffaa6c,fVar2,arg3);
      }
    }
    else {
      fVar2 = DAT_ffffaa88;
      if (DAT_ffffad06 != 0) {
        fVar2 = (float)rx8_decode_u16_affine(0x37800000,0);
        fVar2 = rx8_first_order_filter(DAT_ffffaa88,diag_afr_word_a_ffffaa6c,fVar2,arg3);
      }
    }
    diag_afr_word_a_ffffaa6c = fVar2;
    DAT_ffffaa70 = rx8_first_order_filter(diag_afr_word_a_ffffaa6c,DAT_ffffaa70,1.0,arg3);
    DAT_ffffaa74 = diag_afr_word_a_ffffaa6c;
    uVar1 = extraout_r0;
  }
  DAT_ffffacfc = diag_afr_word_a_ffffaa6c;
  return uVar1;
}


