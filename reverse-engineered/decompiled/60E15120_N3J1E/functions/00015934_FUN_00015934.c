/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000693c0: Idle Target E (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00015934; body bytes: 208; decompiled */

uint FUN_00015934(byte param_1)

{
  uint uVar1;
  uint extraout_r0;
  float extraout_fr0;
  
  uVar1 = (uint)param_1;
  if ((uVar1 == (DAT_ffffb534 == '\0')) || (cranking_active_ffffaa62_ffffaa62 == '\0')) {
    DAT_ffffa7b8 = 0;
    DAT_ffffa7cc = 500.0;
    DAT_ffffa7d0 = 500.0;
  }
  else {
    uVar1 = (uint)engine_running_ffffa428;
    if ((uVar1 == 1) && (DAT_ffffa82c == '\0')) {
      DAT_ffffa7b8 = 1;
      DAT_ffffa7cc = 500.0;
      uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa990,&tbl_idle_target_e_000693c0);
      DAT_ffffa7d0 = extraout_fr0;
    }
    else {
      DAT_ffffa7b8 = (bool)param_1 != (DAT_ffffb534 == '\0');
      if ((bool)DAT_ffffa7b8) {
        DAT_ffffa7cc = DAT_ffffa7d0;
      }
      else {
        DAT_ffffa7cc = 500.0;
      }
      if (DAT_ffffa81a == 0) {
        DAT_ffffa7d0 = rx8_max_float(DAT_ffffa7d0 - 1.6,500.0);
        uVar1 = extraout_r0;
      }
    }
  }
  return uVar1;
}


