/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003eefc; body bytes: 446; decompiled */

undefined1 * FUN_0003eefc(void)

{
  float snapshot_engine_speed_rpm_ffffb548;
  ushort snapshot_DAT_ffffc6c8;
  ushort snapshot_DAT_ffffc6ca;
  ushort snapshot_DAT_ffffc6cc;
  undefined1 *puVar5;
  char cVar6;
  float fVar7;
  float snapshot_intake_air_temperature_ffffaddc;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_vehicle_speed_ffffbbb4;
  float snapshot_DAT_ffffb334;
  
  snapshot_DAT_ffffc6cc = DAT_ffffc6cc;
  snapshot_DAT_ffffc6ca = DAT_ffffc6ca;
  snapshot_DAT_ffffc6c8 = DAT_ffffc6c8;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  fVar7 = DAT_ffffc6c4 - DAT_ffffc6c0;
  if (DAT_ffffd1c5 == '\x01') {
    puVar5 = &DAT_ffffc6ba;
    DAT_ffffc6ba = 0;
    DAT_ffffc6bb = 0;
    DAT_ffffc6b8 = 0;
    DAT_ffffc6b9 = 0;
    DAT_ffffc6bc = 0;
    DAT_ffffc6bd = 0;
    DAT_ffffc6d2 = 0;
  }
  else {
    snapshot_intake_air_temperature_ffffaddc = intake_air_temperature_ffffaddc;
    snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
    snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
    snapshot_DAT_ffffb334 = DAT_ffffb334;
    if ((0x4e2 < DAT_ffffc6c8) || (DAT_ffffb334 <= 15000.0)) {
      cVar6 = ref_getFaultStatus__(0x73);
      if ((((cVar6 == '\0') && (((fVar7 <= 0.2 && (0x4e2 < snapshot_DAT_ffffc6c8)) && (1500.0 < snapshot_engine_speed_rpm_ffffb548)))) &&
          (((0.0 < snapshot_vehicle_speed_ffffbbb4 && (70.0 < snapshot_inferred_coolant_temperature_ffffa98c)) && (-40.0 < snapshot_intake_air_temperature_ffffaddc)))) && (15000.0 < snapshot_DAT_ffffb334)) {
        DAT_ffffc6b9 = 1;
      }
    }
    else {
      DAT_ffffc6b8 = 1;
    }
    if ((0x4e2 < snapshot_DAT_ffffc6ca) || (snapshot_DAT_ffffb334 <= 15000.0)) {
      cVar6 = ref_getFaultStatus__(0x74);
      if ((((cVar6 == '\0') &&
           ((((fVar7 <= 0.2 && (0x4e2 < snapshot_DAT_ffffc6ca)) && (1500.0 < snapshot_engine_speed_rpm_ffffb548)) &&
            ((0.0 < snapshot_vehicle_speed_ffffbbb4 && (70.0 < snapshot_inferred_coolant_temperature_ffffa98c)))))) && (-40.0 < snapshot_intake_air_temperature_ffffaddc)) && (15000.0 < snapshot_DAT_ffffb334)) {
        DAT_ffffc6bb = 1;
      }
    }
    else {
      DAT_ffffc6ba = 1;
    }
    puVar5 = (undefined1 *)(int)(short)snapshot_DAT_ffffc6cc;
    if (snapshot_DAT_ffffc6cc == 0) {
      if (0xf < DAT_ffffc6d2) {
        DAT_ffffc6bc = 1;
      }
      puVar5 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffc6d2,1);
      DAT_ffffc6d2 = (ushort)puVar5;
    }
    else {
      if (0xf < snapshot_DAT_ffffc6cc) {
        DAT_ffffc6bd = 1;
      }
      DAT_ffffc6d2 = 0;
    }
  }
  return puVar5;
}


