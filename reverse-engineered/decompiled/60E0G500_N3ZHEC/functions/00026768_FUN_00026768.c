/* ROM address: 0x00026768; body bytes: 134; decompiled */

void FUN_00026768(void)

{
  float arg0;
  
  if (DAT_ffffc64b == '\0') {
    DAT_ffffb628 = (float)FUN_00002068(DAT_ffffbc1c,&PTR_DAT_0006aa94);
    DAT_ffffb62c = (DAT_ffffaa10 - 93.0) * 0.43;
    if (DAT_ffffb62c < 0.0) {
      DAT_ffffb62c = 0.0;
    }
    arg0 = rx8_first_order_filter(DAT_ffffb628,DAT_ffffb630,2e-05,1e-05);
    DAT_ffffb630 = rx8_clamp_float(arg0,-7.2,4.4);
    DAT_ffffb634 = DAT_ffffae54 + DAT_ffffb62c + DAT_ffffb630;
  }
  else {
    DAT_ffffb634 = 66.25;
  }
  return;
}


