/* ROM address: 0x0003bf7c; body bytes: 208; decompiled */

undefined * FUN_0003bf7c(void)

{
  undefined *puVar1;
  
  DAT_ffffc5f4 = 0xfa < DAT_ffffc5ec;
  DAT_ffffc5f5 = 0xfa < DAT_ffffc5ed;
  DAT_ffffc5f6 = 0xfa < DAT_ffffc5ee;
  if (((0xfa < DAT_ffffc5ed) || (DAT_ffffc5f4)) || (DAT_ffffd201 == '\x01')) {
    DAT_ffffc5f8 = 0;
  }
  else if ((0xfa < DAT_ffffc5ef) || (DAT_ffffc5f7 == 1)) {
    DAT_ffffc5f8 = 1;
  }
  if (((0xfa < DAT_ffffc5ee) || (DAT_ffffc5f4)) || (DAT_ffffd201 == '\x01')) {
    puVar1 = &UNK_00000001;
    DAT_ffffc5f9 = 0;
  }
  else {
    puVar1 = &DAT_0007a9a9;
    if ((0xfa < DAT_ffffc5f0) || (puVar1 = (undefined *)(uint)DAT_ffffc5f7, puVar1 == &UNK_00000001)
       ) {
      DAT_ffffc5f9 = 1;
    }
  }
  return puVar1;
}


