/* ROM address: 0x00067e18; body bytes: 84; decompiled */

int FUN_00067e18(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ec8)[uVar1 * 0x14] != param_1 || (DAT_ffff8fc0 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8eca)[uVar1 * 0x14];
}


