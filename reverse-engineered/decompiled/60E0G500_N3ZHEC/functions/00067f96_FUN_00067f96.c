/* ROM address: 0x00067f96; body bytes: 52; decompiled */

void FUN_00067f96(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8fc0;
  (&DAT_ffff8eb8)[uVar1 * 10] = *param_1;
  (&DAT_ffff8ebc)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8ec0)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8ec4)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}


