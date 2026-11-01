/* ROM address: 0x000683be; body bytes: 74; decompiled */

int FUN_000683be(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8fc8)[uVar1 * 5] != param_1 || (DAT_ffff8fdc == uVar1))) {
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8fcc)[uVar1 * 5];
}


