/* ROM address: 0x00025b12; body bytes: 48; decompiled */

void FUN_00025b12(void)

{
  DAT_ffffb5cc = rx8_clamp_float(DAT_ffffb5b8 + (DAT_ffffb5b8 - DAT_ffffb5d4) * 2.0,0.0,9000.0);
  DAT_ffffb5d4 = DAT_ffffb5b8;
  return;
}


