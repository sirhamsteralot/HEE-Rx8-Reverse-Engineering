/* ROM address: 0x00059398; body bytes: 46; decompiled */

char FUN_00059398(char param_1)

{
  short sVar1;
  
  if (param_1 == '\x02') {
    sVar1 = -0x2da9;
  }
  else {
    if (param_1 != -0x7e) {
      if (param_1 != '\x0f') {
        return param_1;
      }
      DAT_ffffd259 = 1;
      return '\x0f';
    }
    sVar1 = -0x2da8;
  }
  *(undefined1 *)(int)sVar1 = 1;
  return param_1;
}


