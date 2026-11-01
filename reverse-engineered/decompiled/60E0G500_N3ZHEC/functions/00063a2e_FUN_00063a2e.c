/* ROM address: 0x00063a2e; body bytes: 268; decompiled */

undefined4 FUN_00063a2e(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    DAT_ffffd7da = 0;
    DAT_ffffd7dc = DAT_ffff8928;
  }
  else if (param_1 == '\x01') {
    DAT_ffffd7da = DAT_ffffd7da + 1;
  }
  if ((DAT_ffffd7da == DAT_ffff8928) || (DAT_ffffd7da == DAT_ffffd7dc)) {
    DAT_ffffd7da = DAT_ffffd7da + 1;
  }
  if (DAT_ffffd7da < 0x15) {
    if ((&DAT_ffff87d8)[(uint)DAT_ffffd7da * 8] == -1) {
      uVar1 = 0;
    }
    else {
      DAT_ffffd7cc = (&DAT_ffff87d8)[(uint)DAT_ffffd7da * 8];
      DAT_ffffd7ce = (&DAT_ffff87da)[(uint)DAT_ffffd7da * 8];
      DAT_ffffd7d0 = (&DAT_ffff87dc)[(uint)DAT_ffffd7da * 8];
      DAT_ffffd7d2 = (&DAT_ffff87de)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d3 = (&DAT_ffff87df)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d4 = (&DAT_ffff87e1)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d5 = (&DAT_ffff87e0)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d6 = (&DAT_ffff87e2)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d7 = (&DAT_ffff87e3)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d8 = (&DAT_ffff87e4)[(uint)DAT_ffffd7da * 0x10];
      DAT_ffffd7d9 = (&DAT_ffff87e5)[(uint)DAT_ffffd7da * 0x10];
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


