/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa428 engine_running (uint8): Engine running flag; zeroes rough knock corrections in 0x13210; ingredient of the attack condition.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00013210; body bytes: 370; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013070 (216 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined ** ref_roughKnockCorrection(void)

{
  undefined **ppuVar1;
  undefined **extraout_r0;
  undefined **extraout_r0_00;
  undefined **extraout_r0_01;
  undefined **extraout_r0_02;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float snapshot_rough_knock_correction_leading_ffffa6ac;
  float fVar7;
  float arg1;
  float arg1_00;
  
  fVar7 = rough_knock_correction_trailing_ffffa6b0;
  snapshot_rough_knock_correction_leading_ffffa6ac = rough_knock_correction_leading_ffffa6ac;
  arg1 = DAT_ffffa6c0;
  arg1_00 = DAT_ffffa6bc;
  fVar3 = rx8_absolute_difference(rough_knock_correction_leading_ffffa6ac,DAT_ffffa6bc);
  fVar4 = rx8_absolute_difference(fVar7,arg1);
  fVar5 = fVar7 - arg1;
  fVar7 = arg1 - fVar7;
  if (DAT_ffffa6b9 == '\x01') {
    DAT_ffffa6cc = 5.0;
    DAT_ffffa6d0 = 5.0;
    pfVar2 = (float *)&DAT_0006ebf8;
    DAT_ffffa6d4 = 5.0;
  }
  else {
    if (DAT_ffffa6b7 != '\x01') {
      if (DAT_ffffa6b8 == '\x01') {
        DAT_ffffa6cc = 1.0;
        DAT_ffffa6d0 = 1.0;
        DAT_ffffa6d4 = 1.0;
        DAT_ffffa6d8 = 1.0;
        ppuVar1 = (undefined **)((int)&vector_Poweron_Reset + 1);
      }
      else {
        ppuVar1 = (undefined **)&DAT_0006ebfc;
        DAT_ffffa6cc = 5.0;
        DAT_ffffa6d0 = 5.0;
        DAT_ffffa6d4 = 5.0;
        DAT_ffffa6d8 = 5.0;
      }
      goto LAB_000132e8;
    }
    DAT_ffffa6cc = 1.0;
    DAT_ffffa6d0 = 1.0;
    pfVar2 = (float *)&DAT_0006ebd8;
    DAT_ffffa6d4 = 1.0;
  }
  ppuVar1 = (undefined **)((int)&vector_Poweron_Reset + 1);
  DAT_ffffa6d8 = *pfVar2;
LAB_000132e8:
  if (engine_running_ffffa428 == '\0') {
    rough_knock_correction_leading_ffffa6ac = 0.0;
    rough_knock_correction_trailing_ffffa6b0 = 0.0;
  }
  else {
    ppuVar1 = &vector_Manual_Reset;
    if (0.09999999 < fVar3) {
      if (arg1_00 - snapshot_rough_knock_correction_leading_ffffa6ac <= 0.09999999) {
        ppuVar1 = &vector_Manual_Reset;
        if (0.09999999 < snapshot_rough_knock_correction_leading_ffffa6ac - arg1_00) {
          rough_knock_correction_leading_ffffa6ac = rx8_max_float(rough_knock_correction_leading_ffffa6ac - DAT_ffffa6d0,arg1_00);
          ppuVar1 = extraout_r0_00;
        }
      }
      else {
        rough_knock_correction_leading_ffffa6ac = rx8_min_float(rough_knock_correction_leading_ffffa6ac + DAT_ffffa6cc,arg1_00);
        ppuVar1 = extraout_r0;
      }
    }
    if (0.09999999 < fVar4) {
      if (fVar7 <= 0.09999999) {
        ppuVar1 = (undefined **)&UNK_00000004;
        if (0.09999999 < fVar5) {
          rough_knock_correction_trailing_ffffa6b0 = rx8_max_float(rough_knock_correction_trailing_ffffa6b0 - DAT_ffffa6d8,arg1);
          ppuVar1 = extraout_r0_02;
        }
      }
      else {
        rough_knock_correction_trailing_ffffa6b0 = rx8_min_float(rough_knock_correction_trailing_ffffa6b0 + DAT_ffffa6d4,arg1);
        ppuVar1 = extraout_r0_01;
      }
    }
  }
  return ppuVar1;
}


