/* ROM address: 0x00059b3c; body bytes: 46; decompiled */

char FUN_00059b3c(char param_1)

{
  short sVar1;
  
  if (param_1 == '\x02') {
    sVar1 = -0x2d6d;
  }
  else {
    if (param_1 != -0x7e) {
      if (param_1 != '\x0f') {
        return param_1;
      }
      DAT_ffffd295 = 1;
      return '\x0f';
    }
    sVar1 = -0x2d6c;
  }
  *(undefined1 *)(int)sVar1 = 1;
  return param_1;
}


