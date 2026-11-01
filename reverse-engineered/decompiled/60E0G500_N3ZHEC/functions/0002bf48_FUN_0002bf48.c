/* ROM address: 0x0002bf48; body bytes: 148; decompiled */

void FUN_0002bf48(void)

{
  float fVar1;
  float arg1;
  
  arg1 = 0.0;
  if ((((DAT_ffffbb8c == '\0') && (DAT_ffffbb90 == '\0')) && (DAT_ffffa428 == '\x01')) &&
     (((DAT_ffffbc50 != 0 && (DAT_ffffa401 == '\0')) && (DAT_ffffa40a == '\0')))) {
    fVar1 = (float)FUN_00002500(0x3ec99326,0,(int)DAT_ffffbc30);
  }
  else {
    fVar1 = 512.0;
  }
  DAT_ffffbc40 = rx8_clamp_float(((DAT_ffffbb88 * fVar1) / 100.0 - DAT_ffffbd24) - DAT_ffffbd28,arg1
                                 ,512.0);
  return;
}


