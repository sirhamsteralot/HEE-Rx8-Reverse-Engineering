/* ROM address: 0x000639ce; body bytes: 82; decompiled */

undefined * FUN_000639ce(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87d8)[uVar1 * 8] != param_1 || (DAT_ffff8928 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return (undefined *)0xffff;
    }
  }
  return (undefined *)(int)(short)(&DAT_ffff87dc)[uVar1 * 8];
}


