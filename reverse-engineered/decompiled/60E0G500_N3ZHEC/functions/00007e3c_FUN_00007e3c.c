/* ROM address: 0x00007e3c; body bytes: 88; decompiled */

int FUN_00007e3c(char param_1)

{
  int iVar1;
  
  iVar1 = 0xff;
  if (param_1 == '\0') {
    if (DAT_ffff9fc7 != '\0') {
      if (DAT_ffff9fc7 == '\0') {
        iVar1 = 1;
      }
      goto LAB_00007e9e;
    }
  }
  else {
    if (param_1 != '\x06') goto LAB_00007e9e;
    if (DAT_ffff9fc7 != '\0') {
      if (DAT_ffff9fc7 == '\0') {
        iVar1 = 1;
      }
      goto LAB_00007e9e;
    }
  }
  iVar1 = 0;
LAB_00007e9e:
  DAT_ffff9fcb = iVar1 == 0xff;
  return iVar1;
}


