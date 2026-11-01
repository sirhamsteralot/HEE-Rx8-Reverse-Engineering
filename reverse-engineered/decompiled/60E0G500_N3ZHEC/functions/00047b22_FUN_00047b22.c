/* ROM address: 0x00047b22; body bytes: 258; decompiled */

void FUN_00047b22(char param_1)

{
  char cVar1;
  char *pcVar2;
  
  if (((DAT_ffffccdf == '\0') || (DAT_ffffccb1 == '\x01')) || (DAT_ffffccd1 < 3)) {
    DAT_ffffccb0 = '\0';
  }
  else {
    if (((DAT_ffffccde == '\x01') && (DAT_ffffbd44 == '\x01')) ||
       ((DAT_ffffccde == '\x01' && (cVar1 = FUN_0003eaa4(&DAT_ffff8760,0), cVar1 == '\x01')))) {
      pcVar2 = "";
    }
    else {
      if (DAT_ffffad90 != '\x01') {
        DAT_ffffccb0 = '\0';
        goto LAB_00047bae;
      }
      pcVar2 = "";
    }
    DAT_ffffccb0 = *pcVar2;
  }
LAB_00047bae:
  if (param_1 != '\0') {
    if (param_1 == '\f') {
      FUN_00047c5a((int)DAT_ffffccb5);
    }
    goto LAB_00047c48;
  }
  if (DAT_ffffccb0 == '\x01') {
    DAT_ffffccb4 = '\x01';
    DAT_ffffccb5 = '\0';
  }
  else {
    if (DAT_ffffccb0 == '\x02') {
      DAT_ffffccb4 = '\x01';
    }
    else {
      if (DAT_ffffccb0 != '\x03') {
        if (DAT_ffffccb0 == '\x04') {
          DAT_ffffccb4 = '\x03';
          DAT_ffffccb5 = '\x03';
        }
        else if (DAT_ffffccb0 == '\0') {
          DAT_ffffccb4 = '\0';
          DAT_ffffccb5 = '\0';
        }
        goto LAB_00047c34;
      }
      DAT_ffffccb4 = '\x03';
    }
    DAT_ffffccb5 = '\x01';
  }
LAB_00047c34:
  FUN_00047c5a((int)DAT_ffffccb4);
LAB_00047c48:
  FUN_0000e2d4(1);
  return;
}


