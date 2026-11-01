/* ROM address: 0x00012e20; body bytes: 308; decompiled */

uint FUN_00012e20(void)

{
  bool bVar1;
  uint uVar2;
  
  if ((DAT_ffffa6dd == '\0') && (DAT_ffffa7bc - 150.0 <= DAT_ffffb5b8)) {
    DAT_ffffa6dd = '\x01';
  }
  if ((((DAT_ffffbfd4 == '\x01') && (DAT_ffffa428 == '\x01')) && (DAT_ffffa6dd == '\x01')) &&
     (DAT_ffffce6f == '\0')) {
    DAT_ffffa6b6 = 1;
  }
  else {
    DAT_ffffa6b6 = 0;
  }
  if ((DAT_ffffa6de == '\x01') && (DAT_ffffa428 == '\0')) {
    DAT_ffffa6dc = '\0';
  }
  else if ((DAT_ffffa6e0 == '\0') && (DAT_ffffa6b6 == 1)) {
    DAT_ffffa6dc = '\x01';
  }
  DAT_ffffa6de = DAT_ffffa428;
  DAT_ffffa6e0 = DAT_ffffa6b6;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffa6b4 = 0;
  }
  else if (DAT_ffffa6dc == '\x01') {
    DAT_ffffa6b4 = FUN_00002460((int)(short)DAT_ffffa6b4,1);
  }
  if ((DAT_ffffa6b6 == 0) || (0x75 < DAT_ffffa6b4)) {
    DAT_ffffa6b7 = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffa6b7 = 1;
    bVar1 = true;
  }
  if (DAT_ffffa6b6 == 0) {
    DAT_ffffa6b8 = 0;
  }
  else if (!bVar1) {
    DAT_ffffa6b8 = 1;
  }
  uVar2 = (uint)DAT_ffffa6b6;
  if ((uVar2 == 1) && ((DAT_ffffaada == '\0' || (uVar2 = (uint)DAT_ffffb5aa, uVar2 == 0)))) {
    DAT_ffffa6b9 = 1;
  }
  else {
    DAT_ffffa6b9 = 0;
  }
  return uVar2;
}


