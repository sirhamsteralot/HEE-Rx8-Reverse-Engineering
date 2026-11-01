/* ROM address: 0x000584f4; body bytes: 58; decompiled */

undefined4 FUN_000584f4(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 == '\x01') {
    if (DAT_ffffd208 == '\x01') {
      uVar1 = 0;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_ffffd209 == '\x01') {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


