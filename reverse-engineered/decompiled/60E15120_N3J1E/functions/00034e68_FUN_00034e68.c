/* ROM address: 0x00034e68; body bytes: 178; decompiled */

uint FUN_00034e68(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 1) {
    uVar1 = (uint)DAT_ffffc221;
    if (uVar1 == 1) {
      ref_ImmoBadStateSet_();
      DAT_ffffc224 = 0;
      uVar1 = FUN_00035738(1);
      DAT_ffffc22a = 1;
    }
    else if (uVar1 == 3) {
      DAT_ffffc21d = 0;
    }
    else if (uVar1 == 2) {
      if ((DAT_ffffc282 == 0) || (2 < DAT_ffffc282)) {
        ref_setImmoLight__(0);
        DAT_ffffc1d0 = 0;
      }
      else {
        DAT_ffffc282 = DAT_ffffc282 - 1;
        DAT_ffffc22f = 1;
        ref_setImmoLight__(1);
        DAT_ffffc1d0 = 1;
        DAT_ffffc228 = 0;
      }
      DAT_ffffc216 = 0x2ee;
      ref_ImmoGetSeed();
      uVar1 = FUN_00035738(7);
      DAT_ffffc21d = 2;
    }
  }
  else {
    if (uVar1 == 3) {
      uVar1 = FUN_00034d12();
      return uVar1;
    }
    DAT_ffffc21e = 5;
  }
  return uVar1;
}


