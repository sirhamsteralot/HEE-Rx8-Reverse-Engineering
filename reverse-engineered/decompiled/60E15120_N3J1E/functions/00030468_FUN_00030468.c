/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a518: Table 2D - 331 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00030468; body bytes: 460; decompiled */

uint FUN_00030468(void)

{
  byte snapshot_engine_injectors_off_ffffa42c;
  char cVar2;
  ushort uVar3;
  uint extraout_r0;
  uint uVar4;
  byte bVar5;
  float fVar6;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar2 = DAT_ffffce32;
  snapshot_engine_injectors_off_ffffa42c = engine_injectors_off_ffffa42c;
  uVar4 = (uint)(char)DAT_ffffbe9a;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if (6 < DAT_ffffbea5) {
    uVar4 = rx8_add_u8_saturate(uVar4,1);
    DAT_ffffbea5 = 0;
    DAT_ffffbeaa = 0;
  }
  bVar5 = (byte)uVar4;
  if (((-20.0 <= snapshot_inferred_coolant_temperature_ffffa98c) || (5 < (uVar4 & 0xff))) || (DAT_ffffa7ac <= engine_speed_rpm_ffffb548)) {
    bVar5 = 0;
    DAT_ffffbea5 = 0;
    DAT_ffffbeaa = 0;
  }
  if ((DAT_ffffbea9 == '\0') && (snapshot_engine_injectors_off_ffffa42c == 1)) {
    DAT_ffffbea5 = 0;
    DAT_ffffbeaa = 1;
  }
  uVar4 = (uint)DAT_ffffbeaa;
  if (uVar4 == 1) {
    uVar4 = rx8_add_u8_saturate((int)(char)DAT_ffffbea5,1);
    DAT_ffffbea5 = (byte)uVar4;
  }
  fVar6 = 1.0;
  DAT_ffffbe9a = bVar5;
  if (engine_running_ffffa428 == '\0') {
    if ((DAT_ffffbea9 == '\0') && (snapshot_engine_injectors_off_ffffa42c == 1)) {
      if (cVar2 == '\x01') {
        uVar3 = rx8_lookup_2d_raw_u16(snapshot_inferred_coolant_temperature_ffffa98c,&PTR_PTR_0006a518);
        DAT_ffffbea0 = uVar3 >> 4;
        DAT_ffffbe98 = rx8_add_u16_saturate(DAT_ffffbea0,0x27);
        DAT_ffffbe90 = 0.5;
      }
      else {
        if (bVar5 < 200) {
          uVar3 = rx8_lookup_2d_raw_u8(snapshot_inferred_coolant_temperature_ffffa98c,&PTR_CAL_table_845_0006ab28);
          DAT_ffffbe98 = uVar3 & 0xff;
        }
        else {
          DAT_ffffbe98 = 8;
        }
        if (DAT_ffffbe9a < 200) {
          DAT_ffffbe90 = 0.0;
        }
        else {
          DAT_ffffbe90 = 0.34375;
        }
      }
    }
    if (((cVar2 == '\x01') && (1e+07 <= cranking_pulse_adder_ffffbe94)) ||
       ((snapshot_engine_injectors_off_ffffa42c == 1 && (DAT_ffffbe98 <= DAT_ffffbea2)))) {
      DAT_ffffbe9b = '\x01';
    }
    else {
      DAT_ffffbe9b = '\0';
    }
    uVar4 = (uint)snapshot_engine_injectors_off_ffffa42c;
    if (uVar4 == 1) {
      uVar4 = rx8_add_u16_saturate((int)(short)DAT_ffffbea2,1);
      DAT_ffffbea2 = (ushort)uVar4;
    }
    else {
      DAT_ffffbea2 = 0;
    }
    if (DAT_ffffbe9b != '\0') {
      fVar6 = rx8_max_float(DAT_ffffbe84 + -0.046899997,DAT_ffffbe90);
      uVar4 = extraout_r0;
    }
  }
  else {
    DAT_ffffbe84 = 1.0;
    DAT_ffffbe9b = '\0';
    DAT_ffffbea2 = 0;
    fVar6 = DAT_ffffbe84;
  }
  DAT_ffffbe84 = fVar6;
  DAT_ffffbea9 = snapshot_engine_injectors_off_ffffa42c;
  return uVar4;
}


