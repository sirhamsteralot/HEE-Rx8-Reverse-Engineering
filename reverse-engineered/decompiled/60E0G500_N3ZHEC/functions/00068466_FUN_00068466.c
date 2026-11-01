/* ROM address: 0x00068466; body bytes: 34; decompiled */

void FUN_00068466(undefined2 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8fdc;
  (&DAT_ffff8fc8)[uVar1 * 5] = param_1;
  (&DAT_ffff8fcc)[uVar1 * 5] = 0;
  (&DAT_ffff8fca)[uVar1 * 5] = 0;
  (&DAT_ffff8fce)[uVar1 * 5] = 0;
  (&DAT_ffff8fd0)[uVar1 * 10] = 0xa7;
  return;
}


