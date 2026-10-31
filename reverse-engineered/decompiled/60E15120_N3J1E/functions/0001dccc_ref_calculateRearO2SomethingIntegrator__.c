/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069b48: Table 2D - 73 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b5c: Table 2D - 74 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b70: Table 2D - 75 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b84: Table 2D - 76 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b98: Table 2D - 77 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069bac: Table 2D - 78 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001dccc; body bytes: 228; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001e72c (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_calculateRearO2SomethingIntegrator__(float param_1,float param_2)

{
  undefined4 extraout_r0;
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 snapshot_mass_air_flow_ffffa9ec;
  
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80ec);
  if (DAT_ffffae20 == '\x01') {
    fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_73_00069b48);
    fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_74_00069b5c);
    DAT_ffffb08c = fVar1 - fVar2;
    DAT_ffffb090 = fVar1 + fVar3;
  }
  else {
    if (DAT_ffffcac8 == '\x01') {
      fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_75_00069b70);
      fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_76_00069b84);
    }
    else {
      fVar2 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_77_00069b98);
      fVar3 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_78_00069bac);
    }
    DAT_ffffb08c = fVar1 - fVar2;
    DAT_ffffb090 = fVar1 + fVar3;
  }
  DAT_ffffb074 = rx8_clamp_float(DAT_ffffb0ac,DAT_ffffb08c,DAT_ffffb090);
  if ((DAT_ffffb090 <= DAT_ffffb0ac) || (DAT_ffffb0ac <= DAT_ffffb08c)) {
    param_2 = param_2 - DAT_ffffb098;
    param_1 = DAT_ffffb088 * param_2;
  }
  DAT_ffffb0a4 = param_1;
  DAT_ffffb0a0 = param_2;
  return extraout_r0;
}


