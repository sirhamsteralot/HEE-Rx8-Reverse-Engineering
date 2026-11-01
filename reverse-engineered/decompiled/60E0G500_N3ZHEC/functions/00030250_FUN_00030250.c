/* ROM address: 0x00030250; body bytes: 406; decompiled */

uint FUN_00030250(void)

{
  uint uVar1;
  
  if (DAT_ffffaa10 < 101.0) {
    if (DAT_ffffaa10 < 98.0) {
      DAT_ffffbe18 = '\0';
    }
  }
  else {
    DAT_ffffbe18 = '\x01';
  }
  if (DAT_ffffc71c < 1.94) {
    if (DAT_ffffc71c < 1.84) {
      DAT_ffffbe1e = '\0';
    }
  }
  else {
    DAT_ffffbe1e = '\x01';
  }
  if (DAT_ffffaa10 < 80.0) {
    if (DAT_ffffaa10 < 77.0) {
      DAT_ffffbe1f = '\0';
    }
  }
  else {
    DAT_ffffbe1f = '\x01';
  }
  if (DAT_ffffbc1c < 10.0) {
    if (DAT_ffffbc1c < 8.0) {
      DAT_ffffbe20 = '\0';
    }
  }
  else {
    DAT_ffffbe20 = '\x01';
  }
  uVar1 = (uint)DAT_ffffbe0d;
  if (((((uVar1 == 1) && (0x5c < DAT_ffffbe14)) &&
       ((((DAT_ffffbe18 == '\x01' ||
          (((DAT_ffffbe18 == '\0' && (DAT_ffffbdd4 == '\x01')) && (DAT_ffffbe24 == '\x01')))) ||
         ((((DAT_ffffaae0 == '\0' && (DAT_ffffbe0c == '\x01')) && (DAT_ffffcd06 == '\0')) &&
          ((DAT_ffffa96a == '\0' && (DAT_ffffbff5 == '\0')))))) ||
        ((DAT_ffffbdd6 == '\x01' ||
         (((DAT_ffffbe1e == '\0' && (DAT_ffffbe1f == '\x01')) && (DAT_ffffbe20 == '\0')))))))) ||
      ((DAT_ffffc656 == '\x01' || ((DAT_ffffd2a0 == '\x01' && (DAT_ffffd2a5 == '\0')))))) &&
     (DAT_ffffd29f == '\0')) {
    DAT_ffffbe0e = 1;
  }
  else {
    DAT_ffffbe0e = 0;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffbe14,1);
    DAT_ffffbe14 = (ushort)uVar1;
  }
  else {
    DAT_ffffbe14 = 0;
  }
  return uVar1;
}


