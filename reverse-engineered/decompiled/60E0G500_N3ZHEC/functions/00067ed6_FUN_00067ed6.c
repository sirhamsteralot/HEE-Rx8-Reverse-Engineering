/* ROM address: 0x00067ed6; body bytes: 46; decompiled */

void FUN_00067ed6(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8fc0;
  (&DAT_ffff8eb5)[uVar1 * 0x28] = 1;
  (&DAT_ffff8ea8)[uVar1 * 10] = *param_1;
  (&DAT_ffff8eac)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8eb0)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8eb4)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}


