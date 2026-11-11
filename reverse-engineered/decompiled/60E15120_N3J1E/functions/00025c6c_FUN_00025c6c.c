/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a538: Desired Charge Voltage (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a574: Table 2D - 152 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a588: Table 2D - 153 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a59c: Table 2D - 154 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a5b0: Table 2D - 155 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * alternator_voltage_target_select [medium]: Target voltage 0xffffb61c: 14.2 (pool 0x749c8) when c6ac<=0 && b64c; tbl 0x6a5b0(battery temp b5c4) + clamp(b59c ± 0.2 hysteresis, b624) in cold mode (b617); tbl 0x6a59c + min(b59c+0.2, b624) in mode b618; then 0xffffb59c = ref_alternatorPIDsomething(0x5cba4)(b61c). Coolant/IAT 145/150 C flags b64a/b64b/b64c. Called from 0x26868 via pool 0x268d8 and from 0x25790.
 * RAM 0xffffb5b2 low_voltage_latch (uint8): Set by 0x2635c when the 0xffffb60e timer (0x138) reaches 0 under low-voltage conditions (0xffffb654 >= 8.486699 pool 0x74a1c); gates P2503 raise in 0x54590 and the warning flag in 0x26760.
 * RAM 0xffffb5a4 electrical_load_filtered (float): first_order_filter(0xffffb5e0, b5a4, 0.035335) maintained by 0x2633e; numerator of the drag ratio in 0x2ce18 (b5a4/b5a0).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00025c6c; body bytes: 1008; decompiled */

void candidate_alternator_voltage_target_select(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  float fVar5;
  float snapshot_vehicle_speed_ffffbbb4;
  
  cVar3 = DAT_ffffb0cd;
  cVar2 = DAT_ffffaa68;
  cVar1 = cranking_active_ffffaa62_ffffaa62;
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
  if (inferred_ram_c6ac_ffffc6ac_ffffc6ac <= 0.0) {
    if (inferred_ram_c6ac_ffffc6ac_ffffc6ac <= 0.0) {
      DAT_ffffb61a = '\x01';
    }
  }
  else {
    DAT_ffffb61a = '\0';
  }
  if ((((DAT_ffffb64a == '\x01') || (DAT_ffffb64b == '\x01')) ||
      ((automatic_transmission_ffffb534 == '\0' && (DAT_ffffca4c == '\0')))) ||
     (((((DAT_ffffb610 == 0 || (low_voltage_latch_ffffb5b2 == '\x01')) || (DAT_ffffb5b0 == '\x01')) ||
       ((charging_ok_latch_ffffb5b1 == '\x01' || (DAT_ffffc5e6 == '\x01')))) || (DAT_ffffc5db == '\x01')))) {
      ((automatic_transmission_ffffb534 == '\0' && (DAT_ffffca4c == '\0')))) ||
     (((((DAT_ffffb610 == 0 || (low_voltage_latch_ffffb5b2 == '\x01')) || (DAT_ffffb5b0 == '\x01')) ||
       ((charging_ok_latch_ffffb5b1 == '\x01' || (DAT_ffffc5e6 == '\x01')))) || (DAT_ffffc5db == '\x01')))) {
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
  fVar5 = system_voltage_alt_ffffb658;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  DAT_ffffb624 = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_desired_charge_voltage_0006a538);
  DAT_ffffb628 = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_table_2d_152_0006a574);
  DAT_ffffb62c = (float)lookup_2d_descriptor_scaled(inferred_estimated_battery_temperature_ffffb5c4,&tbl_table_2d_153_0006a588);
  cVar4 = DAT_ffffb619;
  if (((((((cVar2 == '\x01') && (DAT_ffffb644 < 4)) || (DAT_ffffb616 == '\x01')) ||
        (inferred_ram_ad18_ffffad18_ffffad18 == '\x01')) || ((cVar1 == '\x01' && (cVar3 == '\x01')))) ||
      ((snapshot_vehicle_speed_ffffbbb4 < 20.0 || ((DAT_ffffb5fc < 20.0 || (20.0 <= electrical_load_filtered_ffffb5a4)))))) ||
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
    if ((((3 < DAT_ffffb644) && (50.0 <= DAT_ffffb5fc)) && (electrical_load_filtered_ffffb5a4 < 50.0)) &&
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
    fVar5 = rx8_min_float(inferred_ram_b59c_ffffb59c_ffffb59c + 0.2,DAT_ffffb624);
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
    fVar5 = rx8_max_float(inferred_ram_b59c_ffffb59c_ffffb59c - 0.2,DAT_ffffb624);
    DAT_ffffb61c = fVar5 - DAT_ffffb634;
  }
  inferred_ram_b59c_ffffb59c_ffffb59c = (float)candidate_alternator_target_encode_u16(DAT_ffffb61c);
  if (cVar2 == '\x01') {
    DAT_ffffb644 = rx8_add_u8_saturate((int)(char)DAT_ffffb644,1);
  }
  else {
    DAT_ffffb644 = 0;
  }
  return;
}


