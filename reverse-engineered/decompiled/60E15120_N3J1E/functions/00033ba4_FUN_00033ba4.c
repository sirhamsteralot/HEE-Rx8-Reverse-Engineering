/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00033ba4; body bytes: 108; decompiled */

undefined4 FUN_00033ba4(void)

{
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float snapshot_load_delta_input_ffffc158;
  
  snapshot_load_delta_input_ffffc158 = load_delta_input_ffffc158;
  DAT_ffffc0d4 = (float)lookup_2d_descriptor_scaled(load_delta_input_ffffc158,&DAT_0006b01c);
  DAT_ffffc0d8 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&DAT_0006afcc);
  if (snapshot_load_delta_input_ffffc158 < 0.0) {
    DAT_ffffc0d0 = DAT_ffffc0d4 * 1.0 * DAT_ffffc0d8;
  }
  else {
    DAT_ffffc0d0 = 0.0;
  }
  if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffc0dc = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,&DAT_0006b058);
    DAT_ffffc0dc = extraout_fr0;
  }
  return uVar1;
}


