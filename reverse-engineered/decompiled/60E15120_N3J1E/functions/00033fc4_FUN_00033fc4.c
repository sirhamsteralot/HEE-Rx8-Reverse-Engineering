/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b0d4: Table 2D - 217 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00033fc4; body bytes: 140; decompiled */

void FUN_00033fc4(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = DAT_ffffb0cd;
  if ((load_delta_input_ffffc158 < -0.01318) || (engine_running_ffffa428 == '\0')) {
    tip_in_decay_ffffc110 = 0x3f800000;
  }
  else {
    if ((((inferred_coolant_temperature_ffffa98c < -40.0) || (DAT_ffffc168 < 0x10)) || (DAT_ffffb0cd != '\0')) ||
       (DAT_ffffc14d != '\x01')) {
      tip_in_mode_flag_ffffc14c = 1;
      DAT_ffffc14d = cVar1;
      return;
    }
    uVar2 = rx8_decode_u16_affine(0x42800000,0);
    tip_in_decay_ffffc110 = lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_217_0006b0d4);
  }
  tip_in_mode_flag_ffffc14c = 0;
  DAT_ffffc14d = cVar1;
  return;
}


