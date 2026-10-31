/* ROM address: 0x00035738; body bytes: 220; decompiled */

void FUN_00035738(char param_1)

{
  undefined4 *puVar1;
  
  DAT_ffffc1c8 = param_1;
  if (param_1 == '\t') {
    if (DAT_ffffc220 == '\x01') {
      DAT_ffffc1c9 = DAT_ffffc220;
      puVar1 = &DAT_ffffc1dc;
    }
    else if (DAT_ffffc220 == '\x02') {
      DAT_ffffc1c9 = DAT_ffffc220;
      puVar1 = &DAT_ffffc1e0;
    }
    else if (DAT_ffffc220 == '\x03') {
      DAT_ffffc1c9 = DAT_ffffc220;
      puVar1 = &DAT_ffffc1e4;
    }
    else {
      if (DAT_ffffc220 != '\x04') {
        if (DAT_ffffc220 != -1) {
          DAT_ffffc1cd = 0;
          DAT_ffffc1ce = 0;
          DAT_ffffc1cf = 0;
          DAT_ffffc1d1 = 1;
          DAT_ffffc21f = 0;
          DAT_ffffc226 = 0;
          DAT_ffffc229 = 1;
          return;
        }
        DAT_ffffc1c9 = DAT_ffffc220;
        DAT_ffffc1ca = 0;
        DAT_ffffc1cb = 0;
        DAT_ffffc1cc = 0;
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        DAT_ffffc1d1 = 1;
        DAT_ffffc21f = 0;
        DAT_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      DAT_ffffc1c9 = DAT_ffffc220;
      puVar1 = &DAT_ffffc1e8;
    }
  }
  else {
    if (param_1 != '\a') {
      if ((param_1 == '\x01') || (param_1 == -0x7f)) {
        DAT_ffffc1c9 = DAT_ffffc224;
        DAT_ffffc1ca = 0;
        DAT_ffffc1cb = 0;
        DAT_ffffc1cc = 0;
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        DAT_ffffc1d1 = 1;
        DAT_ffffc21f = 0;
        DAT_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      if ((param_1 != -0x3a) && (param_1 != -0x38)) {
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        DAT_ffffc1d1 = 1;
        DAT_ffffc21f = 0;
        DAT_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      DAT_ffffc1c9 = 0;
      DAT_ffffc1ca = 0;
      DAT_ffffc1cb = 0;
      DAT_ffffc1cc = 0;
      DAT_ffffc1cd = 0;
      DAT_ffffc1ce = 0;
      DAT_ffffc1cf = 0;
      DAT_ffffc1d1 = 1;
      DAT_ffffc21f = 0;
      DAT_ffffc226 = 0;
      DAT_ffffc229 = 1;
      return;
    }
    puVar1 = &DAT_ffffc208;
    DAT_ffffc1c9 = (char)((uint)DAT_ffffc208 >> 0x18);
  }
  DAT_ffffc1cc = *(undefined1 *)((int)puVar1 + 3);
  DAT_ffffc1cb = (char)((uint)*puVar1 >> 8);
  DAT_ffffc1ca = (char)((uint)*puVar1 >> 0x10);
  DAT_ffffc1cd = 0;
  DAT_ffffc1ce = 0;
  DAT_ffffc1cf = 0;
  DAT_ffffc1d1 = 1;
  DAT_ffffc226 = 0;
  DAT_ffffc21f = 0;
  DAT_ffffc229 = 1;
  return;
}


