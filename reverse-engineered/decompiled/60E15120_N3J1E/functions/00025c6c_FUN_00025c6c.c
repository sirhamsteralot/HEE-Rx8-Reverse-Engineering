/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a538: Desired Charge Voltage (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a574: Table 2D - 152 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a588: Table 2D - 153 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a59c: Table 2D - 154 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a5b0: Table 2D - 155 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00025c6c; body bytes: 1008; decompiled */

void FUN_00025c6c(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float fVar5;
  float snapshot_vehicle_speed_ffffbbb4;
  
  cVar3 = DAT_ffffb0cd;
  cVar2 = DAT_ffffaa68;
  cVar1 = DAT_ffffaa62;
  if (inferred_coolant_temperature_ffffa98c <= 150.0) {
    if (inferred_coolant_temperature_ffffa98c <= 145.0) {
      DAT_ffffb64a = '\x01';
    }
  }
  else {
    DAT_ffffb64a = '\0';
  }
  if (intake_air_temperature_ffffaddc <= 150.0) {
    if (intake_air_temperature_ffffaddc <= 145.0) {
      DAT_ffffb64b = '\x01';
    }
  }
  else {
    DAT_ffffb64b = '\0';
  }
  if (inferred_coolant_temperature_ffffa98c < 150.0) {
    if (inferred_coolant_temperature_ffffa98c < 145.0) {
      DAT_ffffb64c = '\0';
    }
  }
  else {
    DAT_ffffb64c = '\x01';
  }
  if (DAT_ffffc6ac <= 0.0) {
    if (DAT_ffffc6ac <= 0.0) {
      DAT_ffffb61a = '\x01';
    }
  }
  else {
    DAT_ffffb61a = '\0';
  }
  if ((((DAT_ffffb64a == '\x01') || (DAT_ffffb64b == '\x01')) ||
      ((DAT_ffffb534 == '\0' && (DAT_ffffca4c == '\0')))) ||
     (((((DAT_ffffb610 == 0 || (DAT_ffffb5b2 == '\x01')) || (DAT_ffffb5b0 == '\x01')) ||
       ((DAT_ffffb5b1 == '\x01' || (DAT_ffffc5e6 == '\x01')))) || (DAT_ffffc5db == '\x01')))) {
    DAT_ffffb616 = '\x01';
  }
  else {
    DAT_ffffb616 = '\0';
  }
  if ((DAT_ffffb617 != '\x01') || (5.0 < vehicle_speed_ffffbbb4)) {
    DAT_ffffb610 = 0x124;
  }
  else if (DAT_ffffb610 != 0) {
    DAT_ffffb610 = DAT_ffffb610 + -1;
  }
  fVar5 = DAT_ffffb658;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  DAT_ffffb624 = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_desired_charge_voltage_0006a538);
  DAT_ffffb628 = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_table_2d_152_0006a574);
  DAT_ffffb62c = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_table_2d_153_0006a588);
  cVar4 = DAT_ffffb619;
  if (((((((cVar2 == '\x01') && (DAT_ffffb644 < 4)) || (DAT_ffffb616 == '\x01')) ||
        (DAT_ffffad18 == '\x01')) || ((cVar1 == '\x01' && (cVar3 == '\x01')))) ||
      ((snapshot_vehicle_speed_ffffbbb4 < 20.0 || ((DAT_ffffb5fc < 20.0 || (20.0 <= DAT_ffffb5a4)))))) ||
     (fVar5 < DAT_ffffb624 - DAT_ffffb62c)) {
    DAT_ffffb617 = '\0';
LAB_00025f56:
    if (((cVar2 == '\x01') && (3 < DAT_ffffb644)) &&
       ((cVar3 == '\x01' && ((DAT_ffffb616 == '\0' && (cVar1 == '\x01')))))) {
      DAT_ffffb618 = '\x01';
      goto LAB_00025f94;
    }
  }
  else if (cVar2 == '\x01') {
    if ((((3 < DAT_ffffb644) && (50.0 <= DAT_ffffb5fc)) && (DAT_ffffb5a4 < 50.0)) &&
       (DAT_ffffb624 - DAT_ffffb628 <= fVar5)) {
      DAT_ffffb617 = '\x01';
    }
    goto LAB_00025f56;
  }
  DAT_ffffb618 = '\0';
LAB_00025f94:
  DAT_ffffb64d = DAT_ffffb619;
  if ((DAT_ffffb617 == '\0') && (DAT_ffffb618 == '\0')) {
    DAT_ffffb619 = '\x01';
  }
  else {
    DAT_ffffb619 = '\0';
  }
  if (((cVar2 == '\x01') && (DAT_ffffb644 < 4)) || ((DAT_ffffb619 == '\x01' && (cVar4 == '\0')))) {
    DAT_ffffb5fc = 40.0;
  }
  else if (((DAT_ffffb619 == '\x01') && (20.0 <= snapshot_vehicle_speed_ffffbbb4)) || (DAT_ffffb618 == '\x01')) {
    DAT_ffffb5fc = rx8_min_float(DAT_ffffb5fc + 0.0009999999,0.0);
  }
  else if (DAT_ffffb617 == '\x01') {
    DAT_ffffb5fc = rx8_max_float(DAT_ffffb5fc - 0.0009999999,-4.0);
  }
  if (DAT_ffffb618 == '\x01') {
    DAT_ffffb630 = (float)lookup_2d_descriptor_scaled(&tbl_table_2d_154_0006a59c);
    fVar5 = rx8_min_float(DAT_ffffb59c + 0.2,DAT_ffffb624);
    DAT_ffffb61c = DAT_ffffb630 + fVar5;
  }
  else if (DAT_ffffb619 == '\x01') {
    DAT_ffffb61c = DAT_ffffb624;
    if ((DAT_ffffb61a == '\x01') && (DAT_ffffb64c == '\x01')) {
      DAT_ffffb61c = 14.2;
    }
  }
  else if (DAT_ffffb617 == '\x01') {
    DAT_ffffb634 = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_table_2d_155_0006a5b0);
    fVar5 = rx8_max_float(DAT_ffffb59c - 0.2,DAT_ffffb624);
    DAT_ffffb61c = fVar5 - DAT_ffffb634;
  }
  DAT_ffffb59c = (float)ref_alternatorPIDsomething(DAT_ffffb61c);
  if (cVar2 == '\x01') {
    DAT_ffffb644 = rx8_add_u8_saturate((int)(char)DAT_ffffb644,1);
  }
  else {
    DAT_ffffb644 = 0;
  }
  return;
}


