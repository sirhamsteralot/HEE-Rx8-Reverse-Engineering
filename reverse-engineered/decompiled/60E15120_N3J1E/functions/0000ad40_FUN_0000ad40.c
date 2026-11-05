/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x000697ec: Lambda Sensor Scaling (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0000ad40; body bytes: 316; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000ae28) */
/* Unique exact-byte match to related 60E0FC00 function at 0000ad40 (316 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000ad40(void)

{
  float fVar1;
  float arg3;
  ushort local_20;
  
  arg3 = 0.0;
  if (3 < DAT_ffffa207) {
    local_20 = DAT_ffff9efc;
    if (DAT_ffffa1f8 + 0x41 < (uint)DAT_ffff9efc) {
      local_20 = DAT_ffffa1f8 + 0x41;
    }
    if ((int)(uint)local_20 < (int)(DAT_ffffa1f8 - 0x41)) {
      local_20 = DAT_ffffa1f8 - 0x41;
    }
    DAT_ffffa1f8 = local_20;
    DAT_ffffa1e0 = (float)local_20 * -0.625 * 7.6293945e-05 + 1.75;
    if (((DAT_ffffa208 < 0x14) && (DAT_ffffa203 == '\x01')) && (15233.0 <= adc_pair_ratio_raw_ffffa1d8)) {
      DAT_ffffa208 = DAT_ffffa208 + 1;
      DAT_ffffa1f4 = DAT_ffffa1f4 + DAT_ffffa1e0;
      fVar1 = rx8_clamp_float(DAT_ffffa1f4 / ((float)DAT_ffffa208 + 1.0),0.0,0.0);
      ref_updateMemoryAtAddress_float_VAL_ADDR(fVar1,&DAT_ffff8030);
    }
  }
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(arg3,&DAT_ffff8030);
  DAT_ffffa1d0 = rx8_first_order_filter(DAT_ffffa1e0 - fVar1,DAT_ffffa1d0,0.3439,arg3);
  DAT_ffffa1cc = lookup_2d_descriptor_scaled(DAT_ffffa1d0,&tbl_lambda_sensor_scaling_000697ec);
  return;
}


