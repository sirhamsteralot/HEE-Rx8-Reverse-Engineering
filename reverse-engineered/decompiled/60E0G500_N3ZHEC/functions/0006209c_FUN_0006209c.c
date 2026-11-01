/* ROM address: 0x0006209c; body bytes: 194; decompiled */

undefined4 FUN_0006209c(uint param_1,byte param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  param_1 = param_1 & 0xffff;
  cVar1 = (&DAT_0007ded2)[param_1];
  if (cVar1 == '\0') {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        if ((&DAT_0007e2ac)[param_1] == '\0') {
          uVar2 = 5;
        }
        else if ((&DAT_0007e2ac)[param_1] == '\x01') {
          if ((&DAT_0007e220)[param_1] == '\0') {
            uVar2 = 4;
          }
          else if ((&DAT_0007e220)[param_1] == '\x01') {
            uVar2 = 3;
          }
        }
      }
    }
    else {
      uVar2 = 6;
    }
  }
  else if (((cVar1 == '\x03') || (cVar1 == '\x01')) || (cVar1 == '\x02')) {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  return uVar2;
}


