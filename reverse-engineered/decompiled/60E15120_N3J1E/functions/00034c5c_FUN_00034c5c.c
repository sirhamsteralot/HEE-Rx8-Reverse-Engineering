/* ROM address: 0x00034c5c; body bytes: 114; decompiled */

uint FUN_00034c5c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 3) {
    DAT_ffffc21d = 1;
    uVar1 = FUN_00034d12();
    return uVar1;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00034e68();
    return uVar1;
  }
  if (1 < DAT_ffffc21f) {
    DAT_ffffc21f = 0;
    uVar1 = FUN_00035738(0xc6);
  }
  if (DAT_ffffc20c != 0) {
    DAT_ffffc20c = DAT_ffffc20c + -1;
  }
  if (DAT_ffffc20c == 0) {
    ref_ImmoBadStateSet_();
    DAT_ffffc224 = 0;
    uVar1 = FUN_00035738(1);
    DAT_ffffc22a = 1;
  }
  return uVar1;
}


