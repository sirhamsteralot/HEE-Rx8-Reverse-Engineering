/* ROM address: 0x0006385c; body bytes: 82; decompiled */

int FUN_0006385c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87d8)[uVar1 * 8] != param_1 || (DAT_ffff8928 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87e4)[uVar1 * 0x10];
}


