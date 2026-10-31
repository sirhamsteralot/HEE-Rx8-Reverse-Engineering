/* ROM address: 0x0003bd60; body bytes: 394; decompiled */

char FUN_0003bd60(void)

{
  char cVar1;
  
  if (DAT_ffffc000 == -1) {
    DAT_ffffc5b9 = DAT_ffffc002 < 0x80;
    if (DAT_ffffc002 < 0x81) {
      DAT_ffffc5ba = '\0';
    }
    else {
      DAT_ffffc5ba = '\x01';
    }
  }
  else {
    DAT_ffffc5b9 = false;
    DAT_ffffc5ba = '\0';
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5aa = '\'';
    DAT_ffffc5ab = '\'';
    DAT_ffffc5bb = '\0';
    DAT_ffffc5bc = '\0';
    DAT_ffffc5bd = 0;
    DAT_ffffc5be = 0;
    cVar1 = '\x01';
  }
  else {
    if (((inferred_battery_voltage_ffffb590 < 11.0) || (16.0 < inferred_battery_voltage_ffffb590)) || (DAT_ffffd1ad == '\x01')) {
      DAT_ffffc5aa = '\'';
      DAT_ffffc5ab = '\'';
    }
    else if (DAT_ffffc000 == -1) {
      if ((bool)DAT_ffffc5b9 == true) {
        if (DAT_ffffc5aa == '\0') {
          cVar1 = ref_getFaultStatus__(0x35);
          if (cVar1 == '\0') {
            DAT_ffffc5bb = '\x01';
          }
        }
        else {
          DAT_ffffc5aa = DAT_ffffc5aa + -1;
        }
      }
      if (DAT_ffffc5ba == '\x01') {
        if (DAT_ffffc5ab == '\0') {
          cVar1 = ref_getFaultStatus__(0x37);
          if (cVar1 == '\0') {
            DAT_ffffc5bc = '\x01';
          }
        }
        else {
          DAT_ffffc5ab = DAT_ffffc5ab + -1;
        }
      }
    }
    else {
      DAT_ffffc5aa = '\'';
      DAT_ffffc5ab = '\'';
      if ((0x7f < DAT_ffffc002) && (DAT_ffffc002 < 0x81)) {
        DAT_ffffc5be = 1;
        DAT_ffffc5bb = '\0';
        DAT_ffffc5bc = '\0';
        DAT_ffffc5bd = 0;
      }
    }
    if (((DAT_ffffc5bb == '\x01') || (cVar1 = DAT_ffffc5bc, DAT_ffffc5bc == '\x01')) &&
       ((cVar1 = ref_getFaultStatus__(0x35), cVar1 == '\0' &&
        (cVar1 = ref_getFaultStatus__(0x37), cVar1 == '\0')))) {
      DAT_ffffc5bd = 1;
      DAT_ffffc5be = 0;
    }
  }
  return cVar1;
}


