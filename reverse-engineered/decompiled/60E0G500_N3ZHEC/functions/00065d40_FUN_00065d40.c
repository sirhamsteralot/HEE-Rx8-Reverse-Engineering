/* ROM address: 0x00065d40; body bytes: 44; decompiled */

uint FUN_00065d40(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  if ((uVar1 == 0) || (0x3f < uVar1)) {
    if ((0x80 < uVar1) && (uVar1 < 0xc0)) {
      param_1 = 0x70;
    }
  }
  else {
    param_1 = 0x60;
  }
  return param_1;
}


