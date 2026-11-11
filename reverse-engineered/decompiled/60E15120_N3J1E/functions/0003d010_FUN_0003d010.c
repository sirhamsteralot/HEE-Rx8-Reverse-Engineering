/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b61c: Table 2D - 256 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * o2_monitor_integrator [high]: c5ec integrator loaded from tbl 0x6b61c vs catalyst-temp model, decays by MAF*0.1; out-of-tolerance check in 0x3cd06 sets c5fc/c5fd; 0x3ccec calls it then sets c5f0=-40.0, c5f4=200.0. | promoted to high (binary-level re-verification (this pass))
 * RAM 0xffffa42c engine_injectors_off (uint8): Injectors-off flag checked by the 0x3d010 O2 monitor integrator.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003d010; body bytes: 286; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003d06a) */

uint o2_monitor_integrator(void)

{
  char cVar1;
  uint uVar2;
  uint extraout_r0;
  float extraout_fr0;
  float fVar3;
  undefined4 snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  
  cVar1 = engine_injectors_off_ffffa42c;
  if ((engine_running_ffffa428 == '\0') || ((engine_injectors_off_ffffa42c == '\x01' && (DAT_ffffc608 == '\0')))) {
    snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
    DAT_ffffc5f8 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&PTR_CAL_table_845_0006b610);
    DAT_ffffc5fa = (short)(int)((float)((uint)DAT_ffffc5f8 * 0x80) * 0.00390625);
    DAT_ffffc606 = DAT_ffffc5f8;
    uVar2 = lookup_2d_descriptor_scaled(snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_2d_256_0006b61c);
    DAT_ffffc5ec = extraout_fr0;
  }
  else {
    uVar2 = (uint)DAT_ffffc600;
    if ((uVar2 == 1) || (95.88 < vehicle_speed_ffffbbb4)) {
      if ((DAT_ffffc5fa != 0) && (DAT_ffffc5fa = DAT_ffffc5fa + -1, DAT_ffffc5f8 != 0)) {
        DAT_ffffc5f8 = DAT_ffffc5f8 - 1;
      }
    }
    else if (DAT_ffffc5f8 != 0) {
      DAT_ffffc5f8 = DAT_ffffc5f8 - 1;
    }
    if (((DAT_ffffc58e == '\0') && (uVar2 = (uint)DAT_ffffc590, uVar2 == 0)) &&
       (DAT_ffffb0cb == '\0')) {
      fVar3 = mass_air_flow_ffffa9ec * 0.099999994;
      if (open_loop_request_ffffb12a == '\x01') {
        fVar3 = fVar3 * 1.0;
      }
      DAT_ffffc5ec = rx8_max_float(DAT_ffffc5ec - fVar3,0.0);
      uVar2 = extraout_r0;
    }
  }
  DAT_ffffc608 = cVar1;
  return uVar2;
}


