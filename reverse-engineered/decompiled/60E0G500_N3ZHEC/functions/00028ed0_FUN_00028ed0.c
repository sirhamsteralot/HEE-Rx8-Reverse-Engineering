/* ROM address: 0x00028ed0; body bytes: 124; decompiled */

void FUN_00028ed0(void)

{
  float *pfVar1;
  float arg0;
  
  arg0 = 0.0;
  if ((DAT_ffffb6d0 & 1) == 0) {
    pfVar1 = &DAT_ffffba9c;
    if (DAT_ffffb736 == '\x01') {
      DAT_ffffba9c = rx8_first_order_filter(DAT_ffffba98,DAT_ffffba9c,0.125,1e-05);
    }
    else {
      DAT_ffffba9c = 0.0;
    }
  }
  else {
    pfVar1 = &DAT_ffffbaa0;
    if (DAT_ffffb736 == '\x01') {
      DAT_ffffbaa0 = rx8_first_order_filter(DAT_ffffba98,DAT_ffffbaa0,0.125,1e-05);
    }
    else {
      DAT_ffffbaa0 = 0.0;
    }
  }
  DAT_ffffbaa4 = *pfVar1;
  DAT_ffffbaa8 = rx8_max_float(arg0,DAT_ffffbaa4);
  return;
}


