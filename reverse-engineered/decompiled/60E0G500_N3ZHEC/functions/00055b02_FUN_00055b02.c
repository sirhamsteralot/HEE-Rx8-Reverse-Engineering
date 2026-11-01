/* ROM address: 0x00055b02; body bytes: 80; decompiled */

undefined4 FUN_00055b02(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffae97 == '\x01') {
    if (DAT_ffffad9c == '\0') {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 2;
    }
  }
  else if (DAT_ffffae96 == '\0') {
    uVar1 = 4;
  }
  else if (35.0 <= DAT_ffffaa10) {
    uVar1 = 8;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


