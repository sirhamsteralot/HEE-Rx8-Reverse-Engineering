/* ROM address: 0x0001750e; body bytes: 348; decompiled */

char FUN_0001750e(void)

{
  float arg0;
  
  if ((((((DAT_ffffa426 < 0x1f) || (DAT_ffffadbc <= 83.0)) || (DAT_ffffb5b8 <= 2000.0)) ||
       ((6000.0 <= DAT_ffffb5b8 || (DAT_ffffaa10 <= 255.0)))) ||
      ((DAT_ffffae54 <= 255.0 || ((DAT_ffffad8c <= 82.0 || (DAT_ffffb5aa != '\0')))))) ||
     (DAT_ffffa958 < 0xfa)) {
    DAT_ffffa93f = '\0';
  }
  else {
    DAT_ffffa93f = '\x01';
  }
  if (DAT_ffffb5aa == '\0') {
    DAT_ffffa958 = FUN_00002460((int)(short)DAT_ffffa958,1);
  }
  else {
    DAT_ffffa958 = 0;
  }
  if (DAT_ffffa93f == '\0') {
    DAT_ffffa900 = 1.0;
  }
  else {
    arg0 = (float)FUN_0003ea74(DAT_ffffc12c,DAT_ffffc130);
    DAT_ffffa900 = rx8_first_order_filter(arg0,DAT_ffffa900,0.1,1e-05);
  }
  if (0.9 <= DAT_ffffa900) {
    DAT_ffffa95a = 0;
    DAT_ffffa950 = 0;
    DAT_ffffa940 = '\0';
  }
  else {
    if ((DAT_ffffa950 < 0x7d) || (0x1b5 < DAT_ffffa95a)) {
      DAT_ffffa940 = '\0';
    }
    else {
      DAT_ffffa95a = FUN_00002460((int)(short)DAT_ffffa95a,1);
      DAT_ffffa940 = '\x01';
    }
    DAT_ffffa950 = FUN_00002460((int)(short)DAT_ffffa950,1);
  }
  if (DAT_ffffa940 == '\x01') {
    DAT_ffffa904 = 30.0;
  }
  else {
    DAT_ffffa904 = DAT_ffffa904 - 0.16;
    if (DAT_ffffa904 < 0.0) {
      DAT_ffffa904 = 0.0;
    }
  }
  return DAT_ffffa940;
}


