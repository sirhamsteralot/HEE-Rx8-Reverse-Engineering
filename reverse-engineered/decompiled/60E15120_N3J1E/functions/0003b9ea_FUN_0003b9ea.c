/* ROM address: 0x0003b9ea; body bytes: 394; decompiled */

char FUN_0003b9ea(void)

{
  char cVar1;
  
  if (DAT_ffffc000 == -1) {
    DAT_ffffc5ad = DAT_ffffc001 < 0x80;
    if (DAT_ffffc001 < 0x81) {
      DAT_ffffc5ae = '\0';
    }
    else {
      DAT_ffffc5ae = '\x01';
    }
  }
  else {
    DAT_ffffc5ad = false;
    DAT_ffffc5ae = '\0';
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5a8 = '\'';
    DAT_ffffc5a9 = '\'';
    DAT_ffffc5af = '\0';
    DAT_ffffc5b0 = '\0';
    DAT_ffffc5b1 = 0;
    DAT_ffffc5b2 = 0;
    cVar1 = '\x01';
  }
  else {
    if (((inferred_battery_voltage_ffffb590 < 11.0) || (16.0 < inferred_battery_voltage_ffffb590)) || (DAT_ffffd1ad == '\x01')) {
      DAT_ffffc5a8 = '\'';
      DAT_ffffc5a9 = '\'';
    }
    else if (DAT_ffffc000 == -1) {
      if ((bool)DAT_ffffc5ad == true) {
        if (DAT_ffffc5a8 == '\0') {
          cVar1 = ref_getFaultStatus__(0x34);
          if (cVar1 == '\0') {
            DAT_ffffc5af = '\x01';
          }
        }
        else {
          DAT_ffffc5a8 = DAT_ffffc5a8 + -1;
        }
      }
      if (DAT_ffffc5ae == '\x01') {
        if (DAT_ffffc5a9 == '\0') {
          cVar1 = ref_getFaultStatus__(0x36);
          if (cVar1 == '\0') {
            DAT_ffffc5b0 = '\x01';
          }
        }
        else {
          DAT_ffffc5a9 = DAT_ffffc5a9 + -1;
        }
      }
    }
    else {
      DAT_ffffc5a8 = '\'';
      DAT_ffffc5a9 = '\'';
      if (((0x7f < DAT_ffffc001) && (DAT_ffffc001 < 0x81)) &&
         ((cVar1 = ref_getFaultStatus__(0x34), cVar1 == '\0' &&
          (cVar1 = ref_getFaultStatus__(0x36), cVar1 == '\0')))) {
        DAT_ffffc5b2 = 1;
        DAT_ffffc5af = '\0';
        DAT_ffffc5b0 = '\0';
        DAT_ffffc5b1 = 0;
      }
    }
    cVar1 = '\x01';
    if ((DAT_ffffc5af == '\x01') || (cVar1 = DAT_ffffc5b0, DAT_ffffc5b0 == '\x01')) {
      DAT_ffffc5b1 = 1;
      DAT_ffffc5b2 = 0;
    }
  }
  return cVar1;
}


