/* ROM address: 0x00010b30; body bytes: 326; decompiled */

char FUN_00010b30(char param_1)

{
  char cVar1;
  
  DAT_ffffa5d8 = 0;
  if (DAT_ffffa9d9 == '\x01') {
    DAT_ffffa5de = '\0';
  }
  if ((((DAT_ffffc63c == '\x01') || (DAT_ffffa798 == '\x01')) || (DAT_ffffbc94 == '\x01')) ||
     ((DAT_ffffbc95 == '\x01' || (DAT_ffffc240 == '\0')))) {
    DAT_ffffa5d8 = 0xf;
  }
  if (DAT_ffffa9da == '\x01') {
    DAT_ffffa9d9 = '\0';
    DAT_ffffa5de = '\0';
    if (DAT_ffffa9d8 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 4;
    }
    if (DAT_ffffa9d6 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 8;
    }
    if (DAT_ffffa9d7 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 1;
    }
    if (DAT_ffffa9d5 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 2;
    }
  }
  else {
    if (((DAT_ffffa9d9 == '\0') && ((param_1 == '\x06' || (param_1 == '\x12')))) ||
       (DAT_ffffa5de == '\x01')) {
      if (DAT_ffffa9d8 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 4;
      }
      if (DAT_ffffa9d6 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 8;
      }
      DAT_ffffa5de = '\x01';
    }
    if (((DAT_ffffa9d9 == '\0') || (param_1 == '\0')) || (param_1 == '\f')) {
      if (DAT_ffffa9d7 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 1;
      }
      DAT_ffffa9d9 = '\0';
      if (DAT_ffffa9d5 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 2;
      }
    }
  }
  if (DAT_ffffbc96 != '\x01') {
    DAT_ffffa5dc = 0;
    cVar1 = DAT_ffffbc96;
  }
  else {
    DAT_ffffa5dc = 4;
    cVar1 = '\x01';
  }
  DAT_ffffa5da = (ushort)(DAT_ffffbc96 == '\x01');
  return cVar1;
}


