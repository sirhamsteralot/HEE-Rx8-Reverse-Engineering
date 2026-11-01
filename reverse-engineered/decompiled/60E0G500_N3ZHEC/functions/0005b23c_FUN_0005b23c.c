/* ROM address: 0x0005b23c; body bytes: 144; decompiled */

uint FUN_0005b23c(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (DAT_ffffd314 == '\x01') {
    param_1 = 0;
    uVar1 = 0;
  }
  else {
    if ((((DAT_ffffd2dc == '\0') && (DAT_ffffd2da == '\0')) && (DAT_ffffd2db == '\x01')) &&
       ((0x124f < DAT_ffffd2d0 && (0x927 < DAT_ffffd2d4)))) {
      param_1 = param_1 + 1;
      DAT_ffffd2dc = '\x01';
    }
    if (0xffff < param_1) {
      param_1 = 0;
    }
    if ((DAT_ffffd316 == '\0') && (DAT_ffffd315 == '\x01')) {
      uVar1 = uVar1 + 1;
    }
    if (0xffff < uVar1) {
      uVar1 = 0;
    }
  }
  return param_1 << 0x10 | uVar1 & 0xffff;
}


