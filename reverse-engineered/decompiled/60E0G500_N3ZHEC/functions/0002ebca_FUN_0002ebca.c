/* ROM address: 0x0002ebca; body bytes: 78; decompiled */

uint FUN_0002ebca(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00002440(DAT_ffffc00c,DAT_ffffc010,0x3727c5ac);
  if (DAT_ffffbd59 == '\0') {
    if ((uVar1 & 0xff) == 0) {
      DAT_ffffbd6a = 0;
      return uVar1;
    }
  }
  else {
    if (DAT_ffffbdaa != 1) {
      return (uint)DAT_ffffbdaa;
    }
    uVar2 = uVar1 & 0xff;
    uVar1 = 1;
    if (uVar2 == 0) {
      DAT_ffffbd6a = 0;
      return 1;
    }
  }
  DAT_ffffbd6a = 1;
  return uVar1;
}


