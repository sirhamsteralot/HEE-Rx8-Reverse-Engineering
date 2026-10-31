/* ROM address: 0x000303f2; body bytes: 50; decompiled */

void FUN_000303f2(void)

{
  if (engine_running_ffffa428 == '\0') {
    if (DAT_ffffc590 == '\0') {
      DAT_ffffbe80 = lookup_2d_descriptor_scaled(inferred_barometric_pressure_ffffad14,&DAT_0006ab14);
    }
    else {
      DAT_ffffbe80 = 0x3f800000;
    }
  }
  return;
}


