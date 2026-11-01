/* ROM address: 0x00032b16; body bytes: 230; decompiled */

undefined2 * FUN_00032b16(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffb5b8 <= 3000.0) {
    if (DAT_ffffb5b8 <= 2800.0) {
      DAT_ffffc000 = '\0';
    }
  }
  else {
    DAT_ffffc000 = '\x01';
  }
  if (((DAT_ffffc000 == '\0') && (puVar1 = &DAT_00078cb2, 0x752 < DAT_ffffbff0)) ||
     ((DAT_ffffaae0 == '\0' &&
      ((DAT_ffffbff5 == '\0' && (puVar1 = &DAT_ffffbff0, 0x58 < DAT_ffffbff0)))))) {
    DAT_ffffbfec = 0;
  }
  else if (DAT_ffffbff3 == '\x01') {
    puVar1 = &DAT_00078cac;
    if (DAT_ffffbff0 < 0x32) {
      DAT_ffffbfec = 0x42c80000;
    }
    else if (DAT_ffffbff0 < 0x59) {
      DAT_ffffbfec = 0x41480000;
    }
    else {
      DAT_ffffbfec = 0x41480000;
    }
  }
  else {
    puVar1 = (undefined2 *)&DAT_00078ca4;
    if (DAT_ffffbff2 < 0x32) {
      DAT_ffffbfec = 0x42c80000;
    }
    else if (DAT_ffffbff2 < 0x59) {
      DAT_ffffbfec = 0x41480000;
    }
    else {
      DAT_ffffbfec = 0x41480000;
    }
  }
  return puVar1;
}


