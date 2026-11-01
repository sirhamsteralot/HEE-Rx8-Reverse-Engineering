/* ROM address: 0x00010b38; body bytes: 296; decompiled */

char FUN_00010b38(char param_1)

{
  char cVar1;
  
  DAT_ffffa5d8 = 0;
  if (DAT_ffffa955 == '\x01') {
    DAT_ffffa5da = '\0';
  }
  if ((((DAT_ffffc5cc == '\x01') || (DAT_ffffa788 == '\x01')) || (DAT_ffffbc28 == '\x01')) ||
     ((DAT_ffffbc29 == '\x01' || (inferred_ram_c1d0_ffffc1d0_ffffc1d0 == '\0')))) {
    DAT_ffffa5d8 = 0xf;
  }
  cVar1 = DAT_ffffa951;
  if (DAT_ffffa956 == '\x01') {
    DAT_ffffa955 = '\0';
    DAT_ffffa5da = '\0';
    if (DAT_ffffa954 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 4;
    }
    if (DAT_ffffa952 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 8;
    }
    if (DAT_ffffa953 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 1;
    }
    if (DAT_ffffa951 == '\x01') {
      DAT_ffffa5d8 = DAT_ffffa5d8 | 2;
    }
  }
  else {
    if (((DAT_ffffa955 == '\0') && ((param_1 == '\x06' || (param_1 == '\x12')))) ||
       (DAT_ffffa5da == '\x01')) {
      if (DAT_ffffa954 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 4;
      }
      if (DAT_ffffa952 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 8;
      }
      DAT_ffffa5da = '\x01';
    }
    if (((DAT_ffffa955 == '\0') || (param_1 == '\0')) || (cVar1 = param_1, param_1 == '\f')) {
      if (DAT_ffffa953 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 1;
      }
      DAT_ffffa955 = '\0';
      cVar1 = DAT_ffffa951;
      if (DAT_ffffa951 == '\x01') {
        DAT_ffffa5d8 = DAT_ffffa5d8 | 2;
      }
    }
  }
  return cVar1;
}


