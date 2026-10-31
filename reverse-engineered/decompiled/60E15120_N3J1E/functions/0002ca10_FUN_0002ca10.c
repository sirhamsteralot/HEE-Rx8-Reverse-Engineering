/* ROM address: 0x0002ca10; body bytes: 126; decompiled */

void FUN_0002ca10(char param_1)

{
  if (param_1 != '\0') goto LAB_0002ca74;
  if (DAT_ffffbc83 == '\x01') {
    DAT_ffffbc84 = '\x01';
    DAT_ffffbc85 = '\0';
  }
  else {
    if (DAT_ffffbc83 == '\x02') {
      DAT_ffffbc84 = '\x01';
    }
    else {
      if (DAT_ffffbc83 != '\x03') {
        if (DAT_ffffbc83 == '\x04') {
          DAT_ffffbc84 = '\x03';
          DAT_ffffbc85 = '\x03';
        }
        else if (DAT_ffffbc83 == '\0') {
          DAT_ffffbc84 = '\0';
          DAT_ffffbc85 = '\0';
        }
        goto LAB_0002ca6a;
      }
      DAT_ffffbc84 = '\x03';
    }
    DAT_ffffbc85 = '\x01';
  }
LAB_0002ca6a:
  FUN_0002cb08((int)DAT_ffffbc84);
LAB_0002ca74:
  if (param_1 == '\f') {
    FUN_0002cb08((int)DAT_ffffbc85);
  }
  FUN_0000e2d4(1);
  return;
}


