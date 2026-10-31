/* ROM address: 0x00014100; body bytes: 86; decompiled */

void FUN_00014100(void)

{
  undefined *puVar1;
  
  if (DAT_ffffaa62 == '\x01') {
    DAT_ffffa780 = lookup_2d_descriptor_scaled(&DAT_00069208);
  }
  else {
    if ((inferred_coolant_temperature_ffffa98c < 90.0) || (engine_load_ffffc0b4 < 0.5)) {
      puVar1 = &DAT_0006921c;
    }
    else {
      puVar1 = &DAT_00069230;
    }
    DAT_ffffa780 = lookup_2d_descriptor_scaled(puVar1);
  }
  DAT_ffffa784 = DAT_ffffa780;
  return;
}


