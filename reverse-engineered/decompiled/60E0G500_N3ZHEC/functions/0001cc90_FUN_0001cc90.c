/* ROM address: 0x0001cc90; body bytes: 188; decompiled */

void FUN_0001cc90(void)

{
  float arg0;
  
  if (DAT_ffffc12c < 2.0) {
    if (DAT_ffffc12c < 1.96) {
      DAT_ffffae62 = '\0';
    }
  }
  else {
    DAT_ffffae62 = '\x01';
  }
  if ((DAT_ffffa428 == '\x01') && (DAT_ffffae62 == '\x01')) {
    DAT_ffffae63 = '\x01';
  }
  else if ((DAT_ffffa428 == '\0') || ((DAT_ffffae62 == '\0' && (0xe9 < DAT_ffffae60)))) {
    DAT_ffffae63 = '\0';
  }
  if (DAT_ffffae62 == '\0') {
    DAT_ffffae60 = FUN_00002460((int)(short)DAT_ffffae60,1);
  }
  else {
    DAT_ffffae60 = 0;
  }
  arg0 = rx8_first_order_filter(DAT_ffffae54,DAT_ffffae5c,0.996,1e-05);
  if (DAT_ffffae63 != '\0') {
    arg0 = rx8_min_float(arg0,DAT_ffffae5c);
  }
  DAT_ffffae5c = arg0;
  return;
}


