/* ROM address: 0x00030c08; body bytes: 120; decompiled */

void FUN_00030c08(void)

{
  float arg0;
  float arg0_00;
  
  arg0 = DAT_ffffbe54 * DAT_ffffbe7c * DAT_ffffbf2c;
  arg0_00 = DAT_ffffbe58 * DAT_ffffbe80 * DAT_ffffbf30;
  DAT_ffffbeb8 = rx8_clamp_float(DAT_ffffbe50 * DAT_ffffbe78 * DAT_ffffbf28,1024.0,100000.0);
  DAT_ffffbebc = rx8_clamp_float(arg0,0.0,100000.0);
  DAT_ffffbec0 = rx8_clamp_float(arg0_00,0.0,100000.0);
  return;
}


