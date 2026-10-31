/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069810: Off Throttle Fuel Cut - Fuel Resume - In Neutral Threshold9 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001ae74; body bytes: 224; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001aea2) */
/* WARNING: Removing unreachable block (ram,0x0001aeaa) */
/* WARNING: Removing unreachable block (ram,0x0001aec0) */
/* WARNING: Removing unreachable block (ram,0x0001aed8) */
/* WARNING: Removing unreachable block (ram,0x0001aeca) */
/* WARNING: Removing unreachable block (ram,0x0001aeba) */
/* WARNING: Removing unreachable block (ram,0x0001aece) */

undefined4 FUN_0001ae74(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float extraout_fr0_00;
  
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)DAT_ffffad1c);
  DAT_ffffad20 = extraout_fr0;
  DAT_ffffad28 = extraout_fr0;
  if ((engine_running_ffffa428 == '\0') || (uVar1 = 1, DAT_ffffcdb8 == '\x01')) {
    DAT_ffffad24 = 0;
  }
  else {
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_off_throttle_fuel_cut_fuel_resume_in_neutral_threshold9_00069810);
    if (((0.45 <= DAT_ffffad20) && (uVar1 = 0x20, 0x1f < DAT_ffffad2c)) ||
       (extraout_fr0_00 <= DAT_ffffb334)) {
      DAT_ffffad24 = 1;
    }
  }
  if (DAT_ffffad20 < 0.45) {
    DAT_ffffad2c = 0;
  }
  else {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffad2c,1);
    DAT_ffffad2c = (ushort)uVar1;
  }
  return uVar1;
}


