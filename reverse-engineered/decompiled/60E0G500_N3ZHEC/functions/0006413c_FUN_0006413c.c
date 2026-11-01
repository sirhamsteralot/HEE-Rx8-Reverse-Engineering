/* ROM address: 0x0006413c; body bytes: 68; decompiled */

int FUN_0006413c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8930)[uVar1 * 0x1a] != param_1 || (DAT_ffff8d74 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff8936)[uVar1 * 0x34];
}


