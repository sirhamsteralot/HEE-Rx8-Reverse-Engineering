/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069b98: Table 2D - 77 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069bac: Table 2D - 78 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003f210; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003f7ac (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003f210(void)

{
  float fVar1;
  undefined4 snapshot_mass_air_flow_ffffa9ec;
  float fVar3;
  
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80ec);
  DAT_ffffc6e4 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_77_00069b98);
  DAT_ffffc6e8 = (float)lookup_2d_descriptor_scaled(snapshot_mass_air_flow_ffffa9ec,&tbl_table_2d_78_00069bac);
  fVar3 = DAT_ffffc6e8 + fVar1;
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar1 - DAT_ffffc6e4,&DAT_ffff8718);
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar3,&DAT_ffff8720);
  return;
}


