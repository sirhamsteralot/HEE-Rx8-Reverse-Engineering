/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00033cd0; body bytes: 108; decompiled */

undefined4 FUN_00033cd0(void)

{
  undefined4 uVar1;
  undefined4 extraout_fr0;
  float snapshot_DAT_ffffc164;
  
  snapshot_DAT_ffffc164 = DAT_ffffc164;
  DAT_ffffc0f4 = (float)lookup_2d_descriptor_scaled(DAT_ffffc164,&DAT_0006b044);
  DAT_ffffc0f8 = (float)lookup_2d_descriptor_scaled(engine_load_ffffc0b4,&DAT_0006aff4);
  if (snapshot_DAT_ffffc164 < 0.0) {
    DAT_ffffc0f0 = DAT_ffffc0f4 * 0.0 * DAT_ffffc0f8;
  }
  else {
    DAT_ffffc0f0 = 0.0;
  }
  if (engine_injectors_off_ffffa42c == '\x01') {
    DAT_ffffc0fc = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_coolant_temperature_ffffa98c,&DAT_0006b090);
    DAT_ffffc0fc = extraout_fr0;
  }
  return uVar1;
}


