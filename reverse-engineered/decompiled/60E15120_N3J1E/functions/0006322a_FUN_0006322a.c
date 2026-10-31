/* ROM address: 0x0006322a; body bytes: 82; decompiled */

int FUN_0006322a(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87b0)[uVar1 * 8] != param_1 || (DAT_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0xffff;
    }
  }
  return (int)(short)(&DAT_ffff87b4)[uVar1 * 8];
}


