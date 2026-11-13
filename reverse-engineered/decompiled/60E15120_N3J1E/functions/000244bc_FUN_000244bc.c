/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_block_encode [high]: Encodes working RAM into the E2RAM staging block (base 0xffffb440, payload from 0xffffb442): rx8_encode_u16_affine_saturate of 0xffffb40c (step 0.0305176) -> 0xffffb442/444, signed 0xffffb414 -> 0xffffb446, 0xffffb594 (step 0x39a00000 = 0.00030517578125) -> 0xffffb448, ref_readValue_float of 0xffff807c/0xffff8084 -> 0xffffb44a/44c, pedal volts 0xffffa9c4 -> 0xffffb44e, engine_speed_rpm 0xffffb548 (step 0.1953125) and fault bits packed into 0xffffb459+ from 0xffffaa68/0xffffccc1/0xffffbced/0xffffccc9/ref_readValue_8bit 0xffff80a0/0xffffad60/0xffffad62. Called from 0x2377a (jsr via pool 0x237c8 at 0x23796).
 * RAM 0xffffb40c candidate_learned_pedal_value (float): Payload u16[1]/[2] source: written by FUN_000231f0 (fmov.s at 0x233b0/0x233c2/0x233d2 via pool 0x232fa=0xb40c loaded at 0x232c2) as clamp(pedal-derived candidates, ..., 111.0), special 99.0; read back by monitors FUN_0001b6fc/0x46404 and encoded by e2ram_block_encode 0x244bc. Meaning inferred from producers -> candidate_.
 * RAM 0xffffb414 throttle_pedal_position_delta (float): Payload u16[3] source (signed encode): FUN_00023558 sets DAT_ffffb414 = 0xffffb410 - 0xffffb428 (0.0 when 0xffffccc9 set; pool 0x23590 at 0x2355c); b410 = raw pedal/throttle position counts (PIDs 0x004c/0x091a).
 * RAM 0xffffb594 filtered_battery_voltage (float): Payload u16[4] source (step 0.00030517578125): ref_filterBatteryVoltage 0x2563c writes first_order_filter(0xffffb590, 0xffffb594, 0.5, 1e-5); seeded from ADC cell 0xffff9f68 by FUN_00025600.
 * RAM 0xffffb38c candidate_throttle_base_position (float): Payload u16[19] source: FUN_00022a14 sets DAT_ffffb38c = min(0xffffb2c4, ...) or 5.0; consumed as pedal base in ref_throttlePlatePosToTorqueOutput_ 0x21a80 / FUN_000233ec (0xffffb2d4 = idle_air_required 0xffffb2a4 + b38c). Meaning inferred -> candidate_.
 * RAM 0xffffcc91 candidate_idle_learn_flag (uint8): Payload byte at 0xffffb458: written by FUN_00018aea/0x470d0/0x47cce; read by candidate_idle_learn_condition 0x160ce (mov.b via pool at 0x160ce). Idle-learn-related flag, meaning inferred -> candidate_.
 * RAM 0xffffb51e e2ram_payload_reserved (uint16): Cells 0xffffb51e/0xffffb520/0xffffb522/0xffffb524 (payload u16[8..11] sources, pools 0x24690/0x24694/0x24698/0x2469c in 0x244bc): no writer references anywhere in ROM -> constant 0, reserved.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): candidate_learned_pedal_value_ffffb40c; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): -throttle_pedal_position_delta_ffffb414; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): filtered_battery_voltage_ffffb594; decode = raw * 0.0003051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): uVar3; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): candidate_throttle_base_position_ffffb38c; decode = raw * 0.03051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): uVar3; decode = raw * 0.00390625 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 * Affine encoding (16-bit): engine_speed_rpm_ffffb548; decode = raw * 0.1953125 + (0) [RPM]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000244bc; body bytes: 1408; decompiled */

void e2ram_block_encode(void)

{
  ushort uVar1;
  char cVar2;
  undefined4 uVar3;
  
  DAT_ffffb442 = rx8_encode_u16_affine_saturate(candidate_learned_pedal_value_ffffb40c,0x3cfa0000,0);
  DAT_ffffb444 = DAT_ffffb442;
  if (throttle_pedal_position_delta_ffffb414 < 0.0) {
    uVar1 = rx8_encode_u16_affine_saturate(-throttle_pedal_position_delta_ffffb414,0x3cfa0000,0);
    DAT_ffffb446 = ~uVar1 + 1;
  }
  else {
    DAT_ffffb446 = rx8_encode_u16_affine_saturate(throttle_pedal_position_delta_ffffb414,0x3cfa0000,0);
  }
  DAT_ffffb448 = rx8_encode_u16_affine_saturate(filtered_battery_voltage_ffffb594,0x39a00000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&inferred_ram_807c_ffff807c_ffff807c);
  DAT_ffffb44a = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff8084);
  DAT_ffffb44c = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  DAT_ffffb44e = inferred_pedal_volts_ffffa9c4_ffffa9c4;
  DAT_ffffb450 = e2ram_payload_reserved_ffffb51e;
  DAT_ffffb452 = DAT_ffffb520;
  DAT_ffffb454 = DAT_ffffb522;
  DAT_ffffb456 = DAT_ffffb524;
  DAT_ffffb458 = candidate_idle_learn_flag_ffffcc91;
  if (engine_running_flag_ffffaa68 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 1;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfe;
  }
  if (DAT_ffffccc1 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 2;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfd;
  }
  if (DAT_ffffbced == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 4;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xfb;
  }
  if (DAT_ffffccc9 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 8;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xf7;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a0,0);
  if (cVar2 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x10;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xef;
  }
  if (DAT_ffffad60 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x20;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xdf;
  }
  if (DAT_ffffad62 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x40;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0xbf;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8762,0);
  if (cVar2 == '\x01') {
    DAT_ffffb459 = DAT_ffffb459 | 0x80;
  }
  else {
    DAT_ffffb459 = DAT_ffffb459 & 0x7f;
  }
  if (DAT_ffffb4df == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 1;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xfe;
  }
  if (DAT_ffffb4e0 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 2;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xfd;
  }
  if (DAT_ffffb4e1 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x10;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xef;
  }
  if (DAT_ffffb4e2 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x20;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xdf;
  }
  if (DAT_ffffb4e3 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x40;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0xbf;
  }
  if (DAT_ffffb4e4 == '\x01') {
    DAT_ffffb45a = DAT_ffffb45a | 0x80;
  }
  else {
    DAT_ffffb45a = DAT_ffffb45a & 0x7f;
  }
  if (DAT_ffffb4dc == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 1;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfe;
  }
  if (DAT_ffffb4de == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 2;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfd;
  }
  if (DAT_ffffb4dd == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 4;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xfb;
  }
  if (DAT_ffffb4e5 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x10;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xef;
  }
  if (DAT_ffffb4e6 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x20;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xdf;
  }
  if (DAT_ffffb4e7 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x40;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0xbf;
  }
  if (DAT_ffffb4e8 == '\x01') {
    DAT_ffffb45b = DAT_ffffb45b | 0x80;
  }
  else {
    DAT_ffffb45b = DAT_ffffb45b & 0x7f;
  }
  if (DAT_ffffb4e9 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 1;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfe;
  }
  if (DAT_ffffb51c == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 2;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfd;
  }
  if (DAT_ffffb4ea == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 4;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xfb;
  }
  if (DAT_ffffb2cf == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 8;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xf7;
  }
  if (DAT_ffffb2d0 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x10;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xef;
  }
  if (DAT_ffffb422 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x20;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xdf;
  }
  if (DAT_ffffc030 == '\x01') {
    DAT_ffffb45c = DAT_ffffb45c | 0x40;
  }
  else {
    DAT_ffffb45c = DAT_ffffb45c & 0xbf;
  }
  if (DAT_ffffad61 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 1;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfe;
  }
  if (DAT_ffffad63 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 2;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfd;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
  if (cVar2 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 4;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xfb;
  }
  if (DAT_ffffccc7 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 8;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xf7;
  }
  if (DAT_ffffccbd == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x10;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xef;
  }
  if (DAT_ffffccbc == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x20;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xdf;
  }
  if (DAT_ffffb4eb == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x40;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0xbf;
  }
  if (DAT_ffffccc8 == '\x01') {
    DAT_ffffb45d = DAT_ffffb45d | 0x80;
  }
  else {
    DAT_ffffb45d = DAT_ffffb45d & 0x7f;
  }
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x41a00000,&DAT_ffff8094);
  DAT_ffffb45e = rx8_encode_u16_affine_saturate(uVar3,0x3cfa0000,0);
  DAT_ffffb460 = rx8_encode_u16_affine_saturate(candidate_throttle_base_position_ffffb38c,0x3cfa0000,0);
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8068);
  DAT_ffffb462 = rx8_encode_u16_affine_saturate(uVar3,0x3b800000,0);
  DAT_ffffb464 = rx8_encode_u16_affine_saturate(engine_speed_rpm_ffffb548,0x3e480000,0);
  return;
}


