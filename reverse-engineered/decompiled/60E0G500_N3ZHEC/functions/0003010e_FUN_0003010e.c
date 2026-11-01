/* ROM address: 0x0003010e; body bytes: 248; decompiled */

char FUN_0003010e(void)

{
  char cVar1;
  
  if (DAT_ffffaa10 < 97.0) {
    if (DAT_ffffaa10 < 94.0) {
      DAT_ffffbe16 = '\0';
    }
  }
  else {
    DAT_ffffbe16 = '\x01';
  }
  if (DAT_ffffaa10 < 97.0) {
    if (DAT_ffffaa10 < 94.0) {
      DAT_ffffbe17 = '\0';
    }
  }
  else {
    DAT_ffffbe17 = '\x01';
  }
  if (((((((DAT_ffffbe16 == '\x01') || ((DAT_ffffbe17 == '\x01' && (DAT_ffffb13d == '\x01')))) ||
         ((DAT_ffffaae0 == '\0' &&
          ((((DAT_ffffbe0c == '\x01' && (DAT_ffffcd06 == '\0')) && (DAT_ffffa96a == '\0')) &&
           (DAT_ffffbff5 == '\0')))))) || ((DAT_ffffbdd4 == '\x01' || (DAT_ffffbdd6 == '\x01')))) &&
       ((DAT_ffffd07c == '\0' && (cVar1 = '\0', DAT_ffffd0e4 == '\0')))) ||
      ((cVar1 = '\x01', DAT_ffffd2a0 == '\x01' || (cVar1 = DAT_ffffd2a5, DAT_ffffd2a5 == '\x01'))))
     && (DAT_ffffd29f == '\0')) {
    DAT_ffffbe0d = 1;
  }
  else {
    DAT_ffffbe0d = 0;
  }
  return cVar1;
}


