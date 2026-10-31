/* ROM address: 0x0003cf4c; body bytes: 50; decompiled */

void FUN_0003cf4c(void)

{
  float arg1;
  
  if (DAT_ffffd1ad == '\0') {
    arg1 = inferred_coolant_temperature_ffffa98c;
    DAT_ffffc5f0 = rx8_max_float(DAT_ffffc5f0,inferred_coolant_temperature_ffffa98c);
    DAT_ffffc5f4 = rx8_min_float(DAT_ffffc5f4,arg1);
  }
  return;
}


