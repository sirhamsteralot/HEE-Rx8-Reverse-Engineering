/* ROM address: 0x00067f1c; body bytes: 122; decompiled */

undefined4 FUN_00067f1c(short param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((((&DAT_ffff8ec8)[uVar1 * 0x14] != param_1 || (DAT_ffff8fc0 == uVar1)) ||
         ((&DAT_ffff8eb5)[uVar1 * 0x28] != '\x01'))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 1;
    }
  }
  *param_2 = (&DAT_ffff8ea8)[uVar1 * 10];
  param_2[1] = (&DAT_ffff8eac)[uVar1 * 10];
  param_2[2] = (&DAT_ffff8eb0)[uVar1 * 10];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8eb4)[uVar1 * 0x28];
  return 0;
}


