/* ROM address: 0x00034d12; body bytes: 282; decompiled */

uint FUN_00034d12(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 3) {
    if (DAT_ffffc274 == '\x01') {
      DAT_ffffc220 = 0xff;
      uVar1 = FUN_00035738(9);
      DAT_ffffc21d = 0;
    }
    else {
      ref_immo_related__();
      DAT_ffffc220 = 1;
      uVar1 = FUN_00035738(9);
      DAT_ffffc20e = 500;
    }
  }
  else if (uVar1 == 4) {
    uVar1 = (uint)DAT_ffffc220;
    if (uVar1 == 1) {
      if (DAT_ffffc1ec == DAT_ffffc1f0) {
        DAT_ffffc220 = 2;
      }
      uVar1 = FUN_00035738(9);
      return uVar1;
    }
    if (uVar1 == 2) {
      if (DAT_ffffc1ec == DAT_ffffc1f4) {
        DAT_ffffc220 = 3;
      }
      uVar1 = FUN_00035738(9);
      return uVar1;
    }
    if (uVar1 == 3) {
      if (DAT_ffffc1ec == DAT_ffffc1f8) {
        DAT_ffffc220 = 4;
      }
      uVar1 = FUN_00035738(9);
      return uVar1;
    }
    if (uVar1 == 4) {
      if (DAT_ffffc1ec != DAT_ffffc1fc) {
        uVar1 = FUN_00035738(9);
        return uVar1;
      }
      DAT_ffffc20c = 500;
      uVar1 = FUN_00035738(0xc6);
      DAT_ffffc21d = 0;
    }
  }
  else {
    DAT_ffffc21e = 5;
    if (DAT_ffffc20e != 0) {
      DAT_ffffc20e = DAT_ffffc20e + -1;
    }
    if (DAT_ffffc20e == 0) {
      ref_ImmoBadStateSet_();
      DAT_ffffc224 = 0;
      uVar1 = FUN_00035738(1);
      DAT_ffffc22a = 1;
    }
  }
  return uVar1;
}


