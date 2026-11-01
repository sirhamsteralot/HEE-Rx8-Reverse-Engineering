/* ROM address: 0x0001ce38; body bytes: 320; decompiled */

char FUN_0001ce38(void)

{
  char cVar1;
  
  if (DAT_ffffc12c <= 2.0) {
    if (DAT_ffffc12c <= 1.98) {
      DAT_ffffb0d6 = '\0';
    }
  }
  else {
    DAT_ffffb0d6 = '\x01';
  }
  if (1000.0 <= DAT_ffffb5b8) {
    if (1100.0 <= DAT_ffffb5b8) {
      DAT_ffffb0d7 = '\0';
    }
  }
  else {
    DAT_ffffb0d7 = '\x01';
  }
  DAT_ffffb0ce = FUN_000020c4(DAT_ffffaa1c,&DAT_00069f8c);
  if (((((DAT_ffffaa10 < 35.0) || (DAT_ffffa424 < DAT_ffffb0ce)) || (DAT_ffffb19c != '\0')) ||
      ((DAT_ffffae90 != 0 || (cVar1 = FUN_00002440(DAT_ffffbce0,0,0x3727c5ac), cVar1 != '\0')))) ||
     ((((8 < DAT_ffffa9be || ((DAT_ffffb0d4 < 0x10 || (DAT_ffffbfd4 != '\0')))) ||
       (DAT_ffffb0d5 < 4)) ||
      ((DAT_ffffd2a9 != '\0' || ((DAT_ffffb0d6 != '\0' && (DAT_ffffb0d7 != '\x01')))))))) {
    DAT_ffffae96 = '\0';
  }
  else {
    DAT_ffffae96 = '\x01';
  }
  cVar1 = DAT_ffffae96;
  if (((DAT_ffffae96 == '\x01') && (DAT_ffffcd9c == '\0')) &&
     ((cVar1 = '\x01', DAT_ffffaaf8 == '\x01' || (cVar1 = DAT_ffffaaf9, DAT_ffffaaf9 == '\x01')))) {
    DAT_ffffae97 = 1;
  }
  else {
    DAT_ffffae97 = 0;
  }
  return cVar1;
}


