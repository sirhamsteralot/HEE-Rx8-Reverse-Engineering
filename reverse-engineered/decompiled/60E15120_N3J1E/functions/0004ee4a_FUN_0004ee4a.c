/* ROM address: 0x0004ee4a; body bytes: 278; decompiled */

void FUN_0004ee4a(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffcfbb;
  cVar1 = DAT_ffffcfba;
  if (DAT_ffffcfba == '\x01') {
    if ((DAT_ffffcfd3 == '\0') || (DAT_ffffcfce == '\0')) {
      DAT_ffffcfad = '\0';
    }
    else {
      DAT_ffffcfad = rx8_add_u8_saturate((int)DAT_ffffcfad,1);
    }
    if (DAT_ffffcfd3 == '\0') {
      DAT_ffffcfac = '\0';
    }
    else if ((DAT_ffffcfce == '\0') && (DAT_ffffcfad == '\0')) {
      DAT_ffffcfac = rx8_add_u8_saturate((int)DAT_ffffcfac,1);
    }
  }
  if (cVar2 == '\x01') {
    if ((DAT_ffffcfd4 == '\0') || (DAT_ffffcfcf == '\0')) {
      DAT_ffffcfaf = '\0';
    }
    else {
      DAT_ffffcfaf = rx8_add_u8_saturate((int)DAT_ffffcfaf,1);
    }
    if (DAT_ffffcfd4 == '\0') {
      DAT_ffffcfae = '\0';
    }
    else if ((DAT_ffffcfcf == '\0') && (DAT_ffffcfaf == '\0')) {
      DAT_ffffcfae = rx8_add_u8_saturate((int)DAT_ffffcfae,1);
    }
  }
  DAT_ffffcfd3 = cVar1;
  DAT_ffffcfd4 = cVar2;
  DAT_ffffcfce = DAT_ffffcfad;
  DAT_ffffcfcf = DAT_ffffcfaf;
  return;
}


