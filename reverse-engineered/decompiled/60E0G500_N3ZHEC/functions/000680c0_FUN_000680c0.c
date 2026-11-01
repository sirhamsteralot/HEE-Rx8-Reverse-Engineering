/* ROM address: 0x000680c0; body bytes: 100; decompiled */

void FUN_000680c0(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_ffff8fc0;
  iVar2 = uVar1 * 0x28;
  (&DAT_ffff8ec8)[uVar1 * 0x14] = 0xffff;
  (&DAT_ffff8eca)[uVar1 * 0x14] = 0;
  (&DAT_ffff8ea8)[uVar1 * 10] = 0;
  (&DAT_ffff8eac)[uVar1 * 10] = 0;
  (&DAT_ffff8eb0)[uVar1 * 10] = 0;
  (&DAT_ffff8eb4)[iVar2] = 0;
  (&DAT_ffff8eb5)[iVar2] = 0;
  (&DAT_ffff8eb6)[iVar2] = 0;
  (&DAT_ffff8eb7)[iVar2] = 0;
  (&DAT_ffff8ecc)[uVar1 * 0x14] = 0;
  (&DAT_ffff8eb8)[uVar1 * 10] = 0;
  (&DAT_ffff8ebc)[uVar1 * 10] = 0;
  (&DAT_ffff8ec0)[uVar1 * 10] = 0;
  (&DAT_ffff8ec4)[iVar2] = 0;
  (&DAT_ffff8ec5)[iVar2] = 0;
  (&DAT_ffff8ec6)[iVar2] = 0;
  (&DAT_ffff8ec7)[iVar2] = 0;
  (&DAT_ffff8ece)[iVar2] = 0;
  (&DAT_ffff8ecf)[iVar2] = 0xa7;
  FUN_00067dca();
  return;
}


