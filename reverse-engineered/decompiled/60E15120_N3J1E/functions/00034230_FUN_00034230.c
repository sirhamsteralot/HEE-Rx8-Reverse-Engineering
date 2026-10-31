/* ROM address: 0x00034230; body bytes: 128; decompiled */

undefined4 FUN_00034230(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffc144 = DAT_ffffc124 * DAT_ffffc130 + tip_in_decay_ffffc110 * load_delta_enrichment_ffffc134 * tip_in_enrichment_ffffc140 +
                 DAT_ffffc114 * DAT_ffffc120;
  DAT_ffffc148 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_0006b0ac);
  if ((engine_on_time_counter_ffffa426 == 0) || ((DAT_ffffc108 == '\x01' && (DAT_ffffc148 <= DAT_ffffc01c)))) {
    uVar1 = 1;
    DAT_ffffc104 = 0.0;
  }
  else {
    DAT_ffffc104 = rx8_min_float(DAT_ffffc10c * DAT_ffffc144,16.0);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


