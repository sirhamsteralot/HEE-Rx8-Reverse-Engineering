/* ROM address: 0x00020d72; body bytes: 296; decompiled */

void FUN_00020d72(void)

{
  float arg1;
  
  if (DAT_ffffaa10 < -40.0) {
    if (DAT_ffffaa10 < -43.0) {
      DAT_ffffb240 = '\0';
    }
  }
  else {
    DAT_ffffb240 = '\x01';
  }
  arg1 = 0.0;
  if ((DAT_ffffc600 == '\0') && (DAT_ffffcce1 == '\0')) {
    if ((((DAT_ffffb240 != '\x01') || (DAT_ffffcda0 != '\0')) || (1000.0 < DAT_ffffc6b4)) ||
       ((((DAT_ffffb1c2 != '\x01' || (DAT_ffffb1b2 == 0)) &&
         ((DAT_ffffb1c9 != '\x01' || (DAT_ffffb1c4 != '\x01')))) && (DAT_ffffb1c7 != '\x01')))) {
      if ((DAT_ffffb19c != '\x01') ||
         (((DAT_ffffb1b2 != 0 && (DAT_ffffb1c7 != '\0')) &&
          ((DAT_ffffb1c9 != '\0' && ((DAT_ffffc6b4 <= 1000.0 && (DAT_ffffb1c4 != '\0')))))))) {
        DAT_ffffb18c = 0.0;
        DAT_ffffb188 = 0.0;
      }
      else {
        DAT_ffffb18c = rx8_max_float(DAT_ffffb18c - 0.0667,0.0);
        DAT_ffffb188 = rx8_max_float(DAT_ffffb188 - 0.0667,arg1);
      }
    }
    else {
      DAT_ffffb18c = 1.0;
      DAT_ffffb188 = 1.0;
    }
  }
  else {
    DAT_ffffb18c = 0.0;
    DAT_ffffb188 = 0.0;
  }
  return;
}


