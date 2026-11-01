/* ROM address: 0x0002d604; body bytes: 126; decompiled */

void FUN_0002d604(char param_1)

{
  if (param_1 != '\0') goto LAB_0002d668;
  if (DAT_ffffbcef == '\x01') {
    DAT_ffffbcf0 = '\x01';
    DAT_ffffbcf1 = '\0';
  }
  else {
    if (DAT_ffffbcef == '\x02') {
      DAT_ffffbcf0 = '\x01';
    }
    else {
      if (DAT_ffffbcef != '\x03') {
        if (DAT_ffffbcef == '\x04') {
          DAT_ffffbcf0 = '\x03';
          DAT_ffffbcf1 = '\x03';
        }
        else if (DAT_ffffbcef == '\0') {
          DAT_ffffbcf0 = '\0';
          DAT_ffffbcf1 = '\0';
        }
        goto LAB_0002d65e;
      }
      DAT_ffffbcf0 = '\x03';
    }
    DAT_ffffbcf1 = '\x01';
  }
LAB_0002d65e:
  FUN_0002d6fc((int)DAT_ffffbcf0);
LAB_0002d668:
  if (param_1 == '\f') {
    FUN_0002d6fc((int)DAT_ffffbcf1);
  }
  FUN_0000e2d4(1);
  return;
}


