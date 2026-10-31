/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b110: Table 2D - 218 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003419c; body bytes: 34; decompiled */

uint FUN_0003419c(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = (uint)engine_injectors_off_ffffa42c;
  if (uVar1 == 1) {
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&tbl_table_2d_218_0006b110);
    DAT_ffffc10c = extraout_fr0;
  }
  return uVar1;
}


