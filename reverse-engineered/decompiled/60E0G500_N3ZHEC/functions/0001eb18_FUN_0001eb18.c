/* ROM address: 0x0001eb18; body bytes: 464; decompiled */

void FUN_0001eb18(void)

{
  if (((((DAT_ffffa9e8 == '\x01') || (DAT_ffffca0c == '\x01')) || (DAT_ffffccb1 == '\x01')) ||
      ((DAT_ffffcab5 == '\x01' || (DAT_ffffcdfe == '\x01')))) ||
     ((DAT_ffffcdff == '\x01' || ((DAT_ffffce00 == '\x01' || (DAT_ffffce01 == '\x01')))))) {
    DAT_ffffb138 = '\x01';
  }
  else {
    if (((DAT_ffffa444 == '\x01') ||
        ((DAT_ffffa4a4 == '\x01' || ((DAT_ffffbcef != 0 && (DAT_ffffbcef < 5)))))) ||
       ((DAT_ffffccb0 != 0 && (DAT_ffffccb0 < 5)))) {
      DAT_ffffb138 = '\x01';
    }
    else {
      DAT_ffffb138 = '\0';
    }
    if ((((DAT_ffffa445 != '\x01') && (DAT_ffffa4a5 != '\x01')) &&
        ((DAT_ffffbcef < 3 || (4 < DAT_ffffbcef)))) && ((DAT_ffffccb0 < 3 || (4 < DAT_ffffccb0)))) {
      DAT_ffffb139 = '\0';
      goto LAB_0001ec52;
    }
  }
  DAT_ffffb139 = '\x01';
LAB_0001ec52:
  if ((DAT_ffffb138 == '\x01') || (DAT_ffffb139 == '\x01')) {
    DAT_ffffb13a = 1;
  }
  else {
    DAT_ffffb13a = 0;
  }
  if ((DAT_ffffb138 == '\x01') && (DAT_ffffb139 == '\x01')) {
    DAT_ffffb13b = 1;
  }
  else {
    DAT_ffffb13b = 0;
  }
  if ((DAT_ffffa444 == '\x01') || (DAT_ffffa445 == '\x01')) {
    DAT_ffffb13c = 1;
  }
  else {
    DAT_ffffb13c = 0;
  }
  if ((DAT_ffffa444 == '\x01') && (DAT_ffffa445 == '\x01')) {
    DAT_ffffb13d = 1;
  }
  else {
    DAT_ffffb13d = 0;
  }
  if ((DAT_ffffa4a4 == '\x01') || (DAT_ffffa4a5 == '\x01')) {
    DAT_ffffb13e = 1;
  }
  else {
    DAT_ffffb13e = 0;
  }
  if ((DAT_ffffa4a4 == '\x01') && (DAT_ffffa4a5 == '\x01')) {
    DAT_ffffb13f = 1;
  }
  else {
    DAT_ffffb13f = 0;
  }
  FUN_0000e2d4(1);
  return;
}


