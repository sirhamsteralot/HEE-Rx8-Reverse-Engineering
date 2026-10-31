/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00020298; body bytes: 390; decompiled */

uint FUN_00020298(void)

{
  char cVar1;
  char cVar2;
  char cVar4;
  uint uVar3;
  float fVar5;
  float snapshot_closed_loop_trim_filtered_ffffbeb8;
  
  cVar2 = fuel_cut_flag_b_ffffa445;
  cVar1 = fuel_cut_flag_a_ffffa444;
  fVar5 = DAT_ffffb2ec;
  snapshot_closed_loop_trim_filtered_ffffbeb8 = closed_loop_trim_filtered_ffffbeb8;
  cVar4 = rx8_is_outside_tolerance_band(DAT_ffffb2ec,0,0x3727c5ac);
  if (DAT_ffffaa62 == '\0') {
    DAT_ffffb238 = 0;
  }
  else if (((DAT_ffffb242 == '\x01') && (cVar1 == '\0')) ||
          ((DAT_ffffb243 == '\x01' && (cVar2 == '\0')))) {
    DAT_ffffb238 = 1;
  }
  if (((((((closed_loop_active_ffffae1f != '\x01') || (DAT_ffffb2f6 != '\x01')) || (cVar4 == '\0')) ||
        ((DAT_ffffd25d != '\0' || (DAT_ffffd0f2 != '\0')))) ||
       ((-0.015 <= snapshot_closed_loop_trim_filtered_ffffbeb8 && (snapshot_closed_loop_trim_filtered_ffffbeb8 < 0.015)))) || ((DAT_ffffb238 == 1 && (DAT_ffffb23c < 0x26)))) ||
     ((fVar5 < 0.25 &&
      (fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(intake_air_temperature_ffff9f60,&DAT_ffff80bc),
      fVar5 < 50.0)))) {
    DAT_ffffb228 = 0;
  }
  else {
    if (snapshot_closed_loop_trim_filtered_ffffbeb8 < 0.015) {
      DAT_ffffb230 = 0x38a7c5ac;
      DAT_ffffb228 = 2;
      fVar5 = DAT_ffffb220 + 8e-05;
    }
    else {
      fVar5 = DAT_ffffb220 - 8e-05;
      DAT_ffffb228 = 1;
    }
    DAT_ffffb220 = rx8_clamp_float(fVar5,-0.05,0.15);
  }
  uVar3 = (uint)DAT_ffffb238;
  if (uVar3 == 1) {
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffb23c,1);
    DAT_ffffb23c = (ushort)uVar3;
  }
  else {
    DAT_ffffb23c = 0;
  }
  DAT_ffffb242 = cVar1;
  DAT_ffffb243 = cVar2;
  return uVar3;
}


