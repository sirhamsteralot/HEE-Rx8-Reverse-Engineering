/* ROM address: 0x0002292e; body bytes: 270; decompiled */

uint FUN_0002292e(void)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = DAT_ffffae97;
  if (DAT_ffffae97 == '\0') {
    if (DAT_ffffb39e == '\x01') {
      DAT_ffffb39d = 1;
    }
  }
  else {
    DAT_ffffb39d = 0;
  }
  if ((((DAT_ffffd07c == '\x01') || (DAT_ffffd0e4 == '\x01')) ||
      ((4500.0 <= DAT_ffffb5b8 && (DAT_ffffbe6c < 10.0)))) ||
     ((4.0 < DAT_ffffbc1c && (DAT_ffffaada == '\x01')))) {
    DAT_ffffb366 = 0;
  }
  else if (((DAT_ffffb388 != '\x01') || (DAT_ffffae97 != '\x01')) ||
          ((DAT_ffffb146 != 0 && (DAT_ffffae54 < 60.0)))) {
    DAT_ffffb366 = 0;
  }
  else {
    DAT_ffffb366 = 1;
  }
  uVar2 = (uint)DAT_ffffb39d;
  if (uVar2 == 1) {
    uVar2 = FUN_00002460((int)DAT_ffffb398,1);
    DAT_ffffb398 = (short)uVar2;
  }
  else {
    DAT_ffffb398 = 0;
  }
  DAT_ffffb39e = cVar1;
  return uVar2;
}


