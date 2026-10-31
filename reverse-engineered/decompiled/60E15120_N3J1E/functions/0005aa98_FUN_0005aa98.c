/* ROM address: 0x0005aa98; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059250 (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005aa98(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (DAT_ffffd2d8 == '\x01') {
    param_1 = 0;
    uVar1 = 0;
  }
  else {
    if ((((DAT_ffffd2a0 == '\0') && (DAT_ffffd29e == '\0')) && (DAT_ffffd29f == '\x01')) &&
       ((0x124f < DAT_ffffd294 && (0x927 < DAT_ffffd298)))) {
      param_1 = param_1 + 1;
      DAT_ffffd2a0 = '\x01';
    }
    if (0xffff < param_1) {
      param_1 = 0;
    }
    if ((DAT_ffffd2da == '\0') && (DAT_ffffd2d9 == '\x01')) {
      uVar1 = uVar1 + 1;
    }
    if (0xffff < uVar1) {
      uVar1 = 0;
    }
  }
  return param_1 << 0x10 | uVar1 & 0xffff;
}


