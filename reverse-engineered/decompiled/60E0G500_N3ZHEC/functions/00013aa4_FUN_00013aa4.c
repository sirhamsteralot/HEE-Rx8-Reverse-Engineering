/* ROM address: 0x00013aa4; body bytes: 236; decompiled */

void FUN_00013aa4(void)

{
  char cVar1;
  float arg0;
  float fVar2;
  
  cVar1 = DAT_ffffc0c8;
  fVar2 = DAT_ffffa744;
  arg0 = DAT_ffffa73c;
  if (DAT_ffffa740 == '\x01') {
    if (((DAT_ffffc0c7 == '\0') && (arg0 = DAT_ffffa73c + 0.015, DAT_ffffa75d == '\x01')) &&
       (DAT_ffffc0c8 == '\0')) {
      arg0 = rx8_max_float(arg0,0.0);
    }
    if (DAT_ffffc0c4 == '\0') {
      if (DAT_ffffc0c5 == '\0') {
        DAT_ffffa75b = 0;
        if (0x3d < DAT_ffffa75a) {
          fVar2 = DAT_ffffa744 + 0.35;
          DAT_ffffa75a = 0;
        }
        DAT_ffffa75a = FUN_00002478((int)(char)DAT_ffffa75a,1);
      }
      else {
        DAT_ffffa75a = 0;
        if (0x3d < DAT_ffffa75b) {
          DAT_ffffa75b = 0;
          fVar2 = DAT_ffffa744 + 0.35;
        }
        DAT_ffffa75b = FUN_00002478((int)(char)DAT_ffffa75b,1);
      }
    }
    else {
      DAT_ffffa75a = 0;
      DAT_ffffa75b = 0;
    }
  }
  DAT_ffffa73c = (float)FUN_00013c3a(arg0);
  DAT_ffffa744 = (float)FUN_00013bd4(fVar2);
  DAT_ffffa734 = FUN_00013c4e(DAT_ffffa73c + DAT_ffffa744);
  DAT_ffffa738 = DAT_ffffa734;
  DAT_ffffa75d = cVar1;
  return;
}


