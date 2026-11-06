/* [ADDITIONAL SOURCE REVIEW]
 * idle_ac_load_calc [medium]: A/C load term: b534==1 -> tbl 0x69530, else 3-D tbl 0x69544(coolant, catalyst temp model 0xffffa998); result 0xffffa8c4, filtered into 0xffffa8c8 (updates only when below a8c8+20.0). Called from 0x167c0 via pool 0x16890.
 * RAM 0xffffb534 automatic_transmission (uint8): Set to 1 by ref_getAutoTransCal__ 0x24b44 (store at 0x24b58 via pool 0x24b5e); 0x24b8c clears 0xffffb53c/b53e/b540 when b534==1; selects AT vs MT table paths across the idle batch (0x16748/0x148c4/0x16900/0x15fa0/0x3354e/0x34650).
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069530: Table 2D - 46 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069544: Table 3D - 13 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00016748; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001654c (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 candidate_idle_ac_load_calc(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar2;
  
  if (automatic_transmission_ffffb534 == '\x01') {
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


