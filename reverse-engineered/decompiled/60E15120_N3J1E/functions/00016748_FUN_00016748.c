/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069530: Table 2D - 46 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069544: Table 3D - 13 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016748; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001654c (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00016748(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar2;
  
  if (DAT_ffffb534 == '\x01') {
    uVar1 = lookup_2d_descriptor_scaled(&tbl_table_2d_46_00069530);
    fVar2 = extraout_fr0;
  }
  else {
    uVar1 = lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa990,inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_table_3d_13_00069544);
    fVar2 = extraout_fr0_00;
  }
  if (fVar2 < DAT_ffffa8c8 + 20.0) {
    DAT_ffffa8c4 = fVar2;
  }
  DAT_ffffa8c8 = DAT_ffffa8c4;
  return uVar1;
}


