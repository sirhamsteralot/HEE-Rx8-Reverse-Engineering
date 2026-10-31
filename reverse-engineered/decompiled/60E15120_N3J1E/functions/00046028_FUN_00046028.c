/* ROM address: 0x00046028; body bytes: 144; decompiled */

void FUN_00046028(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffb4ec;
  cVar1 = DAT_ffffad18;
  if (DAT_ffffcc0c != '\0') {
    if (DAT_ffffcc0c != '\x01') {
      DAT_ffffcc12 = cVar1;
      DAT_ffffcc13 = cVar2;
      return;
    }
    if ((DAT_ffffad18 == DAT_ffffcc12) && (DAT_ffffb4ec == DAT_ffffcc13)) {
      if (DAT_ffffad18 != DAT_ffffb4ec) {
        DAT_ffffcc10 = 0;
        DAT_ffffcc0e = rx8_add_u16_saturate((int)DAT_ffffcc0e,1);
        DAT_ffffcc12 = cVar1;
        DAT_ffffcc13 = cVar2;
        return;
      }
      DAT_ffffcc0e = 0;
      DAT_ffffcc10 = rx8_add_u16_saturate((int)DAT_ffffcc10,1);
      DAT_ffffcc12 = cVar1;
      DAT_ffffcc13 = cVar2;
      return;
    }
  }
  DAT_ffffcc10 = 0;
  DAT_ffffcc0e = 0;
  DAT_ffffcc12 = cVar1;
  DAT_ffffcc13 = cVar2;
  return;
}


