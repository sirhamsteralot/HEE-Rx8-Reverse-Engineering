/* ROM address: 0x000303a8; body bytes: 74; decompiled */

void FUN_000303a8(void)

{
  if (engine_running_ffffa428 == '\0') {
    if (((inferred_coolant_temperature_ffffa98c < 150.0) || (DAT_ffffc5e6 != '\0')) || (DAT_ffffb423 != '\0')) {
      DAT_ffffbe68 = lookup_2d_descriptor_scaled(inferred_throttle_position_ffffad44,&DAT_0006ab00);
    }
    else {
      DAT_ffffbe68 = 0x3f800000;
    }
  }
  return;
}


