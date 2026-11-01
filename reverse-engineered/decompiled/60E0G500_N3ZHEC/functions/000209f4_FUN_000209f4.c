/* ROM address: 0x000209f4; body bytes: 390; decompiled */

uint FUN_000209f4(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_ffffbf38;
  cVar1 = DAT_ffffb1c8;
  if (DAT_ffffc12c < 0.0) {
    if (DAT_ffffc12c < -0.04) {
      DAT_ffffb241 = '\0';
    }
  }
  else {
    DAT_ffffb241 = '\x01';
  }
  if (DAT_ffffc12c <= 0.875) {
    if (DAT_ffffc12c <= 0.835) {
      DAT_ffffb242 = '\0';
    }
  }
  else {
    DAT_ffffb242 = '\x01';
  }
  if (DAT_ffffb5b8 < 3500.0) {
    if (DAT_ffffb5b8 < 3300.0) {
      DAT_ffffb243 = '\0';
    }
  }
  else {
    DAT_ffffb243 = '\x01';
  }
  if (DAT_ffffb5b8 <= 6000.0) {
    if (DAT_ffffb5b8 <= 5800.0) {
      DAT_ffffb244 = '\0';
    }
  }
  else {
    DAT_ffffb244 = '\x01';
  }
  if ((((DAT_ffffb241 == '\x01') && (DAT_ffffb242 == '\0')) && (DAT_ffffb243 == '\x01')) &&
     ((DAT_ffffb244 == '\0' && ((DAT_ffffbca9 == '\x05' || (DAT_ffffbca9 == '\x06')))))) {
    DAT_ffffb1c8 = '\x01';
  }
  else {
    DAT_ffffb1c8 = '\0';
  }
  if ((cVar1 == '\x01') && (DAT_ffffb1c8 == '\0')) {
    DAT_ffffb21c = 0;
  }
  else if (DAT_ffffb21c != 0) {
    DAT_ffffb21c = DAT_ffffb21c + -1;
  }
  if ((DAT_ffffb1c8 == '\x01') || (DAT_ffffb21c != 0)) {
    DAT_ffffb1c7 = 1;
  }
  else {
    DAT_ffffb1c7 = 0;
  }
  uVar3 = (uint)DAT_ffffb1c7;
  if (((uVar3 == 1) && (DAT_ffffb24a == '\0')) && (uVar3 = (uint)DAT_ffffbf38, uVar3 == 1)) {
    uVar3 = FUN_000020c4(&DAT_0006a498);
    DAT_ffffb1c0 = (short)uVar3;
  }
  else if (DAT_ffffb1c0 != 0) {
    DAT_ffffb1c0 = DAT_ffffb1c0 + -1;
  }
  DAT_ffffb24a = bVar2;
  return uVar3;
}


