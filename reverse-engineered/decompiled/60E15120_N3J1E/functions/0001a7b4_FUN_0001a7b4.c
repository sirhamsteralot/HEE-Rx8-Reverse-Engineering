/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000697e0: Lamda Sensor Barometric Pressure Compensation (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000697ec: Lambda Sensor Scaling (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001a7b4; body bytes: 606; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001a832) */
/* WARNING: Removing unreachable block (ram,0x0001a84c) */
/* WARNING: Removing unreachable block (ram,0x0001a848) */
/* WARNING: Removing unreachable block (ram,0x0001a84e) */
/* WARNING: Removing unreachable block (ram,0x0001a860) */

char FUN_0001a7b4(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined4 *puVar6;
  float fVar7;
  float fVar8;
  undefined4 snapshot_DAT_ffffaa8c;
  undefined4 snapshot_DAT_ffffaa90;
  
  if (DAT_ffffad0a != '\x01') {
    DAT_ffffad00 = (float)diag_afr_word_a_ffffaa6c;
    return DAT_ffffad0a;
  }
  if (engine_running_ffffa428 != '\x01') {
    DAT_ffffad00 = (float)diag_afr_word_a_ffffaa6c;
    return engine_running_ffffa428;
  }
  snapshot_DAT_ffffaa8c = DAT_ffffaa8c;
  snapshot_DAT_ffffaa90 = DAT_ffffaa90;
  fVar7 = (float)lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&tbl_lamda_sensor_barometric_pressure_compensation_000697e0);
  fVar8 = (float)lookup_2d_descriptor_scaled(diag_afr_word_b_ffffaa7c,&tbl_lambda_sensor_scaling_000697ec);
  DAT_ffffaa84 = (fVar8 + -1.0) * fVar7 + 1.0;
  if (DAT_ffffad08 == 0) {
    DAT_ffffaa94 = 0;
  }
  else if (DAT_ffffad08 < 0x7d) {
    DAT_ffffaa94 = DAT_ffffad08;
  }
  else {
    DAT_ffffaa94 = 0x7d;
  }
  if (DAT_ffffad09 == 0) {
    DAT_ffffaa95 = 0;
  }
  else if (DAT_ffffad09 < 0x7d) {
    DAT_ffffaa95 = DAT_ffffad09;
  }
  else {
    DAT_ffffaa95 = 0x7d;
  }
  cVar2 = -0x6a;
  uVar5 = 0x95;
  puVar6 = &DAT_ffffacf4;
  do {
    cVar2 = cVar2 + -1;
    puVar6 = puVar6 + -1;
    *puVar6 = (&DAT_ffffaa98)[uVar5 & 0xff];
    uVar5 = uVar5 + 0xff;
  } while (cVar2 != '\0');
  DAT_ffffaa98 = DAT_ffffaa84;
  DAT_ffffaa8c = (&DAT_ffffaa98)[DAT_ffffaa94];
  DAT_ffffaa90 = (&DAT_ffffaa98)[DAT_ffffaa95];
  if (DAT_ffffaa94 < DAT_ffffaa95) {
    cVar2 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffaa90,DAT_ffffad00,0x3727c5ac);
    if (DAT_ffffaa8c < DAT_ffffaa90) {
      if (cVar2 == '\0') {
        DAT_ffffaa96 = '\0';
      }
    }
    else {
      DAT_ffffaa96 = '\x01';
    }
  }
  else {
    cVar2 = rx8_is_outside_tolerance_band(snapshot_DAT_ffffaa8c,DAT_ffffad00,0x3727c5ac);
    if (DAT_ffffaa8c < DAT_ffffaa90) {
      if (cVar2 == '\0') {
        DAT_ffffaa96 = '\x01';
      }
    }
    else {
      DAT_ffffaa96 = '\0';
    }
  }
  if (DAT_ffffaa94 == DAT_ffffaa95) {
    DAT_ffffaa97 = 0;
    bVar1 = false;
    goto LAB_0001aa32;
  }
  bVar3 = rx8_add_u8_saturate((int)(char)DAT_ffffaa94,1);
  if (0x95 < bVar3) {
    bVar3 = 0x96;
  }
  bVar4 = rx8_add_u8_saturate((int)(char)DAT_ffffaa95,1);
  if (0x95 < bVar4) {
    bVar4 = 0x96;
  }
  if (DAT_ffffaa96 == '\x01') {
    if (DAT_ffffaa8c < (&DAT_ffffaa98)[bVar3]) {
LAB_0001aa14:
      DAT_ffffaa97 = 1;
      bVar1 = true;
      goto LAB_0001aa32;
    }
    if (DAT_ffffad00 < DAT_ffffaa8c) {
      DAT_ffffaa97 = 0;
      bVar1 = false;
      goto LAB_0001aa32;
    }
  }
  else {
    if ((&DAT_ffffaa98)[bVar4] <= DAT_ffffaa90) goto LAB_0001aa14;
    if (DAT_ffffaa90 <= DAT_ffffad00) {
      DAT_ffffaa97 = 0;
      bVar1 = false;
      goto LAB_0001aa32;
    }
  }
  DAT_ffffaa97 = 1;
  bVar1 = true;
LAB_0001aa32:
  if (bVar1) {
    DAT_ffffaa88 = DAT_ffffad00;
    cVar2 = '\x01';
  }
  else {
    cVar2 = DAT_ffffaa96;
    DAT_ffffaa88 = DAT_ffffaa90;
    if (DAT_ffffaa96 == '\x01') {
      DAT_ffffaa88 = DAT_ffffaa8c;
    }
  }
  DAT_ffffad00 = (float)diag_afr_word_a_ffffaa6c;
  return cVar2;
}


